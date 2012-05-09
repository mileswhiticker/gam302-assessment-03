#include "AsteroidBelt.hpp"

AsteroidBelt::AsteroidBelt()
:	HabitableObject()
{
	ExploitableResources[RESOURCE_METALORE] = (double)(rand()%15) + (double)(rand()%150) / 100;
	ExploitableQuality[RESOURCE_METALORE] = (double)(rand()%100);
	ExploitableResources[RESOURCE_CRYSTALORE] = (double)(rand()%5) + (double)(rand()%50) / 100;
	ExploitableQuality[RESOURCE_CRYSTALORE] = (double)(rand()%100);
	//
	m_MaxDevLevel = 350;
	m_InfrastructureBonus = 0.75;
}

void AsteroidBelt::Update(double a_Dt, double a_TimeRate)
{
	HabitableObject::Update(a_Dt, a_TimeRate);
	//
}

std::map<RESOURCE_TYPE, double> AsteroidBelt::GetNextDevReq(double a_TimePassed)
{
	std::map<RESOURCE_TYPE, double> reqs;
	//
	return reqs;
}

std::map<RESOURCE_TYPE, double> AsteroidBelt::GetNextIndReq(double a_TimePassed)
{
	std::map<RESOURCE_TYPE, double> reqs;
	//
	return reqs;
}
