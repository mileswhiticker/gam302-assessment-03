#ifndef HABITABLE_OBJECT_HPP
#define HABITABLE_OBJECT_HPP

#include <map>
#include "Resources.hpp"

class HabitableObject
{
public:
	HabitableObject();
	virtual void Update(double a_Dt, double a_TimeRate);
	//
protected:
	int m_MaxSustainablePop;
	int m_CurPop;
	double m_DevelopmentLevel;
	double m_IndustrialLevel;
	std::string m_Name;
	bool m_Inhabited;
	//
	std::map<RESOURCE_TYPE,double> ExploitableResources;
	std::map<RESOURCE_TYPE,double> ExploitableQuality;
	std::map<RESOURCE_TYPE,double> ResourceQuality;
	std::map<RESOURCE_TYPE, double> ResourcePool;
	//
	double m_MaxDevLevel;
	double m_MaxIndLevel;
	double m_InfrastructureBonus;	//asteroid mining networks and gas collectors get infrastructure bonuses due to being cheaper to develop
	//
private:
	void ProduceRawMaterials(double a_TimePassed);
	void ProduceFinishedGoods(double a_TimePassed);
	void GrowPopulation(double a_TimePassed);
	void BuildInfrastructure(double a_TimePassed);
	//
	bool m_PopulationStarving;
	bool m_IndustryStarving;
};

#endif	//HABITABLE_OBJECT_HPP