#include "GameInst.hpp"
#include "Helpers.hpp"
#include "GameHelpers.hpp"
#include "StarSystem.hpp"
#include "Planet.hpp"

void GameInst::SetupSystemDetailGUI()
{
	//create windows
	m_pSystemView = sfg::Table::Create();
	m_pSelectedSystem = NULL;

	//create table cells
	for(unsigned short i = 0; i < MAX_SYSTEMOBJECTS + 2; i++)
	{
		SystemDetailCells.push_back(sfg::Label::Create("system detail cell " + Num2Str(i + 1)));
		m_pSystemView->Attach(SystemDetailCells.back(), sf::Rect<sf::Uint32>(1, i + 1, 1, 1));
		//SystemDetailCells.back()->OnLeftClick.Connect(&Planet::SelectMe, a_pSystem);
	}

	//asteroid is a speshul case
	//SystemListItems[a_pSystem->SystemUID]->OnLeftClick.Connect(&StarSystem::SelectMe, a_pSystem);
}

void GameInst::UpdateSystemDetailGUI()
{
	if(m_pSelectedSystem && m_CurView == VIEW_SYSTEM)
	{
		//nothing to see here, folks
		SystemDetailCells[0]->SetText("Star name: " + m_pSelectedSystem->m_StarName);
		SystemDetailCells[1]->SetText("Asteroid belt");

		//update list of planets
		int numPlanets = m_pSelectedSystem->Planets.size();
		for(unsigned short n=2; n<numPlanets + 2; n++)
		{
			SystemDetailCells[n]->SetText( GetObjTypeAsStr(m_pSelectedSystem->Planets[n-2].MyType) + ": " + m_pSelectedSystem->Planets[n-2].m_Name );
			SystemDetailCells[n]->OnLeftClick.Connect( &Planet::SelectMe, &m_pSelectedSystem->Planets[n-2] );
		}

		//clear other cells
		int numEmptyCells = MAX_SYSTEMOBJECTS - numPlanets;
		for(unsigned short n = numPlanets + 2; n < numEmptyCells + numPlanets + 2; n++)
		{
			SystemDetailCells[n]->SetText("");
		}
	}
	else
	{
		for(unsigned short n=0;n<SystemDetailCells.size();n++)
		{
			SystemDetailCells[n]->SetText("");
		}
	}

	//update the cells
	sfg::Container::WidgetsList cells = m_pSystemView->GetChildren();
	for(unsigned short n=0;n<cells.size();n++)
	{
		cells[n]->Update(0);
	}
}
