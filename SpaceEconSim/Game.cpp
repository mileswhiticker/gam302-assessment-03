#include "Game.hpp"
#include "Trader.hpp"

#include <iostream>
#include <sstream>

#define MIN_STARSYSTEMS 1
#define MAX_STARSYSTEMS 5

Game::Game()
:	m_Initialised(false)
,	TimePassageRate(1)
{
	//
}

bool Game::CheckInitialised()
{
	return m_Initialised;
}

void Game::CreateNewWorld(SelectListener* a_pSelectListener)
{
	m_Initialised = true;

	//stuff
	short numStarSystems = rand()%MAX_STARSYSTEMS + MIN_STARSYSTEMS;
	for(short i=0;i<numStarSystems;i++)
	{
		StarSystems.push_back(StarSystem(*this, a_pSelectListener));
	}
}

void Game::Update(float a_Dt)
{
	m_Initialised = false;
	std::stringstream out;
	out << "Game Update, fps: " << 1/a_Dt;
	//std::cout << out.str().c_str() << std::endl;

	//update all star systems out there
	for(unsigned short i=0;i<StarSystems.size();i++)
	{
		StarSystems[i].Update(a_Dt, TimePassageRate);
	}

	//update any traders in interstellar space
	for(unsigned short i=0;i<InterstellarTraders.size();i++)
	{
		InterstellarTraders[i]->Update(a_Dt, TimePassageRate);
	}
}
