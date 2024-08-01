from .models import *
from game.settings import *
from math import ceil
from game import settings

# Access the single instance of ALL
def get_all_instance():
    return ALLInfo.objects.first()

# Getters
def get_leverage_one():
    instance = get_all_instance()
    if instance:
        return instance.LEVERAGE_ONE
    return None

def get_leverage_two():
    instance = get_all_instance()
    if instance:
        return instance.LEVERAGE_TWO
    return None

def get_leverage_three():
    instance = get_all_instance()
    if instance:
        return instance.LEVERAGE_THREE
    return None

def get_leverage_four():
    instance = get_all_instance()
    if instance:
        return instance.LEVERAGE_FOUR
    return None

def get_leverage_one_coef():
    instance = get_all_instance()
    if instance:
        return instance.LEVERAGE_ONE_COEF
    return None

def get_leverage_tree_coef():
    instance = get_all_instance()
    if instance:
        return instance.LEVERAGE_TREE_COEF
    return None

def get_demand():
    instance = get_all_instance()
    if instance:
        return instance.demand
    return None

def get_supply():
    instance = get_all_instance()
    if instance:
        return instance.supply
    return None

def get_transactions():
    instance = get_all_instance()
    if instance:
        return instance.TRANSACTIONS
    return None
def get_b_a_value():
    instance = get_all_instance()
    if instance:
        return instance.B_A_VALUE
    return None

# Setters
def set_leverage_one(value):
    instance = get_all_instance()
    if instance:
        instance.LEVERAGE_ONE = value
        instance.save()

def set_leverage_two(value):
    instance = get_all_instance()
    if instance:
        instance.LEVERAGE_TWO = value
        instance.save()

def set_leverage_three(value):
    instance = get_all_instance()
    if instance:
        instance.LEVERAGE_THREE = value
        instance.save()

def set_leverage_four(value):
    instance = get_all_instance()
    if instance:
        instance.LEVERAGE_FOUR = value
        instance.save()

def set_leverage_one_coef(value):
    instance = get_all_instance()
    if instance:
        instance.LEVERAGE_ONE_COEF = value
        instance.save()

def set_leverage_tree_coef(value):
    instance = get_all_instance()
    if instance:
        instance.LEVERAGE_TREE_COEF = value
        instance.save()

def set_demand(value):
    instance = get_all_instance()
    if instance:
        instance.demand = value
        instance.save()

def set_supply(value):
    instance = get_all_instance()
    if instance:
        instance.supply = value
        instance.save()

def set_b_a_value(value):
    instance = get_all_instance()
    if instance:
        instance.B_A_VALUE = value
        instance.save()

def set_transactions(value):
    instance = get_all_instance()
    if instance:
        instance.TRANSACTIONS = value
        instance.save()

def change_to_a(b):
    return b*get_b_a_value()

def change_to_b(a):
    print(a/get_b_a_value())
    return a/get_b_a_value()



def get_duel_fee(attakcer,defender):
    return 1

def get_reject_fee(attacker,defender):
    return 2


def get_duel_loose_fee(looser:Team,winner:Team):
    if(winner.score>looser.score):
        return (winner.score-looser.score)*0.025
        
    else:
        return (looser.score-winner.score)*0.1



def get_duel_win_fee(looser,winner):
    if(winner.score>looser.score):
        delta=(winner.score-looser.score)*0.025
    else:
        delta=(looser.score-winner.score)*0.1
        
    return 40+delta

def calcuate_b_a():
    global K
    print(get_demand(),get_supply())
    set_b_a_value(get_b_a_value()+K*(get_demand()-get_supply()))
    set_b_a_value(max(get_b_a_value(),1))
    set_demand(0)
    set_supply(0)
    for team in Team.objects.all():
        set_team_score(team)
    BA.objects.create(value=get_b_a_value())

    
    
def set_team_score(team:Team):
    
    team.score=change_to_b(team.A)+team.B

    team.save()
