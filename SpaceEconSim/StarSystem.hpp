#ifndef STAR_SYSTEM_HPP
#define STAR_SYSTEM_HPP

#define MIN_SYSTEMOBJECTS 1
#define MAX_SYSTEMOBJECTS 10

#include "Planet.hpp"
#include "AsteroidBelt.hpp"

#include <string>
#include <vector>

class Game;

class SelectListener;

class StarSystem
{
public:
	StarSystem(Game& a_Game, SelectListener* a_pSelectListener);
	void Update(float a_Dt, float TimePassageRate);
	//
	std::vector<Planet> Planets;
	std::string m_StarName;
	int SystemUID;
	//
	void SelectMe();
	//
private:
	SelectListener* m_pSelectListener;
	Game& m_Game;
	AsteroidBelt AsteroidMiningBelt;
	//
	std::map<int, Trader*> InsystemTraders;	//traders moving through a star system
};

#endif	//STAR_SYSTEM_HPP