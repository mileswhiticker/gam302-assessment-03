#include "StarSystem.hpp"
#include "GameHelpers.hpp"
#include "SelectListener.hpp"
#include "Trader.hpp"

StarSystem::StarSystem(Game& a_Game, SelectListener* a_pSelectListener)
:	m_StarName(GetStarName())
,	m_pSelectListener(a_pSelectListener)
,	m_Game(a_Game)
,	AsteroidMiningBelt(m_pSelectListener)
{
	static int idNum = 0;
	SystemUID = idNum++;
	short numPlanets = rand()%MAX_SYSTEMOBJECTS + MIN_SYSTEMOBJECTS;
	for(short i=0; i<numPlanets; i++)
	{
		Planets.push_back(Planet(a_pSelectListener));
	}
}

void StarSystem::Update(float a_Dt, float TimePassageRate)
{
	//update all planets in the system
	for(unsigned short i=0; i<Planets.size(); i++)
	{
		Planets[i].Update(a_Dt, TimePassageRate);
	}

	//update the asteroid belt
	AsteroidMiningBelt.Update(a_Dt, TimePassageRate);

	//update any traders in between planets
	for(unsigned short i=0;i<InsystemTraders.size();i++)
	{
		InsystemTraders[i]->Update(a_Dt, TimePassageRate);
	}
}

void StarSystem::SelectMe()
{
	if(m_pSelectListener)
		m_pSelectListener->Fire(this, SelectListener::LISTENER_SYSTEM);
}
