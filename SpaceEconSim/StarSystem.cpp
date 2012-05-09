#include "StarSystem.hpp"
#include "GameHelpers.hpp"

#define MIN_SYSTEMOBJECTS 1
#define MAX_SYSTEMOBJECTS 10

StarSystem::StarSystem()
:	m_StarName(GetStarName())
{
	short numPlanets = rand()%MAX_SYSTEMOBJECTS + MIN_SYSTEMOBJECTS;
	for(short i=0; i<numPlanets; i++)
	{
		Planets.push_back(Planet());
	}
}

void StarSystem::Update(float a_Dt)
{
	for(unsigned short i=0; i<Planets.size(); i++)
	{
		Planets[i].Update(a_Dt, 1);
	}
}
