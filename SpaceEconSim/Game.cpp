#include "Game.hpp"

#include <iostream>
#include <sstream>

#define MIN_STARSYSTEMS 5
#define MAX_STARSYSTEMS 10

Game::Game()
:	m_Initialised(false)
{
	//
}

bool Game::CheckInitialised()
{
	return m_Initialised;
}

void Game::CreateNewWorld()
{
	m_Initialised = true;

	//stuff
	short numStarSystems = rand()%MAX_STARSYSTEMS + MIN_STARSYSTEMS;
	for(short i=0;i<numStarSystems;i++)
	{
		StarSystems.push_back(StarSystem());
	}
}

void Game::Update(float a_Dt)
{
	m_Initialised = false;
	std::stringstream out;
	out << "Game Update, fps: " << 1/a_Dt;
	std::cout << out.str().c_str() << std::endl;

	for(unsigned short i=0;i<StarSystems.size();i++)
	{
		StarSystems[i].Update(a_Dt);
	}

	//lotsa stuff
	//
}
