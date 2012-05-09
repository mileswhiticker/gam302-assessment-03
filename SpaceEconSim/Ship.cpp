#include "Ship.hpp"
#include "GameHelpers.hpp"

Ship::Ship()
:	Type(Ship::INVALID_SHIP)
,	Name(GetShipName())
,	MaintLevel(100)
,	MaintMax(100)
,	FuelStored(50)
,	FuelMax(50)
,	Speed(50)
,	StorageUsed(0)
,	StorageMax(1000)
{
	//
}

float Ship::GetRange()
{
	return FuelStored * 10;
}

	/*Type Type;
	std::string Name;
	//
	float MaintLevel;
	float MaintMax;
	float FuelStored;
	float FuelMax;
	float Speed;
	//
	float StorageUsed;
	float StorageMax;*/