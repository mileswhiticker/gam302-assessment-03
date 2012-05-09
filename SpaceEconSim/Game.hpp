#ifndef GAME_HPP
#define GAME_HPP

#include <vector>
#include <map>
#include "StarSystem.hpp"

class Trader;

class Game
{
public:
	Game();
	void CreateNewWorld(SelectListener* a_pSelectListener);
	void Update(float a_Dt);
	bool CheckInitialised();
	//
	std::map<int, Trader*> AllTraders;
	std::vector<StarSystem> StarSystems;
	//
private:
	bool m_Initialised;
	float TimePassageRate;
	//
	std::map<int, Trader*> InterstellarTraders;	//traders in interstellar space.
};

#endif	//GAME_HPP