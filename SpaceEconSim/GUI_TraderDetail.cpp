#include "GameInst.hpp"
#include "Trader.hpp"
#include "Helpers.hpp"
#include "GameHelpers.hpp"

void GameInst::SetupTraderDetailGUI()
{
	//create windows
	m_pTraderView = sfg::Table::Create();
	m_pSelectedTrader = NULL;

	//create table cells
	for(unsigned short i=0;i<3;i++)
	{
		//StorageSlots.push_back(sfg::Label::Create("storage slot " + Num2Str(i+1)));
		for(unsigned short j=0;j<8;j++)
		{
			TraderDetailCells.push_back(sfg::Label::Create("trader detail cell " + Num2Str(8*i + j + 1)));
			m_pTraderView->Attach(TraderDetailCells.back(), sf::Rect<sf::Uint32>(i + 1, j + 1, 1, 1));
		}
	}
}

void GameInst::UpdateTraderDetailGUI()
{
	if(m_pSelectedTrader && m_CurView == VIEW_TRADER)
	{
		//column1
		TraderDetailCells[NAME]->SetText( "Trader name: " + m_pSelectedTrader->Name);
		TraderDetailCells[WEALTH]->SetText( "Wealth: $" + Num2Str(m_pSelectedTrader->Money));
		TraderDetailCells[DECISIVENESS]->SetText( "Decisiveness: " + Num2Str(m_pSelectedTrader->Decisiveness));
		TraderDetailCells[RISKTAKER]->SetText( "Risk Taker: " + Num2Str(m_pSelectedTrader->RiskTaker));
		TraderDetailCells[CAUTIOUS]->SetText( "Catiousness: " + Num2Str(m_pSelectedTrader->Caution));
		TraderDetailCells[AMBITIOUS]->SetText( "Ambition: " + Num2Str(m_pSelectedTrader->Ambition));
		TraderDetailCells[PRIDE]->SetText( "Pride: " + Num2Str(m_pSelectedTrader->Pride));
		TraderDetailCells[RESTLESSNESS]->SetText( "Restlessness: " + Num2Str(m_pSelectedTrader->Restlessness));
		//column2
		TraderDetailCells[SHIPNAME]->SetText( "Ship name: " + std::string( m_pSelectedTrader->MyShip.Name + " (" + GetShipTypeAsStr(m_pSelectedTrader->MyShip.MyType) + ")") );
		TraderDetailCells[FUEL]->SetText( "Fuel stores: " + Num2Str(m_pSelectedTrader->MyShip.FuelStored) + "/" + Num2Str(m_pSelectedTrader->MyShip.FuelMax));
		TraderDetailCells[STORAGE]->SetText( "Used storage space: " + Num2Str(m_pSelectedTrader->MyShip.StorageUsed) + "/" + Num2Str(m_pSelectedTrader->MyShip.StorageMax));
		TraderDetailCells[MAINTENANCE]->SetText( "Maintenance level: " + Num2Str(m_pSelectedTrader->MyShip.MaintLevel) + "/" + Num2Str(m_pSelectedTrader->MyShip.MaintMax));
		TraderDetailCells[SPEED]->SetText( "Ship speed: " + Num2Str(m_pSelectedTrader->MyShip.Speed));
		TraderDetailCells[RANGE]->SetText( "Travel range: " + Num2Str(m_pSelectedTrader->MyShip.GetRange()));
		TraderDetailCells[LOCATION]->SetText( "Current location: " + Num2Str(m_pSelectedTrader->LocationUID));
		TraderDetailCells[DESTINATION]->SetText( "Destination: " + Num2Str(m_pSelectedTrader->DestinationUID));
		//column3
		short numResources = m_pSelectedTrader->MyShip.StoredResources.size();
		for(unsigned short n=0;n<numResources;n++)
		{
			TraderDetailCells[TraderCells(n)]->SetText(GetResourceAsStr((RESOURCE_TYPE)(n+1)) + ": " + Num2Str(m_pSelectedTrader->MyShip.StoredResources[(RESOURCE_TYPE)n+1]));
		}

		/*
		m_pTraderName->SetText( "Trader name: " + m_pSelectedTrader->Name);
		m_pTraderWealth->SetText( "Wealth: $" + Num2Str(m_pSelectedTrader->Money));
		m_pDecisiveness->SetText( "Decisiveness: " + Num2Str(m_pSelectedTrader->Decisiveness));
		m_pRiskTaker->SetText( "Risk Taker: " + Num2Str(m_pSelectedTrader->RiskTaker));
		m_pCautious->SetText( "Catiousness: " + Num2Str(m_pSelectedTrader->Caution));
		m_pAmbitious->SetText( "Ambition: " + Num2Str(m_pSelectedTrader->Ambition));
		m_pPride->SetText( "Pride: " + Num2Str(m_pSelectedTrader->Pride));
		m_pRestlessness->SetText( "Restlessness: " + Num2Str(m_pSelectedTrader->Restlessness));
		//
		m_pShipName->SetText( "Ship name: " + std::string( m_pSelectedTrader->MyShip.Name + " (" + GetShipTypeAsStr(m_pSelectedTrader->MyShip.MyType) + ")") );
		m_pFuel->SetText( "Fuel stores: " + Num2Str(m_pSelectedTrader->MyShip.FuelStored) + "/" + Num2Str(m_pSelectedTrader->MyShip.FuelMax));
		m_pStorage->SetText( "Used storage space: " + Num2Str(m_pSelectedTrader->MyShip.StorageUsed) + "/" + Num2Str(m_pSelectedTrader->MyShip.StorageMax));
		m_pMaintenance->SetText( "Maintenance level: " + Num2Str(m_pSelectedTrader->MyShip.MaintLevel) + "/" + Num2Str(m_pSelectedTrader->MyShip.MaintMax));
		m_pSpeed->SetText( "Ship speed: " + Num2Str(m_pSelectedTrader->MyShip.Speed));
		m_pRange->SetText( "Travel range: " + Num2Str(m_pSelectedTrader->MyShip.GetRange()));
		m_pLocation->SetText( "Current location: " + Num2Str(m_pSelectedTrader->LocationUID));
		m_pDestination->SetText( "Destination: " + Num2Str(m_pSelectedTrader->DestinationUID));
		//
		short numResources = m_pSelectedTrader->MyShip.StoredResources.size();
		for(unsigned short n=0;n<numResources;n++)
		{
			StorageSlots[n]->SetText(GetResourceAsStr((RESOURCE_TYPE)(n+1)) + ": " + Num2Str(m_pSelectedTrader->MyShip.StoredResources[(RESOURCE_TYPE)n+1]));
		}
		for(unsigned short n=8-numResources;n<8;n++)
		{
			StorageSlots[n]->SetText("");
		}
		*/
	}
	else
	{
		for(unsigned short i=0;i<TraderDetailCells.size();i++)
		{
			TraderDetailCells[TraderCells(i)]->SetText("");
		}
		/*
		//column 1
		m_pTraderName->SetText("");
		m_pTraderWealth->SetText("");
		m_pDecisiveness->SetText("");
		m_pRiskTaker->SetText("");
		m_pCautious->SetText("");
		m_pAmbitious->SetText("");
		m_pPride->SetText("");
		m_pRestlessness->SetText("");
		//column 2
		m_pShipName->SetText("");
		m_pFuel->SetText("");
		m_pStorage->SetText("");
		m_pMaintenance->SetText("");
		m_pSpeed->SetText("");
		m_pRange->SetText("");
		m_pLocation->SetText("");
		m_pDestination->SetText("");
		//column 3
		for(unsigned short n=0;n<8;n++)
		{
			StorageSlots[n]->SetText("");
		}
		*/
	}

	//update the cells
	sfg::Container::WidgetsList cells = m_pTraderView->GetChildren();
	for(unsigned short n=0;n<cells.size();n++)
	{
		cells[n]->Update(0);
	}
}
