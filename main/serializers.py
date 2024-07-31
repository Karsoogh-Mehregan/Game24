from rest_framework.serializers import Serializer,ModelSerializer
from rest_framework import serializers
from .models import Team,Duel,BA,Game


class TeamSerializer(serializers.ModelSerializer):
    status = serializers.SerializerMethodField()

    class Meta:
        model = Team
        fields = ["id", "name", "A", "B", "score", "status"]

    def get_status(self, obj: Team):
        opposing_team=""
        if(obj.stat==1):
            opposing_team=Duel.objects.filter(attacker=obj).filter(winner=None)[0].attacker.name
            return obj._stats[obj.stat]+f"({opposing_team})"

        elif(obj.stat==2):
            opposing_team=Duel.objects.filter(defender=obj).filter(winner=None)[0].attacker.name
            return obj._stats[obj.stat]+f"({opposing_team})"
        
        return obj._stats[obj.stat]



class BASerializer(serializers.ModelSerializer):
    class Meta:
        model=BA
        fields = ["value"]

class GameSerializer(serializers.ModelSerializer):
    class Meta:
        model=Game
        fields=["name","score","value"]

