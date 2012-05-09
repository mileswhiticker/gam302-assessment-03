#include "GameInst.hpp"
#include "Helpers.hpp"
#include "HabitableObject.hpp"
#include "StarSystem.hpp"
#include "GameHelpers.hpp"
#include "Resources.hpp"

void GameInst::SetupSettlementDetailGUI()
{
	//create windows
	m_pSettlementView = (sfg::Table::Create());
	m_pSelectedSettlement = NULL;
	
	//create table cells
	for(unsigned short i=0;i<3;i++)
	{
		//StorageSlots.push_back(sfg::Label::Create("storage slot " + Num2Str(i+1)));
		for(unsigned short j=0;j<8;j++)
		{
			SettlementDetailCells.push_back(sfg::Label::Create("settlement detail cell " + Num2Str(8*i + j + 1)));
			m_pSettlementView->Attach(SettlementDetailCells.back(), sf::Rect<sf::Uint32>(i + 1, j + 1, 1, 1));
		}
	}
}

void GameInst::UpdateSettlementDetailGUI()
{
	if(m_pSelectedSettlement && m_CurView == VIEW_SETTLEMENT)
	{
		//update the contents of all cells
		//column1
		SettlementDetailCells[SETTLEMENTNAME]->SetText( "Settlement name: " + m_pSelectedSettlement->m_Name );
		SettlementDetailCells[SETTLEMENTTYPE]->SetText( "Settlement type: " + GetHabTypeAsStr(m_pSelectedSettlement->MyType) );
		SettlementDetailCells[STARNAME]->SetText( "Primary star name: default" );
		SettlementDetailCells[WEALTH]->SetText( "Colony wealth: " + Num2Str(m_pSelectedSettlement->m_Money) );
		if(m_pSelectedSettlement->IsInfrastructureStarving())
		{
			SettlementDetailCells[INDLEVEL]->SetText( "Industrial infrastructure: " + Num2Str(m_pSelectedSettlement->m_IndustrialLevel) + "/" + Num2Str(m_pSelectedSettlement->m_MaxIndLevel) + "(starving)");
			SettlementDetailCells[DEVLEVEL]->SetText( "Developmental infrastructure: " + Num2Str(m_pSelectedSettlement->m_DevelopmentLevel) + "/" + Num2Str(m_pSelectedSettlement->m_MaxDevLevel) + "(starving)");
		}
		else
		{
			SettlementDetailCells[INDLEVEL]->SetText( "Industrial infrastructure: " + Num2Str(m_pSelectedSettlement->m_IndustrialLevel) + "/" + Num2Str(m_pSelectedSettlement->m_MaxIndLevel));
			SettlementDetailCells[DEVLEVEL]->SetText( "Developmental infrastructure: " + Num2Str(m_pSelectedSettlement->m_DevelopmentLevel) + "/" + Num2Str(m_pSelectedSettlement->m_MaxDevLevel));
		}
		if(m_pSelectedSettlement->IsPopulationStarving())
			SettlementDetailCells[POP]->SetText( "Population: " + Num2Str(m_pSelectedSettlement->m_CurPop) + "/" + Num2Str(m_pSelectedSettlement->m_MaxPop) + "(starving)");
		else
			SettlementDetailCells[POP]->SetText( "Population: " + Num2Str(m_pSelectedSettlement->m_CurPop) + "/" + Num2Str(m_pSelectedSettlement->m_MaxPop));
		SettlementDetailCells[EMPTY_CELL]->SetText("");
		//column2
		//RESPOOL8
		/*
		short numResources = m_pSelectedSettlement->ResourcePool.size();
		for(unsigned short n=0;n<numResources;n++)
		{
			SettlementDetailCells[TraderCells(n+1)]->SetText(GetResourceAsStr((RESOURCE_TYPE)(n+1)) + " (" + m_pSelectedSettlement-> + "): " + Num2Str(m_pSelectedTrader->MyShip.StoredResources[(RESOURCE_TYPE)n+1]));
		}
		//column3
		//EXPPOOL1
		numResources = m_pSelectedSettlement->ExploitableResources.size();
		for(unsigned short n=0;n<numResources;n++)
		{
			SettlementDetailCells[TraderCells(n+1)]->SetText(GetResourceAsStr((RESOURCE_TYPE)(n+1)) + ": " + Num2Str(m_pSelectedTrader->MyShip.StoredResources[(RESOURCE_TYPE)n+1]));
		}*/
	}
	else
	{
		//make all cells blank
		for(unsigned short j=0;j<SettlementDetailCells.size();j++)
		{
			SettlementDetailCells[j]->SetText("");
		}
	}

	//update cells
	for(unsigned short j=0;j<SettlementDetailCells.size();j++)
	{
		SettlementDetailCells[j]->Update(1);
	}
}
