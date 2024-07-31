from .models import *
from game.settings import *
from math import ceil
def change_to_a(b):
    return b*b_a_value

def change_to_b(a):
    return a/b_a_value



def get_duel_fee(attakcer,defender):
    return 1

def get_reject_fee(attacker,defender):
    return 2


def get_duel_loose_fee(looser:Team,winner:Team):
    if(winner.score>looser.score):
        return (winner.score-looser.score)*0.4
    else:
        return (looser.score-winner.score)*0.025



def get_duel_win_fee(looser,winner):
    if(winner.score>looser.score):
        delta=(winner.score-looser.score)*0.4
    else:
        delta=(looser.score-winner.score)*0.025
    return 40+delta

def calcuate_b_a():
    global b_a_value,K,demand,supply
    b_a_value+=max(K*(demand-supply),1)
    demand=0
    supply=0
    for team in Team.objects.all():
        set_team_score(team)
    print("b/a value: ",b_a_value)
    BA.objects.create(value=b_a_value)

    
    
def set_team_score(team:Team):
    team.score=team.A*b_a_value+team.B
    team.save()
