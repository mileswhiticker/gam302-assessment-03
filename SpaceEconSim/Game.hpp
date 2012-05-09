#ifndef GAME_HPP
#define GAME_HPP

#include <vector>
#include "StarSystem.hpp"

class Game
{
public:
	Game();
	void CreateNewWorld();
	void Update(float a_Dt);
	bool CheckInitialised();
	//
private:
	bool m_Initialised;
	std::vector<StarSystem> StarSystems;
	//
};

#endif	//GAME_HPP