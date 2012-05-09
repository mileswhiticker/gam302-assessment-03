#include "HabitableObject.hpp"
#include "Helpers.hpp"

//re production - population directly affects productivity
//if current pop greater than 50% of sustainable population, and there's a good labourforce
//less than 50%, and there's labour shortages

void HabitableObject::ProduceRawMaterials(double a_TimePassed)
{
	double popFactor = 0.5f + m_CurPop / m_MaxSustainablePop;

	//produce some raw materials
	//amount produced is primarily affected by the development level
	for(int resType = 1; resType < END_RESOURCE; resType++)
	{
		//how much of the resource is produced
		double producedResources = ExploitableResources[(RESOURCE_TYPE)resType] * m_DevelopmentLevel * popFactor;

		//modify the avg quality of the pool by the quality of what's being produced
		//whichever is larger will have a stronger effect on the quality of the final pool
		double deltaQ = ResourceQuality[(RESOURCE_TYPE)resType] - ExploitableQuality[(RESOURCE_TYPE)resType];
		deltaQ /= 2 * (producedResources / ResourcePool[(RESOURCE_TYPE)resType]);

		//add the produced resources and modify the pooled quality accordingly
		ResourceQuality[(RESOURCE_TYPE)resType] += (double)deltaQ;
		ResourcePool[(RESOURCE_TYPE)resType] += (double)producedResources;
	}
}

void HabitableObject::ProduceFinishedGoods(double a_TimePassed)
{
	//finished goods to be hardcoded for now, unfortunately :(
	double popFactor = 0.5f + m_CurPop / m_MaxSustainablePop;
	
	//---------- metal ore > metal plates ----------//
	if(ResourcePool[RESOURCE_METALORE] > 0)
	{
		//amount produced is primarily affected by the industrial level
		double producedGoods = min((double)( (double)m_IndustrialLevel * 1000 * popFactor * (a_TimePassed/360.0) ), ResourcePool[RESOURCE_METALORE]);

		//avg quality between the stored pool and the produced amount
		double producedQ = ExploitableQuality[RESOURCE_METALORE] + m_IndustrialLevel / 10;
		double deltaQ = ResourceQuality[RESOURCE_METALPLATES] - producedQ;
		deltaQ /= 2 * (producedGoods / ResourcePool[RESOURCE_METALPLATES]);

		//add the produced resources and modify the pooled quality accordingly
		ResourceQuality[RESOURCE_METALPLATES] += (double)deltaQ;
		ResourcePool[RESOURCE_METALPLATES] += (double)producedGoods;
	}
	
	//---------- crystal ore > electrical components ----------//
	if(ResourcePool[RESOURCE_CRYSTALORE] > 0)
	{
		//amount produced is primarily affected by the industrial level
		double producedGoods = min((double)( (double)m_IndustrialLevel * 1000 * popFactor * (a_TimePassed/360.0) ), ResourcePool[RESOURCE_CRYSTALORE]);

		//avg quality between the stored pool and the produced amount
		double producedQ = ExploitableQuality[RESOURCE_CRYSTALORE] + m_IndustrialLevel / 10;
		double deltaQ = ResourceQuality[RESOURCE_COMPONENTS] - producedQ;
		deltaQ /= 2 * (producedGoods / ResourcePool[RESOURCE_COMPONENTS]);

		//add the produced resources and modify the pooled quality accordingly
		ResourceQuality[RESOURCE_COMPONENTS] += (double)deltaQ;
		ResourcePool[RESOURCE_COMPONENTS] += (double)producedGoods;
	}
	
	//---------- hydrogen > fuel ----------//
	if(ResourcePool[RESOURCE_CRYSTALORE] > 0)
	{
		//amount produced is primarily affected by the industrial level
		double producedGoods = min((double)( (double)m_IndustrialLevel * 1000 * popFactor * (a_TimePassed/360.0) ), ResourcePool[RESOURCE_HYDROGEN]);

		//avg quality between the stored pool and the produced amount
		double producedQ = ExploitableQuality[RESOURCE_HYDROGEN] + m_IndustrialLevel / 10;
		double deltaQ = ResourceQuality[RESOURCE_FUEL] - producedQ;
		deltaQ /= 2 * (producedGoods / ResourcePool[RESOURCE_FUEL]);

		//add the produced resources and modify the pooled quality accordingly
		ResourceQuality[RESOURCE_FUEL] += (double)deltaQ;
		ResourcePool[RESOURCE_FUEL] += (double)producedGoods;
	}
}
