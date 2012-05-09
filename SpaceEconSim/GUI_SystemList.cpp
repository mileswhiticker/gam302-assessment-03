#include "GameInst.hpp"
#include "StarSystem.hpp"
#include "Helpers.hpp"
#include "GameHelpers.hpp"
#include <map>

void GameInst::AddSystemToList(StarSystem* a_pSystem)
{
	std::pair<int, sfg::Label::Ptr> listItem = std::pair<int, sfg::Label::Ptr>( a_pSystem->SystemUID, sfg::Label::Create(a_pSystem->m_StarName) );
	SystemListItems.insert(listItem);
	m_pSystemList->Attach( SystemListItems[a_pSystem->SystemUID], sf::Rect<sf::Uint32>(1,SystemListItems.size(),1,1) );
	SystemListItems[a_pSystem->SystemUID]->OnLeftClick.Connect(&StarSystem::SelectMe, a_pSystem);
}

void GameInst::RemoveSystemFromList(StarSystem* a_pSystem)
{
	//
}
