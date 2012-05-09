#include "GameHelpers.hpp"
#include "Helpers.hpp"

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
	if(! (rand()%3) )
	{
		out += " ";
		std::vector<std::string> possibleSuffixes;
		//
		possibleSuffixes.push_back("Majoris");
		possibleSuffixes.push_back("Minoris");
		possibleSuffixes.push_back("Prior");
		possibleSuffixes.push_back("Posterior");
		possibleSuffixes.push_back("Eridanus");
		possibleSuffixes.push_back("al Cygni");
		//
		out += possibleSuffixes[rand()%possibleSuffixes.size()];
	}
	else
	{
		out += "-";
		out += Num2Str(rand()%1000);
	}
	//
	return out;
}

std::string GetShipName()
{
	std::string out;
	//
	std::vector<std::string> adjectives;
	adjectives.push_back("Astral");
	adjectives.push_back("Solar");
	adjectives.push_back("Stellar");
	adjectives.push_back("Swift");
	adjectives.push_back("Bounteous");
	adjectives.push_back("Courteous");
	adjectives.push_back("Quiet");
	adjectives.push_back("Sleek");
	adjectives.push_back("Dark");
	adjectives.push_back("Lucky");
	adjectives.push_back("Celestial");
	//
	std::vector<std::string> nouns;
	nouns.push_back("Explorer");
	nouns.push_back("Queen");
	nouns.push_back("Lady");
	nouns.push_back("Zephyr");
	nouns.push_back("Pioneer");
	nouns.push_back("Raven");
	nouns.push_back("Envoy");
	nouns.push_back("Enterprise");
	nouns.push_back("Pathfinder");
	nouns.push_back("Surprise");
	nouns.push_back("Sprinter");
	nouns.push_back("Flame");
	nouns.push_back("Princess");
	nouns.push_back("Gallivant");
	nouns.push_back("Alacrity");
	nouns.push_back("Horizon");
	nouns.push_back("Guardian");
	//
	std::vector<std::string> properNouns;
	properNouns.push_back("Ariel");
	properNouns.push_back("Arrakis");
	properNouns.push_back("Terra");
	properNouns.push_back("Zhu Que");
	properNouns.push_back("Santo");
	properNouns.push_back("Silverhold");
	properNouns.push_back("Lazarus");
	//
	if(rand()%4)
	{
		out += adjectives[rand()%adjectives.size()];
		out += " ";
		out += nouns[rand()%nouns.size()];
	}
	else
	{
		if(! (rand()%5))
			out += adjectives[rand()%adjectives.size()] + " ";
		out += nouns[rand()%nouns.size()];
		out += " of ";
		out += properNouns[rand()%properNouns.size()];
	}
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
	default:
		{
			return std::string("Invalid resource type");
		}
	}
}

std::string GetShipTypeAsStr(Ship::Type MyType)
{
	switch(MyType)
	{
	case(Ship::SHIP_CORVETTE):
		{
			return std::string("Corvette");
		}
	case(Ship::SHIP_FRIGATE):
		{
			return std::string("Frigate");
		}
	case(Ship::SHIP_LINER):
		{
			return std::string("Bulk Liner");
		}
	default:
		{
			return std::string("Invalid ship type");
		}
	}
}

std::string GetTraderName()
{
	std::string out;
	std::vector<std::string> firstNames;
	firstNames.push_back("Kenth");
	firstNames.push_back("Kura");
	firstNames.push_back("Porro");
	firstNames.push_back("Dick");
	firstNames.push_back("Katie");
	firstNames.push_back("Gil");
	firstNames.push_back("Dash");
	firstNames.push_back("Enjas");
	firstNames.push_back("John");
	firstNames.push_back("Rege");
	firstNames.push_back("Viny");
	firstNames.push_back("Jackeith");
	out += firstNames[rand()%firstNames.size()] + " ";
	//
	std::vector<std::string> surNames;
	surNames.push_back("Halcard");
	surNames.push_back("Tillo");
	surNames.push_back("Leitheds");
	surNames.push_back("Felis");
	surNames.push_back("Melne");
	surNames.push_back("Jissard");
	surNames.push_back("Vancil");
	surNames.push_back("Shule");
	surNames.push_back("Lowsyk");
	surNames.push_back("Kara");
	surNames.push_back("Darend");
	surNames.push_back("Felian");
	surNames.push_back("Orum");
	surNames.push_back("Lerga");
	surNames.push_back("Bryante");
	surNames.push_back("Dersand");
	out += surNames[rand()%surNames.size()];
	//
	return out;
}

std::string GetHabTypeAsStr(HabitableObject::Type MyType)
{
	switch(MyType)
	{
	case(HabitableObject::HAB_TERRA):
		{
			return std::string("Terrestrial Colony");
		}
	case(HabitableObject::HAB_DEAD):
		{
			return std::string("Dead World Biodome");
		}
	case(HabitableObject::HAB_GAS):
		{
			return std::string("Gas Collector Array");
		}
	case(HabitableObject::HAB_ASTEROID):
		{
			return std::string("Asteroid Mining Network");
		}
	default:
		{
			return std::string("Invalid settlement type");
		}
	}
}

std::string GetObjTypeAsStr(HabitableObject::Type MyType)
{
	switch(MyType)
	{
	case(HabitableObject::HAB_TERRA):
		{
			return std::string("Terrestrial planet");
		}
	case(HabitableObject::HAB_DEAD):
		{
			return std::string("Dead World");
		}
	case(HabitableObject::HAB_GAS):
		{
			return std::string("Gas giant");
		}
	case(HabitableObject::HAB_ASTEROID):
		{
			return std::string("Asteroid belt");
		}
	default:
		{
			return std::string("Invalid settlement type");
		}
	}
}

std::string GetPlanetName()
{
	std::string out;
	//
	out += GetRandomLetter();
	out += GetRandomLetter();
	out += GetRandomLetter();
	out += "-";
	out += Num2Str(rand()%1000);
	//
	return out;
}
