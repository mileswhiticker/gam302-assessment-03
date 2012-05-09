#include "HabitableObject.hpp"
#include "StarSystem.hpp"
#include "Helpers.hpp"
#include "SelectListener.hpp"
#include "Trader.hpp"

#include <iostream>

HabitableObject::HabitableObject(SelectListener* a_pSelectListener)
:	m_MaxPop(0)
,	m_CurPop(0)
,	m_DevelopmentLevel(0)
,	m_IndustrialLevel(0)
,	m_Inhabited(false)
,	m_MaxDevLevel(0)
,	m_MaxIndLevel(0)
,	m_PopulationStarving(false)
,	m_IndustryStarving(false)
,	m_InfrastructureBonus(1)
,	m_Money(0)
,	MyType(INVALID_HAB)
,	pSelectListener(a_pSelectListener)
{
	static int curID = 0;
	SettlementUID = curID++;
	for(int resType = 1; resType < END_RESOURCE; resType++)
	{
		ResourcePool[(RESOURCE_TYPE)resType] = 0.0f;
		ExploitableResources[(RESOURCE_TYPE)resType] = 0.0f;
		ResourceQuality[(RESOURCE_TYPE)resType] = 0.0f;
		ExploitableQuality[(RESOURCE_TYPE)resType] = 0.0f;
	}
}

void HabitableObject::Update(double a_Dt, double a_TimeRate)
{
	//timeRate = number of ingame days / 1 outgame second
	//1 ingame update per day
	//number of ingame days since last update = deltaT * timeRate
	double timePassed = a_Dt * a_TimeRate;
	if(m_Inhabited)
	{
		//save some space here by moving most of this shit elsewhere
		GrowPopulation(timePassed);
		ProduceRawMaterials(timePassed);
		ProduceFinishedGoods(timePassed);
		BuildInfrastructure(timePassed);
	}

	//update any traders here
	for(unsigned short i=0;i<PlanetsideTraders.size();i++)
	{
		PlanetsideTraders[i]->Update(a_Dt, a_TimeRate);
	}
}

void HabitableObject::SelectMe()
{
	if(pSelectListener)
		pSelectListener->Fire(this, SelectListener::LISTENER_SETTLEMENT);
}

bool HabitableObject::IsInfrastructureStarving()
{
	return m_IndustryStarving;
}

bool HabitableObject::IsPopulationStarving()
{
	return m_PopulationStarving;
}
