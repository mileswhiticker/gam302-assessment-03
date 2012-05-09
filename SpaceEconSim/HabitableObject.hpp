#ifndef HABITABLE_OBJECT_HPP
#define HABITABLE_OBJECT_HPP

#include <map>
#include "Resources.hpp"

class StarSystem;
class SelectListener;
class Trader;

class HabitableObject
{
public:
	enum Type
	{
		INVALID_HAB = 0,
		//
		HAB_TERRA,
		HAB_DEAD,
		HAB_GAS,
		HAB_ASTEROID,
		//
		MAX_HAB
	};
	Type MyType;
	HabitableObject(SelectListener* a_pSelectListener = NULL);
	virtual void Update(double a_Dt, double a_TimeRate);
	void SelectMe();
	//
	bool IsInfrastructureStarving();
	bool IsPopulationStarving();
	//
public:
	int m_MaxPop;
	int m_CurPop;
	double m_DevelopmentLevel;
	double m_IndustrialLevel;
	std::string m_Name;
	bool m_Inhabited;
	//
	std::map<RESOURCE_TYPE,double> ExploitableResources;
	std::map<RESOURCE_TYPE,double> ExploitableQuality;
	std::map<RESOURCE_TYPE, double> ResourcePool;
	std::map<RESOURCE_TYPE,double> ResourceQuality;
	//
	double m_MaxDevLevel;
	double m_MaxIndLevel;
	double m_InfrastructureBonus;	//asteroid mining networks and gas collectors get infrastructure bonuses due to being cheaper to develop
	float m_Money;
	int SettlementUID;
	//
	StarSystem* ParentStar;
	std::map<int, Trader*> PlanetsideTraders;	//traders on the planet
	//
protected:
	SelectListener* pSelectListener;
	//
private:
	void ProduceRawMaterials(double a_TimePassed);
	void ProduceFinishedGoods(double a_TimePassed);
	void GrowPopulation(double a_TimePassed);
	void BuildInfrastructure(double a_TimePassed);
	//
	bool m_PopulationStarving;
	bool m_IndustryStarving;
	//
};

#endif	//HABITABLE_OBJECT_HPP