#ifndef TRADER_HPP
#define TRADER_HPP

#include "Ship.hpp"
class SelectListener;

class Trader
{
public:
	Trader(SelectListener* a_pSelectListener = NULL);
	void Update(double a_Dt, double TimePassageRate);
	//
	std::string Name;
	float Money;
	int Decisiveness;
	int Restlessness;
	int Pride;
	int Caution;
	int Ambition;
	int RiskTaker;
	//
	Ship MyShip;
	int TraderUID;
	int LocationUID;
	int DestinationUID;
	//
	void SelectMe();
	//
private:
	SelectListener* pSelectListener;
	//
};

#endif	//TRADER_HPP