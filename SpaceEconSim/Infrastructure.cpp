#include "HabitableObject.hpp"
#include "Helpers.hpp"

//re production - population directly affects productivity
//if current pop greater than 50% of sustainable population, and there's a good labourforce
//less than 50%, and there's labour shortages

void HabitableObject::BuildInfrastructure(double a_TimePassed)
{
	double popFactor = 0.5f + m_CurPop / m_MaxPop;
	//infrastructure growth requires a small amount of plates, components and fuel
	//if not enough resources are in place, it will decay slightly
	//development requires less resources than industry to develop in a ratio of 2:1
	
	//work out how much resources we need
	double goodsRequired = m_DevelopmentLevel * popFactor * m_InfrastructureBonus * a_TimePassed;
	if( ResourcePool[RESOURCE_METALPLATES] < goodsRequired || ResourcePool[RESOURCE_FUEL] < goodsRequired || ResourcePool[RESOURCE_COMPONENTS] < goodsRequired )
		m_IndustryStarving = true;
	else
		m_IndustryStarving = false;
	//remove the necessary resources
	ResourcePool[RESOURCE_METALPLATES] -= min(goodsRequired, ResourcePool[RESOURCE_METALPLATES]);
	ResourcePool[RESOURCE_FUEL] -= min(goodsRequired, ResourcePool[RESOURCE_FUEL]);
	ResourcePool[RESOURCE_COMPONENTS] -= min(goodsRequired, ResourcePool[RESOURCE_COMPONENTS]);
	//if there was enough resources, grow
	if(!m_IndustryStarving)
	{
		m_DevelopmentLevel += (a_TimePassed / (360 * m_DevelopmentLevel) );
	}

	//work out how much resources we need
	goodsRequired = 2 * m_IndustrialLevel * popFactor * m_InfrastructureBonus * a_TimePassed;
	if( ResourcePool[RESOURCE_METALPLATES] < goodsRequired || ResourcePool[RESOURCE_FUEL] < goodsRequired || ResourcePool[RESOURCE_COMPONENTS] < goodsRequired )
		m_IndustryStarving = true;
	else
		m_IndustryStarving = false;
	//remove the necessary resources
	ResourcePool[RESOURCE_METALPLATES] -= min(goodsRequired, ResourcePool[RESOURCE_METALPLATES]);
	ResourcePool[RESOURCE_FUEL] -= min(goodsRequired, ResourcePool[RESOURCE_FUEL]);
	ResourcePool[RESOURCE_COMPONENTS] -= min(goodsRequired, ResourcePool[RESOURCE_COMPONENTS]);
	//if there was enough resources, grow
	if(!m_IndustryStarving)
	{
		m_DevelopmentLevel += (a_TimePassed / (360 * m_DevelopmentLevel) );
	}
}
