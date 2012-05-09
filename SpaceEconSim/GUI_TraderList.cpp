#include "GameInst.hpp"
#include "Trader.hpp"
#include "Helpers.hpp"
#include "GameHelpers.hpp"
#include <map>

void GameInst::AddTraderToList(Trader* a_pTrader)
{
	TraderListItems.insert( std::pair<int, sfg::Label::Ptr>(a_pTrader->TraderUID, sfg::Label::Create(a_pTrader->Name + " (" + GetShipTypeAsStr(a_pTrader->MyShip.MyType) + "): $" + Num2Str(a_pTrader->Money)) ) );
	//TraderListItems[a_Trader.TraderUID] = sfg::Label::Create(a_Trader.Name + " (" + GetShipTypeAsStr(a_Trader.MyShip.MyType) + "): $" + Num2Str(a_Trader.Money) );
	m_pTraderList->Attach( TraderListItems[a_pTrader->TraderUID], sf::Rect<sf::Uint32>(1,TraderListItems.size(),1,1) );
	TraderListItems[a_pTrader->TraderUID]->OnLeftClick.Connect(&Trader::SelectMe, a_pTrader);
}

void GameInst::RemoveTraderFromList(Trader& a_Trader)
{
	//
}
