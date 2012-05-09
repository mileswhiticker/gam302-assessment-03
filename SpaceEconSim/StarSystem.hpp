#ifndef STAR_SYSTEM_HPP
#define STAR_SYSTEM_HPP

#include "Planet.hpp"

#include <string>
#include <vector>

class StarSystem
{
public:
	StarSystem();
	void Update(float a_Dt);
	//
private:
	std::vector<Planet> Planets;
	std::string m_StarName;
	//
};

#endif	//STAR_SYSTEM_HPP