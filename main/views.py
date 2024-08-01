from django.shortcuts import render
from rest_framework.views import APIView
from rest_framework.generics import ListAPIView
import json
from .models import Team,Question,Duel
from django.http import HttpRequest
from django.http import JsonResponse
from rest_framework import status
from .import helper
from .helper import *
from .serializers import TeamSerializer,BASerializer,GameSerializer
from .models import *
from django.db.models import Q
from threading import Timer
from random import choice



# Create your views here.
class AllTeam(ListAPIView):
    serializer_class=TeamSerializer
    queryset=Team.objects.all().order_by("-score")
    
class GetTeam(APIView):
    def get(self,request,id):
        ser=TeamSerializer(Team.objects.get(id=id))
        return JsonResponse(ser.data)
class SolveQuestion(APIView):
    def post(self,request:HttpRequest):
        data=json.loads(request.body)
        team=Team.objects.get(id=data["team_id"])
        question=Question.objects.get(number=data["question_id"])
        if(QuestionStat.objects.filter(question=question).filter(team=team).filter(solved=False).count()==0):
            return JsonResponse({"error":"hasnt bought or already solved"},status=status.HTTP_400_BAD_REQUEST)
        


        team.A=team.A+question.score
        team.save()
        qs=QuestionStat.objects.filter(team=team,question=question)[0]
        
        qs.solved=True
        qs.save()
        
        
        return JsonResponse({"message":"solved"})


class BuyQuestions(APIView):
    def post(self,request:HttpRequest):
        data=json.loads(request.body)
        team=Team.objects.get(id=data["team_id"])
        question=Question.objects.get(number=data["question_id"])
        if(QuestionStat.objects.filter(question=question).filter(team=team).count()!=0):
            return JsonResponse({"error":"already bough"},status=status.HTTP_400_BAD_REQUEST)
        if(team.A<question.value and not get_leverage_two()):
            return JsonResponse({"error":"not enought money"},status=status.HTTP_400_BAD_REQUEST)
        
        
        
        team.A=team.A-question.value
        

        team.save()
        QuestionStat.objects.create(team=team,question=question)
        set_team_score(team)
        return JsonResponse({"message":"bought"})
    

class BuyRandom(APIView):
    def post(self,request):
        data=json.loads(request.body)
        team=Team.objects.get(id=data["team_id"])
        if(team.A<50):
            return JsonResponse({"error":"not enough money"},status=status.HTTP_400_BAD_REQUEST)
        cand=set()
        for q in Question.objects.all():
            if(QuestionStat.objects.filter(Q(team=team) & Q(question__number=q.number)).count()==0):
                cand.add(q.number)

        
        if len(cand)==0:
            return JsonResponse({"error":"no question left"},status=status.HTTP_400_BAD_REQUEST)


        question=Question.objects.get(number=choice(list(cand)))
        team.A=team.A-50
        team.save()
        QuestionStat.objects.create(team=team,question=question)
        set_team_score(team)
        return JsonResponse({"message":f"bought question {question.number}"})

class ExchangeA(APIView):
    def post(self,request:HttpRequest):
    
        data=json.loads(request.body)
        team=Team.objects.get(id=data["team_id"])
        amount=data["amount"]
        if(amount>team.A):
            return JsonResponse({"error":"not enough currency"},status=status.HTTP_400_BAD_REQUEST)
        team.A=team.A-amount
        set_demand(get_demand()+change_to_b(amount))

        team.B=team.B+change_to_b(amount)
        team.save()
        exchanged=change_to_b(amount)
        set_transactions(get_transactions()+change_to_b(amount))
        if(get_transactions()>ALL_TRANSACTIONS):
            set_transactions(0)
            calcuate_b_a()

        return JsonResponse({"message":f"exchanged {exchanged} B"})
class ExchangeB(APIView):
    def post(self,request:HttpRequest):
        data=json.loads(request.body)
        team=Team.objects.get(id=data["team_id"])
        amount=data["amount"]
        if(amount>team.B):
            return JsonResponse({"error":"not enough currency"},status=status.HTTP_400_BAD_REQUEST)
        team.B=team.B-amount
        team.A=team.A+change_to_a(amount)
        set_supply(get_supply()+amount)
        team.save()
        exchanged=change_to_a(amount)

        set_transactions(get_transactions()+amount)
        if(get_transactions()>ALL_TRANSACTIONS):
            set_transactions(0)
            calcuate_b_a()
        return JsonResponse({"message":f"exchanged +{exchanged} A"})

class ScoreBoard(APIView):
    def get(self):
        result=dict()
        result.users=TeamSerializer(Team.objects.all(),many=True).data
        result.rate=get_b_a_value()
        return JsonResponse(data=result)
    
class Attack(APIView):
    def post(self,request):
        data=json.loads(request.body)
        attacker=Team.objects.get(id=data["attacker_id"])
        defender=Team.objects.get(id=data["defender_id"])
        fee=get_duel_fee(attacker,defender)
        if(attacker.stat!=0):
            return JsonResponse({"error":"cant start a battle"},status=status.HTTP_400_BAD_REQUEST)
        if(attacker.B<fee):
            return JsonResponse({"error":"not enought money"},status=status.HTTP_400_BAD_REQUEST)
        Duel.objects.create(attacker=attacker,defender=defender,winner=None)
        attacker.B=attacker.B-fee
        defender.stat=2
        attacker.stat=1
        defender.save()
        attacker.save()
        set_team_score(attacker)

        return JsonResponse({"message":"battle started"})
     
class EndDuel(APIView):
    def post(self,request):
        data=json.loads(request.body)
        if("attacker_id" in data):

            attacker=Team.objects.get(id=data["attacker_id"])
            duel=Duel.objects.get(attacker=attacker,winner=None)
            defender=duel.defender
        else:

            defender=Team.objects.get(id=data["defender_id"])
            duel=Duel.objects.get(defender=defender,winner=None)
            attacker=duel.attacker

        winner=Team.objects.get(id=data["winner_id"])
        duel.winner=winner
        
        
        
        if(attacker==winner):
            looser=defender
        else:
            looser=attacker
        
        loose_fee=get_duel_loose_fee(looser,winner)
        win_fee=get_duel_win_fee(looser,winner)
        looser_B=looser.B
        b_minus=min(loose_fee,looser_B)
        looser.B-=min(loose_fee,looser_B)
        a_minus=max(looser_B-loose_fee,0)
        looser.A-=change_to_a(max(looser_B-loose_fee,0))

        looser.A=max(looser.A,0)
        coef=1
        if(get_leverage_three()):
            coef=settings.LEVERAGE_TREE_COEF

        winner.B+=coef*win_fee
        set_team_score(looser)
        set_team_score(winner)
        
        looser.stat=4
        winner.stat=4
        duel.save()
        winner.save()
        looser.save()
        
        def change_stat_later(attacker,defender):
            
            defender.stat=0
            attacker.stat=0
            defender.save()
            attacker.save()
            

        # Schedule the function to run 5 minutes later
        t = Timer(COOL_DOWN_TIME, change_stat_later, [attacker,defender])
        t.start()

        return JsonResponse({f"message":f"battle ended"})

class RejectDuel(APIView):
    def post(self,request):
        data=json.loads(request.body)
        defender=Team.objects.get(id=data["defender_id"])
        duel=Duel.objects.get(defender=defender,winner=None)

        attacker=duel.attacker
        fee=get_reject_fee(duel.attacker,duel.defender)
        if(defender.B<fee):
            return JsonResponse({"error":"not enought money to reject"},status=status.HTTP_400_BAD_REQUEST)
        defender.B=defender.B-get_reject_fee(duel.attacker,duel.defender)
        defender.stat=4
        attacker.stat=4
        set_team_score(defender)

        attacker.save()
        duel.save()
        defender.save()
        return JsonResponse({"message":"duel rejected"})
    


class AcceptDuel(APIView):
    def post(self,request):
        data=json.loads(request.body)
        defender=Team.objects.get(id=data["defender_id"])
        duel=Duel.objects.get(defender=defender,winner=None)
        attacker=duel.attacker
        attacker.stat=3
        defender.stat=3

        attacker.save()
        duel.save()
        defender.save()
        return JsonResponse({"message":"battle started"})
    

class GetQuestions(APIView):
    def get(self,request,team):
        result=list()

        for q in Question.objects.all().order_by("score"):  
            coef=1
            if(get_leverage_one()):
                coef=settings.LEVERAGE_ONE_COEF
            result.append({"number":q.number,"bought":True,"max-score":q.score,"price":q.value*coef})
            query=QuestionStat.objects.filter(team__id=team).filter(question__number=q.number)
            if(query.count()==0):
                result[-1]["bought"]=False
                result[-1]["score"]=0
            else:
                result[-1]["score"]=query[0].score
        return JsonResponse(result,safe=False)
class GetDuel(APIView):
    def get(self,request,team_id):
        team=Team.objects.get(id=team_id)
        if(team.stat==3):
            duel=Duel.objects.filter(Q(defender_id=team_id) | Q(attacker_id=team_id)).filter(winner=None)
            if(duel.count()!=0):
                return JsonResponse({"invitations":False,"active":True,"attacker":duel[0].attacker.name,"defender":duel[0].defender.name,"defender_id":duel[0].defender.id,"attacker_id":duel[0].attacker.id})
        elif(team.stat==2):
            duel=Duel.objects.filter(defender_id=team_id).filter(winner=None)
            return JsonResponse({"invitation":True,"active":False,"attacker":duel[0].attacker.name})

        return JsonResponse({"active":False,"invitation":False})

                

class Calculate(APIView):
    def post(self,request):
        calcuate_b_a()
        return JsonResponse({"message":"calculated"})
class GetValue(ListAPIView):
    serializer_class = BASerializer
    queryset=BA.objects.all().order_by("time")

class AllGames(ListAPIView):
    serializer_class=GameSerializer
    queryset=Game.objects.all()
    
class GetGame(APIView):
    def get(self,reques,team_id):
        team=Team.objects.get(id=team_id)
        query=GameTeam.objects.filter( Q(team=team) & Q(finished=False))
    
        if(query.count()==0):
            return JsonResponse({"active":False})
        
        
        else:
            return JsonResponse({"active":True,"name":query[0].game.name})

            


class StartGame(APIView):
    def post(self,request):
        data=json.loads(request.body)
        team=Team.objects.get(id=data.get("team_id"))
        game=Game.objects.get(name=data.get("game_name"))
        if(team.B<game.value):
            return JsonResponse({"error":"not enought money"},status=status.HTTP_400_BAD_REQUEST)
        if(GameTeam.objects.filter(Q(game=game) & Q(team=team) & Q(finished=False)).count()!=0):
            return JsonResponse({"error":"another game is in proccess"},status=status.HTTP_400_BAD_REQUEST)
        if(GameTeam.objects.filter(Q(game=game) & Q(team=team)).count()>=game.limit ):
            return JsonResponse({"error":"game has been played more than the limit"},status=status.HTTP_400_BAD_REQUEST)

        GameTeam.objects.create(game=game,team=team)
        team.B=team.B-game.value
        set_team_score(team)

        team.save()
        return JsonResponse({"message":"started"})


class EndGame(APIView):
    def post(self,request):
        data=json.loads(request.body)
        team=Team.objects.get(id=data.get("team_id"))
        gt=GameTeam.objects.get( Q(team=team) & Q(finished=False))
        game=gt.game    
        gt.finished=True
        added_score=0
        if(data["won"]):
            added_score=game.score
            if(not get_leverage_four()):
                team.B=team.B+game.score
             
            else:
                team.A=team.A+change_to_a(game.score)
                


            team.save()
            
            gt.won=True
        else:
            gt.won=False
        set_team_score(team)
        
        gt.save()
        return JsonResponse({"message":f"ended "})


class SetScore(APIView):
    def post(self,request):
        data=json.loads(request.body)
        team=Team.objects.get(id=data["team_id"])
        score=data.get("score")
        question=Question.objects.get(number=data["question_id"])
        if(QuestionStat.objects.filter(question=question).filter(team=team).count()==0):
            return JsonResponse({"error":"hasnt bought or already solved"},status=status.HTTP_400_BAD_REQUEST)
        
        qs=QuestionStat.objects.get(team=team,question=question)
        #ask this
        if(not get_leverage_two()):
            team.A=team.A+score-qs.score
        else:
            team.B=team.B+change_to_b(score)-change_to_b(qs.score)
        qs.score=score
        
        team.save()
        qs.save()
        return JsonResponse({"message":"changed"})
        


class SetA(APIView):
    def post(self,request):
        data=json.loads(request.body)
        team=Team.objects.get(id=data["team_id"])
        team.A=data.get("amount")
        set_team_score(team)

        team.save()
        return JsonResponse({"message":"changed"})
        
class SetB(APIView):
    def post(self,request):
        data=json.loads(request.body)
        team=Team.objects.get(id=data["team_id"])
        team.B=data.get("amount")
        set_team_score(team)

        team.save()
        return JsonResponse({"message":"changed"})


class GetLeverageStat(APIView):
    def get(self,request):
        return JsonResponse({"lev1":get_leverage_one(),"lev2":get_leverage_two(),"lev3":get_leverage_three(),"lev4":get_leverage_four()})
    

class ToggleLeverage1(APIView):
    def post(self,reques):
        set_leverage_one(not get_leverage_one())
        
        return JsonResponse({"message":"toggled"})

class ToggleLeverage2(APIView):
    def post(self,reques):
        set_leverage_two(not get_leverage_two())
        return JsonResponse({"message":"toggled"})
    

class ToggleLeverage3(APIView):
    def post(self,reques):
        set_leverage_three(not get_leverage_three())

        return JsonResponse({"message":"toggled"})
    

class ToggleLeverage4(APIView):
    def post(self,reques):
        set_leverage_four(not get_leverage_four())
        return JsonResponse({"message":"toggled"})
    