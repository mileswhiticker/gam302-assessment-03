#ifndef GAME_HELPERS_HPP
#define GAME_HELPERS_HPP

#include <string>
#include "Resources.hpp"
#include "Ship.hpp"
#include "HabitableObject.hpp"

std::string GetShipName();

std::string GetStarName();

std::string GetPlanetName();

std::string GetResourceAsStr(RESOURCE_TYPE Type);
std::string GetShipTypeAsStr(Ship::Type MyType);
std::string GetHabTypeAsStr(HabitableObject::Type MyType);
std::string GetObjTypeAsStr(HabitableObject::Type MyType);

std::string GetTraderName();

#endif	//GAME_HELPERS_HPP