from django.db import models
from game.settings import * 

class ALLInfo(models.Model):
    LEVERAGE_ONE=models.BooleanField(default=False)
    LEVERAGE_TWO=models.BooleanField(default=False)
    LEVERAGE_THREE=models.BooleanField(default=False)
    LEVERAGE_FOUR=models.BooleanField(default=False)
    demand=models.FloatField(default=0)
    supply=models.FloatField(default=0)
    B_A_VALUE=models.FloatField(default=10)
    TRANSACTIONS=models.IntegerField(default=0)

class Team(models.Model):

    name=models.CharField(max_length=30)
    A=models.FloatField(default=300)
    B=models.FloatField(default=20)
    score=models.FloatField()
    _stats=["free","pending","not responded","battle","cool down"]
    stat=models.IntegerField(default=0)
    def __str__(self):
        return self.name
    def save(self, *args, **kwargs):
        self.score=self.A+self.B*ALLInfo.objects.first().B_A_VALUE
        
        super().save(*args, **kwargs)



class Duel(models.Model):
    attacker=models.ForeignKey(Team,related_name="duels",on_delete=models.CASCADE)
    defender=models.ForeignKey(Team,on_delete=models.CASCADE,related_name="defenders")
    winner=models.ForeignKey(Team,blank=True,null=True,default=None,on_delete=models.CASCADE,related_name="winners")
    #None means has not yet been started and -1 means rejected


class Question(models.Model):
    number=models.IntegerField(primary_key=True)
    score=models.IntegerField()
    value=models.IntegerField()
    def __str__(self):
        return str(self.number)


class QuestionStat(models.Model):
    team=models.ForeignKey(Team,on_delete=models.CASCADE)
    question=models.ForeignKey(Question,on_delete=models.CASCADE)
    score=models.FloatField(default=0)
    



class BA(models.Model):
    value=models.FloatField()
    time=models.DateTimeField(auto_now_add=True)
    def __str__(self):
        return str(self.value)


class Game(models.Model):
    name=models.CharField(max_length=100 ,default="")
    score=models.FloatField()
    value=models.FloatField()
    limit=models.IntegerField(default=2)
    def __str__(self):
        return self.name

class GameTeam(models.Model):
    team=models.ForeignKey(Team,on_delete=models.CASCADE,default=None)
    game=models.ForeignKey(Game,on_delete=models.CASCADE,default=None)
    finished=models.BooleanField(default=False)
    won=models.BooleanField(default=False)
    def __str__(self):
        return self.team.name+" "+self.game.name
    

