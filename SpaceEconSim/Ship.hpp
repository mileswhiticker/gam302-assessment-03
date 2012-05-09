#ifndef SHIP_HPP
#define SHIP_HPP

#include <vector>
#include "Resources.hpp"

struct Ship
{
	Ship();
	enum Type
	{
		INVALID_SHIP = 0,
		SHIP_CORVETTE,
		SHIP_FRIGATE,
		SHIP_LINER
	};
	Type Type;
	std::string Name;
	//
	float MaintLevel;
	float MaintMax;
	float FuelStored;
	float FuelMax;
	float Speed;
	float GetRange();
	//
	float StorageUsed;
	float StorageMax;
	std::vector<RESOURCE_TYPE> StoredResources;
};

#endif	//SHIP_HPP