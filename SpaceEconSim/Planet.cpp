#include "Planet.hpp"
#include "SelectListener.hpp"

#include "Helpers.hpp"
#include "GameHelpers.hpp"

#define TERRESTRIAL_SPAWN_PROBABILITY 0.05f
#define GASGIANT_SPAWN_PROBABILITY 0.3f

Planet::Planet(SelectListener* a_pSelectListener, Planet::Type a_PlanetType)
:	HabitableObject(a_pSelectListener)
,	m_MyType(INVALID)
{
	//get a random name
	m_Name = GetPlanetName();

	//setup unique planet stats
	switch(a_PlanetType)
	{
	default:
		{
			//we want a random planet type
			if(rand()%100 < (int)(TERRESTRIAL_SPAWN_PROBABILITY*100) )
				a_PlanetType = TERRESTRIAL;
			else if(rand()%100 < (int)(GASGIANT_SPAWN_PROBABILITY*100) )
				a_PlanetType = GASGIANT;
			else
				a_PlanetType = DEAD;
			//fall through
		}
	case(TERRESTRIAL):
		{
			m_MyType = TERRESTRIAL;
			ExploitableResources[RESOURCE_METALORE] = (double)(rand()%20) + (double)(rand()%200) / 100;
			ExploitableQuality[RESOURCE_METALORE] = (double)(rand()%100);
			ExploitableResources[RESOURCE_CRYSTALORE] = (double)(rand()%10) + (double)(rand()%100) / 100;
			ExploitableQuality[RESOURCE_CRYSTALORE] = (double)(rand()%100);
			ExploitableResources[RESOURCE_FOOD] = (double)(rand()%20) + (double)(rand()%300) / 100;
			ExploitableQuality[RESOURCE_FOOD] = (double)(rand()%100);
			ExploitableResources[RESOURCE_HYDROGEN] = (double)(rand()%1) + (double)(rand()%50) / 100;
			ExploitableQuality[RESOURCE_HYDROGEN] = (double)(rand()%100);
			//
			m_MaxDevLevel = 1000;
			m_MaxIndLevel = 1000;
			//
			break;
		}
	case(GASGIANT):
		{
			m_MyType = GASGIANT;
			ExploitableResources[RESOURCE_HYDROGEN] = (double)(rand()%50) + (double)(rand()%500) / 100;
			ExploitableQuality[RESOURCE_HYDROGEN] = (double)(rand()%100);
			//
			m_MaxDevLevel = 750;
			m_MaxIndLevel = 750;
			m_InfrastructureBonus = 0.9;
			//
			break;
		}
	case(DEAD):
		{
			m_MyType = DEAD;
			ExploitableResources[RESOURCE_METALORE] = (double)(rand()%25) + (double)(rand()%250) / 100;
			ExploitableQuality[RESOURCE_METALORE] = (double)(rand()%100);
			ExploitableResources[RESOURCE_CRYSTALORE] = (double)(rand()%15) + (double)(rand()%150) / 100;
			ExploitableQuality[RESOURCE_CRYSTALORE] = (double)(rand()%100);
			ExploitableResources[RESOURCE_HYDROGEN] = (double)(rand()%50) / 100;
			ExploitableQuality[RESOURCE_HYDROGEN] = (double)(rand()%100);
			//
			m_MaxDevLevel = 350;
			m_MaxIndLevel = 350;
			//
			break;
		}
	}
}

void Planet::Update(double a_Dt, double a_TimeRate)
{
	HabitableObject::Update(a_Dt, a_TimeRate);
	//
}

std::map<RESOURCE_TYPE, double> Planet::GetNextDevReq(double a_TimePassed)
{
	std::map<RESOURCE_TYPE, double> reqs;
	//
	return reqs;
}

std::map<RESOURCE_TYPE, double> Planet::GetNextIndReq(double a_TimePassed)
{
	std::map<RESOURCE_TYPE, double> reqs;
	//
	return reqs;
}

void Planet::SelectMe()
{
	if(pSelectListener)
		pSelectListener->Fire(this, SelectListener::LISTENER_SETTLEMENT);
}
