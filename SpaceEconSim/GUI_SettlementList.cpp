#include "GameInst.hpp"
#include "HabitableObject.hpp"
#include "Helpers.hpp"
#include "GameHelpers.hpp"
#include <map>

void GameInst::AddSettlementToList(HabitableObject* a_pSettlement)
{
	std::pair<int, sfg::Label::Ptr> listItem = std::pair<int, sfg::Label::Ptr>( a_pSettlement->SettlementUID, sfg::Label::Create(a_pSettlement->m_Name + " (" + GetHabTypeAsStr(a_pSettlement->MyType) + "): $" + Num2Str(a_pSettlement->m_Money)) );
	SettlementListItems.insert(listItem);
	//TraderListItems[a_Trader.TraderUID] = sfg::Label::Create(a_Trader.Name + " (" + GetShipTypeAsStr(a_Trader.MyShip.MyType) + "): $" + Num2Str(a_Trader.Money) );
	m_pSettlementList->Attach( SettlementListItems[a_pSettlement->SettlementUID], sf::Rect<sf::Uint32>(1,SettlementListItems.size(),1,1) );
	SettlementListItems[a_pSettlement->SettlementUID]->OnLeftClick.Connect(&HabitableObject::SelectMe, a_pSettlement);
}

void GameInst::RemoveSettlementFromList(HabitableObject& a_Settlement)
{
	//
}
