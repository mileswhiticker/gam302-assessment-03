#ifndef ASTEROID_BELT_HPP
#define ASTEROID_BELT_HPP

#include "HabitableObject.hpp"

class AsteroidBelt : HabitableObject
{
public:
	AsteroidBelt();
	virtual void Update(double a_Dt, double a_TimeRate);
	//
	virtual std::map<RESOURCE_TYPE, double> GetNextDevReq(double a_TimePassed);
	virtual std::map<RESOURCE_TYPE, double> GetNextIndReq(double a_TimePassed);
	//
private:
	//
};

#endif