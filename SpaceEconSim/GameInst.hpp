#ifndef GAME_INST_HPP
#define GAME_INST_HPP

#include "Scene.hpp"
#include "SelectListener.hpp"

#include <SFGUI/Button.hpp>
#include <SFGUI/Window.hpp>
#include <SFGUI/Notebook.hpp>
#include <SFGUI/Table.hpp>
#include <SFGUI/Label.hpp>

class Game;
class Trader;
struct Company;
class StarSystem;
class HabitableObject;
struct Announcement;

class GameInst : public Scene
{
public:
	GameInst(GUIManager& a_GUIMgr);
	bool Start();
	void Stop();
	virtual void Update(float a_dt);
	virtual void UpdateGUISizes();
	//
	sfg::Button::Ptr m_pQuitMenuButton;
	sfg::Notebook::Ptr m_pListView;
	sfg::Window::Ptr m_pDetailView;
	//
	void Select(void* a_pSelectee, SelectListener::Type a_SelectedType);
	//
	enum DetailView
	{
		INVALID_VIEW = 0,
		VIEW_TRADER,
		VIEW_COMPANY,
		VIEW_SETTLEMENT,
		VIEW_SYSTEM,
		END_VIEW
		//
	};
	//
private:
	//
	void ShowDetailView(GameInst::DetailView a_ViewType);
	GameInst::DetailView m_CurView;
	//
	bool m_Running;
	Game* m_pGame;
	SelectListener* m_pSelectListener;
	//
private:
	//trader views
	sfg::Table::Ptr m_pTraderList;
	std::map<int, sfg::Label::Ptr> TraderListItems;
	//
	enum TraderCells
	{
		//column1
		NAME = 0,
		WEALTH,
		DECISIVENESS,
		RISKTAKER,
		CAUTIOUS,
		AMBITIOUS,
		PRIDE,
		RESTLESSNESS,
		//column2
		SHIPNAME,
		FUEL,
		STORAGE,
		MAINTENANCE,
		SPEED,
		RANGE,
		LOCATION,
		DESTINATION,
		//column3
		SLOT1,
		SLOT2,
		SLOT3,
		SLOT4,
		SLOT5,
		SLOT6,
		SLOT7,
		SLOT8,
		//
		ENDCELL_TRADER
	};
	sfg::Table::Ptr m_pTraderView;
	std::vector<sfg::Label::Ptr> TraderDetailCells;
	//
	void AddTraderToList(Trader* a_pTrader);
	void RemoveTraderFromList(Trader& a_Trader);
	//
	void SetupTraderDetailGUI();
	void UpdateTraderDetailGUI();
	Trader* m_pSelectedTrader;
	//
private:
	//settlement views
	sfg::Table::Ptr m_pSettlementList;
	std::map<int, sfg::Label::Ptr> SettlementListItems;
	//
	enum SettlementCells
	{
		SETTLEMENTNAME = 0,
		SETTLEMENTTYPE,
		STARNAME,
		SETTLEMENTWEALTH,
		INDLEVEL,
		DEVLEVEL,
		POP,
		EMPTY_CELL,
		//
		RESPOOL1,
		RESPOOL2,
		RESPOOL3,
		RESPOOL4,
		RESPOOL5,
		RESPOOL6,
		RESPOOL7,
		RESPOOL8,
		//
		EXPPOOL1,
		EXPPOOL2,
		EXPPOOL3,
		EXPPOOL4,
		EXPPOOL5,
		EXPPOOL6,
		EXPPOOL7,
		EXPPOOL8,
		//
		ENDCELL_SETTLEMENT
	};
	sfg::Table::Ptr m_pSettlementView;
	std::vector<sfg::Label::Ptr> SettlementDetailCells;
	//
	void AddSettlementToList(HabitableObject* a_pSettlement);
	void RemoveSettlementFromList(HabitableObject& a_pSettlement);
	//
	void SetupSettlementDetailGUI();
	void UpdateSettlementDetailGUI();
	//
	HabitableObject* m_pSelectedSettlement;
	//
private:
	//company views
	sfg::Table::Ptr m_pCompanyList;
	void AddCompanyToList(Trader* a_pTrader);
	void RemoveCompanyFromList(Trader& a_Trader);
	
	//----- company detailed view
	void SetupCompanyDetailGUI();
	void UpdateCompanyDetailGUI();
	sfg::Window::Ptr m_pCompanyView;
	//
private:
	//announcement views
	sfg::Table::Ptr m_pAnnouncementList;
	void AddAnnouncementToList(Announcement* a_pAnnouncement);
	void RemoveAnnouncementFromList(Announcement* a_pAnnouncement);
	
	//----- announcement detailed view
	void SetupAnnouncementDetailGUI();
	void UpdateAnnouncementDetailGUI();
	sfg::Window::Ptr m_pAnnouncementView;
	//
private:
	//system views
	enum SystemCells
	{
		SYSTEMNAME = 0,
		NUMDEADPLANETS,
		NUMTERRAPLANETS,
		NUMGASPLANETS,
		//
		ENDCELL_SYSTEM
	};
	sfg::Table::Ptr m_pSystemList;
	std::map<int, sfg::Label::Ptr> SystemListItems;
	//
	sfg::Table::Ptr m_pSystemView;
	std::vector<sfg::Label::Ptr> SystemDetailCells;
	//
	void AddSystemToList(StarSystem* a_pSystem);
	void RemoveSystemFromList(StarSystem* a_pSystem);
	//
	void SetupSystemDetailGUI();
	void UpdateSystemDetailGUI();
	//
	StarSystem* m_pSelectedSystem;
};

#endif	//GAME_INST_HPP