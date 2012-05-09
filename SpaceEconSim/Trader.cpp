#include "Trader.hpp"
#include "GameHelpers.hpp"
#include "Ship.hpp"
#include "SelectListener.hpp"

Trader::Trader(SelectListener* a_pSelectListener)
:	Name(GetTraderName())
,	Money(1000)
,	MyShip(Ship())
	//
,	Decisiveness(rand()%100)
,	Restlessness(rand()%100)
,	Pride(rand()%100)
,	Caution(rand()%100)
,	Ambition(rand()%100)
,	RiskTaker(rand()%100)
	//
,	pSelectListener(a_pSelectListener)
{
	static int curId = 0;
	TraderUID = curId++;
	LocationUID = 0;
	DestinationUID = 0;
}

void Trader::Update(double a_Dt, double TimePassageRate)
{
	//ai stuff
	//
}

void Trader::SelectMe()
{
	if(pSelectListener)
		pSelectListener->Fire(this, SelectListener::LISTENER_TRADER);
}
