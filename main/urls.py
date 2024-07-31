from django.urls import path
from .views import *

from django.http import HttpResponse
def test(request):
    return HttpResponse("servers up")

urlpatterns = [
    path("",test),
    path("teams",AllTeam.as_view()),
    path("team/<int:id>",GetTeam.as_view()),
    path("exchange/A",ExchangeA.as_view()),
    path("exchange/B",ExchangeB.as_view()),
    path("questions/<int:team>",GetQuestions.as_view()),
    path("buy",BuyQuestions.as_view()),
    path("solve",SolveQuestion.as_view()),
    path("attack",Attack.as_view()),
    path("duel/<int:team_id>",GetDuel.as_view()),
    path("accept",AcceptDuel.as_view()),
    path("reject",RejectDuel.as_view()),
    path("end-duel",EndDuel.as_view()),
    path("calculate",Calculate.as_view()),
    path("ba",GetValue.as_view()),
    path("game/<int:team_id>",GetGame.as_view()),
    path("end-game",EndGame.as_view()),
    path("games",AllGames.as_view()),
    path("start-game",StartGame.as_view()),
    path("set-score",SetScore.as_view()),
    path("set-a",SetA.as_view()),
    path("set-b",SetB.as_view()),
    path("get-leverages",GetLeverageStat.as_view()),
    path("toggle-lev-1",ToggleLeverage1.as_view()),
    path("toggle-lev-2",ToggleLeverage2.as_view()),
    path("buy-random",BuyRandom.as_view()),



]