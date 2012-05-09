#ifndef TRADER_HPP
#define TRADER_HPP

#include "Ship.hpp"

struct Trader
{
	std::string Name;
	float Money;
	int Decisiveness;
	int Restlessness;
	int Pride;
	int Caution;
	int Ambition;
	int RiskTaker;
	//
	Ship Ship;
	int LocationUID;
	int DestinationUID;
};

#endif	//TRADER_HPP