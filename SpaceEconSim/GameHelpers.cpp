#include "GameHelpers.hpp"

#include <vector>

std::string GetStarName()
{
	std::string out;
	//
	std::vector<std::string> possiblePrefixes;
	//
	possiblePrefixes.push_back("Antares");
	possiblePrefixes.push_back("Acrux");
	possiblePrefixes.push_back("Alderamin");
	possiblePrefixes.push_back("Aldebaran");
	possiblePrefixes.push_back("Betelguese");
	possiblePrefixes.push_back("Sirius");
	possiblePrefixes.push_back("Arcturus");
	possiblePrefixes.push_back("Arrakis");
	possiblePrefixes.push_back("Deneb");
	possiblePrefixes.push_back("Scheat");
	possiblePrefixes.push_back("Terebellum");
	possiblePrefixes.push_back("Yed");
	//
	out += possiblePrefixes[rand()%possiblePrefixes.size()];
	//
	if(rand()%3)
	{
		out += " ";
		std::vector<std::string> possibleSuffixes;
		//
		possibleSuffixes.push_back("Majoris");
		possibleSuffixes.push_back("Minoris");
		possibleSuffixes.push_back("Prior");
		possibleSuffixes.push_back("Posterior");
		possibleSuffixes.push_back("Eridanus");
		possibleSuffixes.push_back("Taurus");
		possibleSuffixes.push_back("Cygnus");
		possibleSuffixes.push_back("Ursa");
		possibleSuffixes.push_back("Canis");
		possibleSuffixes.push_back("Draco");
		//
		out += possibleSuffixes[rand()%possibleSuffixes.size()];
	}
	else
	{
		out += "-";
		out += rand()%1000;
	}
	//
	return out;
}

std::string GetShipName()
{
	std::string out = "Default Ship Name";
	return out;
}

std::string GetResourceAsStr(RESOURCE_TYPE Type)
{
	switch(Type)
	{
	case(RESOURCE_METALORE):
		{
			return std::string("Metal ore");
		}
	case(RESOURCE_CRYSTALORE):
		{
			return std::string("Crystal ore");
		}
	case(RESOURCE_HYDROGEN):
		{
			return std::string("Hydrogen");
		}
	case(RESOURCE_FUEL):
		{
			return std::string("Fuel");
		}
	case(RESOURCE_FOOD):
		{
			return std::string("Food");
		}
	case(RESOURCE_METALPLATES):
		{
			return std::string("Metal plates");
		}
	case(RESOURCE_COMPONENTS):
		{
			return std::string("Electrical components");
		}
	case(RESOURCE_LUXURYGOODS):
		{
			return std::string("Luxury goods");
		}
	}
}
