#include "HabitableObject.hpp"
#include "Helpers.hpp"

void HabitableObject::GrowPopulation(double a_TimePassed)
{
	//stuff only happens here if there are humans to make it happen >.>
	m_MaxPop = (int)(100000.0f * m_DevelopmentLevel);
		
	//eat some food
	double foodRequired = 0.00213f * m_CurPop * a_TimePassed;
	if(foodRequired > ResourcePool[RESOURCE_FOOD])
		m_PopulationStarving = true;
	else
		m_PopulationStarving = false;
	ResourcePool[RESOURCE_FOOD] -= min((double)foodRequired, ResourcePool[RESOURCE_FOOD]);

	if(m_CurPop > m_MaxPop || m_PopulationStarving)
	{
		//some people die due to overcrowding (homelessness is a terrible thing) or lack of food
		double popLoss = pow(1 + (double)( rand()%4 + 1) / 100 + (double)( rand()%10 + 1) / 1000 + (double)( rand()%10 + 1) / 10000, a_TimePassed);
		m_CurPop -= (int)( (double)m_CurPop * popLoss);

		//make sure we always have at least 0 people... todo: properly despawn settlements
		if(m_CurPop < 0)
		{
			m_CurPop = 0;
			m_Inhabited = false;
		}
	}
	else
	{
		//population grows a bit
		double popGrowth = pow(1 + (double)( rand()%3 ) / 100 + (double)( rand()%10 + 1) / 1000 + (double)( rand()%10 + 1) / 10000, a_TimePassed);
		m_CurPop += (int)( (double)m_CurPop * popGrowth);
	}
}
