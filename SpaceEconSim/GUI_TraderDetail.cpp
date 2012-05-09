#include "GameInst.hpp"
#include "Trader.hpp"
#include "Helpers.hpp"
#include "GameHelpers.hpp"

void GameInst::SetupTraderDetailGUI()
{
	m_pDetailView->Add(m_pTraderView);
	//column 1
	m_pTraderView->Attach(m_pTraderName, sf::Rect<sf::Uint32>(1,1,1,1));
	m_pTraderView->Attach(m_pTraderWealth, sf::Rect<sf::Uint32>(1,2,1,1));
	m_pTraderView->Attach(m_pDecisiveness, sf::Rect<sf::Uint32>(1,3,1,1));
	m_pTraderView->Attach(m_pRiskTaker, sf::Rect<sf::Uint32>(1,4,1,1));
	m_pTraderView->Attach(m_pCautious, sf::Rect<sf::Uint32>(1,5,1,1));
	m_pTraderView->Attach(m_pAmbitious, sf::Rect<sf::Uint32>(1,6,1,1));
	m_pTraderView->Attach(m_pPride, sf::Rect<sf::Uint32>(1,7,1,1));
	m_pTraderView->Attach(m_pRestlessness, sf::Rect<sf::Uint32>(1,8,1,1));
	//column2
	m_pTraderView->Attach(m_pShipName, sf::Rect<sf::Uint32>(2,1,1,1));
	m_pTraderView->Attach(m_pFuel, sf::Rect<sf::Uint32>(2,2,1,1));
	m_pTraderView->Attach(m_pStorage, sf::Rect<sf::Uint32>(2,3,1,1));
	m_pTraderView->Attach(m_pMaintenance, sf::Rect<sf::Uint32>(2,4,1,1));
	m_pTraderView->Attach(m_pSpeed, sf::Rect<sf::Uint32>(2,5,1,1));
	m_pTraderView->Attach(m_pRange, sf::Rect<sf::Uint32>(2,6,1,1));
	m_pTraderView->Attach(m_pLocation, sf::Rect<sf::Uint32>(2,7,1,1));
	m_pTraderView->Attach(m_pDestination, sf::Rect<sf::Uint32>(2,8,1,1));
	//column3
	for(unsigned short n=0;n<8;n++)
	{
		m_pTraderView->Attach(StorageSlots[n], sf::Rect<sf::Uint32>(3,n+1,1,1) );
	}
}

void GameInst::UpdateTraderDetailGUI()
{
	if(m_pSelectedTrader)
	{
		m_pTraderName->SetText(m_pSelectedTrader->Name);
		m_pTraderWealth->SetText( Num2Str(m_pSelectedTrader->Money));
		m_pDecisiveness->SetText( Num2Str(m_pSelectedTrader->Decisiveness));
		m_pRiskTaker->SetText( Num2Str(m_pSelectedTrader->RiskTaker));
		m_pCautious->SetText( Num2Str(m_pSelectedTrader->Caution));
		m_pAmbitious->SetText( Num2Str(m_pSelectedTrader->Ambition));
		m_pPride->SetText( Num2Str(m_pSelectedTrader->Pride));
		m_pRestlessness->SetText( Num2Str(m_pSelectedTrader->Restlessness));
		//
		m_pShipName->SetText( std::string(m_pSelectedTrader->Ship.Name + " (" + Num2Str(m_pSelectedTrader->Ship.Type) + ")"));
		m_pFuel->SetText( Num2Str(m_pSelectedTrader->Ship.FuelStored) + "/" + Num2Str(m_pSelectedTrader->Ship.FuelMax));
		m_pStorage->SetText( Num2Str(m_pSelectedTrader->Ship.StorageUsed) + "/" + Num2Str(m_pSelectedTrader->Ship.StorageMax));
		m_pMaintenance->SetText( Num2Str(m_pSelectedTrader->Ship.MaintLevel) + "/" + Num2Str(m_pSelectedTrader->Ship.MaintMax));
		m_pSpeed->SetText( Num2Str(m_pSelectedTrader->Ship.Speed));
		m_pRange->SetText( Num2Str(m_pSelectedTrader->Ship.GetRange()));
		m_pLocation->SetText( Num2Str(m_pSelectedTrader->LocationUID));
		m_pDestination->SetText( Num2Str(m_pSelectedTrader->DestinationUID));
		//
		short numResources = m_pSelectedTrader->Ship.StoredResources.size();
		for(unsigned short n=0;n<numResources;n++)
		{
			StorageSlots[n]->SetText(GetResourceAsStr((RESOURCE_TYPE)(n+1)) + ": " + Num2Str(m_pSelectedTrader->Ship.StoredResources[(RESOURCE_TYPE)n+1]));
		}
		for(unsigned short n=8-numResources;n<8;n++)
		{
			StorageSlots[n]->SetText("");
		}
	}
	else
	{
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
	}
}
