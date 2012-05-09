#ifndef GAME_INST_HPP
#define GAME_INST_HPP

#include "Scene.hpp"
#include <SFGUI/Button.hpp>
#include <SFGUI/Window.hpp>
#include <SFGUI/Notebook.hpp>
#include <SFGUI/Table.hpp>
#include <SFGUI/Label.hpp>

class Game;
struct Trader;
struct Company;
class StarSystem;
class HabitableObject;

enum DETAIL_VIEW
{
	INVALID_VIEW = 0,
	VIEW_TRADER,
	VIEW_COMPANY,
	VIEW_SETTLEMENT,
	VIEW_SYSTEM,
	END_VIEW
	//
};

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
	sfg::Window::Ptr m_pAnnouncementList;
	sfg::Window::Ptr m_pTraderList;
	sfg::Window::Ptr m_pCompanyList;
	sfg::Window::Ptr m_pSettlementList;
	sfg::Window::Ptr m_pSystemList;
	//
	//
private:
	//----- game gui stuff -----//
	
	//trader detailed view
	void SetupTraderDetailGUI();
	void UpdateTraderDetailGUI();
	Trader* m_pSelectedTrader;
	sfg::Table::Ptr m_pTraderView;
	//column1
	sfg::Label::Ptr m_pTraderName;
	sfg::Label::Ptr m_pTraderWealth;
	sfg::Label::Ptr m_pDecisiveness;
	sfg::Label::Ptr m_pRiskTaker;
	sfg::Label::Ptr m_pCautious;
	sfg::Label::Ptr m_pAmbitious;
	sfg::Label::Ptr m_pPride;
	sfg::Label::Ptr m_pRestlessness;
	//column2
	sfg::Label::Ptr m_pShipName;
	sfg::Label::Ptr m_pFuel;
	sfg::Label::Ptr m_pStorage;
	sfg::Label::Ptr m_pMaintenance;
	sfg::Label::Ptr m_pSpeed;
	sfg::Label::Ptr m_pRange;
	sfg::Label::Ptr m_pLocation;
	sfg::Label::Ptr m_pDestination;
	//column3
	std::vector<sfg::Label::Ptr> StorageSlots;
	
	//company detailed view
	void SetupCompanyDetailGUI();
	void UpdateCompanyDetailGUI();
	sfg::Window::Ptr m_pCompanyView;
	
	//settlement detailed view
	void SetupSettlementDetailGUI();
	void UpdateSettlementDetailGUI();
	sfg::Window::Ptr m_pSettlementView;
	
	//system detailed view
	void SetupSystemDetailGUI();
	void UpdateSystemDetailGUI();
	sfg::Window::Ptr m_pSystemView;

	//
	void ShowDetailView(DETAIL_VIEW a_ViewType = INVALID_VIEW);
	DETAIL_VIEW m_CurView;
	//
	void DummyFunction();
	//
	bool m_Running;
	Game* m_pGame;
};

#endif	//GAME_INST_HPP