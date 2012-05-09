#ifndef PLANET_HPP
#define PLANET_HPP

#include "HabitableObject.hpp"
#include <map>

class Planet : public HabitableObject
{
public:
	enum Type
	{
		INVALID = 0,
		DEAD,
		GASGIANT,
		TERRESTRIAL
	};
	//
	Planet(SelectListener* a_pSelectListener, Planet::Type a_PlanetType = INVALID);
	virtual void Update(double a_Dt, double a_TimeRate);
	//
	virtual std::map<RESOURCE_TYPE, double> GetNextDevReq(double a_TimePassed);
	virtual std::map<RESOURCE_TYPE, double> GetNextIndReq(double a_TimePassed);
	//
	void SelectMe();
	//
private:
	Planet::Type m_MyType;
	//
};

#endif	//PLANET_HPP