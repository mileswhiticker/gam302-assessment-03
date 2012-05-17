#include "GameInst.hpp"
#include "Game.hpp"
#include "GUIManager.hpp"
#include "Helpers.hpp"
#include "Trader.hpp"

#include "Planet.hpp"
#include "AsteroidBelt.hpp"

GameInst::GameInst(GUIManager& a_GUIMgr)
:	Scene(a_GUIMgr)
,	m_pGame(new Game())
,	m_Running(false)
,	m_pQuitMenuButton(sfg::Button::Create("Quit to Main Menu"))
,	m_CurView(INVALID_VIEW)
	//
,	m_pDetailView(sfg::Window::Create(2))		//sfg::Window::Style::BACKGROUND
,	m_pListView(sfg::Notebook::Create())
	//
,	m_pAnnouncementList(sfg::Table::Create())
,	m_pTraderList(sfg::Table::Create())
,	m_pCompanyList(sfg::Table::Create())
,	m_pSettlementList(sfg::Table::Create())
,	m_pSystemList(sfg::Table::Create())
	//
{
	//grab the screen dimensions
	sf::Vector2f windowDim = m_GUIMgr.GetWindowDim();

	//to handle button presses and the like
	m_pSelectListener = new SelectListener(*this);
	
	/** Create Adjustment.
		* @param value Current value.
		* @param lower Minimum value.
		* @param upper Maximum value.
		* @param minor_step Minor change value (such as clicking on arrow button).
		* @param major_step Major change value (such as clicking on the scroll area).
		* @param page_size Page size (how many entries are visible / slider size).
		* @return Adjustment.
		*/

	//add a systemlist scrollbar
	/*sfg::Scrollbar::Ptr systemScrollBar = sfg::Scrollbar::Create(sfg::Scale::VERTICAL);
	m_pSystemList->Attach(systemScrollBar, sf::Rect<unsigned int>(1,1,1,1), 0, 0);
	sfg::Adjustment::Ptr adjustment = systemScrollBar->GetAdjustment();
	systemScrollBar->SetRequisition( sf::Vector2f( 0.f, windowDim.y/2 ) );

	// Tune the adjustment parameters.
	adjustment->SetLower( 20.f );
	adjustment->SetUpper( 100.f );

	// How much it should change when clicked on the stepper.
	adjustment->SetMinorStep( 1.f );

	// How much it should change when clicked on the trough.
	adjustment->SetMajorStep( 5.f );*/

	//add some random systems for testing
	AddSystemToList(new StarSystem(*m_pGame, m_pSelectListener));
	AddSystemToList(new StarSystem(*m_pGame, m_pSelectListener));
	AddSystemToList(new StarSystem(*m_pGame, m_pSelectListener));
	AddSystemToList(new StarSystem(*m_pGame, m_pSelectListener));
	AddSystemToList(new StarSystem(*m_pGame, m_pSelectListener));
	AddSystemToList(new StarSystem(*m_pGame, m_pSelectListener));

	//add some random traders for testing
	AddTraderToList(new Trader(m_pSelectListener));
	AddTraderToList(new Trader(m_pSelectListener));
	AddTraderToList(new Trader(m_pSelectListener));
	AddTraderToList(new Trader(m_pSelectListener));
	AddTraderToList(new Trader(m_pSelectListener));
	AddTraderToList(new Trader(m_pSelectListener));
	AddTraderToList(new Trader(m_pSelectListener));

	//add some random settlements for testing
	/*HabitableObject* pSettlement = new Planet(m_pSelectListener);
	AddSettlementToList(pSettlement);
	pSettlement = new Planet(m_pSelectListener);
	AddSettlementToList(pSettlement);
	pSettlement = new Planet(m_pSelectListener);
	AddSettlementToList(pSettlement);
	pSettlement = (HabitableObject*)(new AsteroidBelt(m_pSelectListener));
	AddSettlementToList(pSettlement);
	pSettlement = (HabitableObject*)(new AsteroidBelt(m_pSelectListener));
	AddSettlementToList(pSettlement);*/

	//setup gui
	sf::FloatRect allocRect;
	//double invHeightScalar = 10;
	//double invWidthScalar = 5;
	
	//quit to menu button
	//sfg::Context::Get().GetEngine().SetProperty("Button", "FontSize", 20.0f);
	m_pQuitMenuButton->SetRequisition( sf::Vector2f(windowDim.x / 20, windowDim.y / 20) );
	allocRect = m_pQuitMenuButton->GetAllocation();
	m_pQuitMenuButton->SetPosition( sf::Vector2f(5, 5) );
	m_pQuitMenuButton->Show(false);
	m_GUIMgr.AddWidget(m_pQuitMenuButton);
	Widgets.push_back(m_pQuitMenuButton);

	//listview
	m_pListView->AppendPage( m_pAnnouncementList, sfg::Label::Create( "Announcements" ) );
	m_pListView->AppendPage( m_pTraderList, sfg::Label::Create( "Traders" ) );
	m_pListView->AppendPage( m_pCompanyList, sfg::Label::Create( "Companies" ) );
	m_pListView->AppendPage( m_pSettlementList, sfg::Label::Create( "Inhabited Settlements" ) );
	m_pListView->AppendPage( m_pSystemList, sfg::Label::Create( "Star Systems" ) );
	m_pListView->SetRequisition( sf::Vector2f( windowDim.x, (3 * windowDim.y / 5) - (windowDim.y / 20 + 11) ) );
	//
	allocRect = m_pListView->GetAllocation();
	m_pListView->SetPosition( sf::Vector2f(0, windowDim.y / 20 + 10) );
	m_pListView->Show(false);
	m_GUIMgr.AddWidget(m_pListView);
	Widgets.push_back(m_pListView);
	
	//detail view
	//
	m_pDetailView->SetRequisition( sf::Vector2f( windowDim.x, (2 * windowDim.y / 5) ) );
	allocRect = m_pDetailView->GetAllocation();
	m_pDetailView->SetPosition( sf::Vector2f(0, 3 * windowDim.y / 5) );
	m_pDetailView->Show(false);
	m_GUIMgr.AddWidget(m_pDetailView);
	Widgets.push_back(m_pDetailView);

	SetupTraderDetailGUI();
	SetupCompanyDetailGUI();
	SetupSettlementDetailGUI();
	SetupSystemDetailGUI();
}

bool GameInst::Start()
{
	if(m_pGame->CheckInitialised())
	{
		m_Running = true;
		return true;
	}
	m_pGame->CreateNewWorld(m_pSelectListener);

	//get the traders
	for(unsigned short n = 0;n < m_pGame->AllTraders.size(); n++)
	{
		AddTraderToList(m_pGame->AllTraders[n]);
	}

	//get systems and inhabited planets
	for(unsigned short n=0;n<m_pGame->StarSystems.size();n++)
	{
		AddSystemToList(&m_pGame->StarSystems[n]);
		for(unsigned short m=0; m<m_pGame->StarSystems[n].Planets.size(); m++)
		{
			Planet* curPlanet = &m_pGame->StarSystems[n].Planets[m];
			if(curPlanet->m_Inhabited)
				AddSettlementToList(curPlanet);
		}
	}
	//
	m_Running = true;
	return false;
}

void GameInst::Stop()
{
	m_Running = false;
	m_CurView = INVALID_VIEW;
	UpdateTraderDetailGUI();
	UpdateCompanyDetailGUI();
	UpdateSettlementDetailGUI();
	UpdateSystemDetailGUI();
}

void GameInst::Update(float a_dt)
{
	//run the game update function... lotta shit happens here
	int curListView = m_pListView->GetCurrentPage();
	if(m_Running)
	{
		m_pGame->Update(a_dt);
		//
		UpdateTraderDetailGUI();
		UpdateCompanyDetailGUI();
		UpdateSettlementDetailGUI();
		UpdateSystemDetailGUI();
	}
}

void GameInst::UpdateGUISizes()
{
	//
}

void GameInst::ShowDetailView(GameInst::DetailView a_ViewType)
{
	//remove the previous detailed view, if there is one
	sfg::Widget::Ptr child = m_pDetailView->GetChild();
	if(child)
	{
		m_pDetailView->Remove(child);
		child->Show(false);
	}

	//add a new detailed view, if there is one
	switch(a_ViewType)
	{
	case(VIEW_TRADER):
		{
			m_pDetailView->Add(m_pTraderView);
			m_pTraderView->Show(true);
			break;
		}
	case(VIEW_COMPANY):
		{
			m_pDetailView->Add(m_pCompanyView);
			m_pCompanyView->Show(true);
			break;
		}
	case(VIEW_SETTLEMENT):
		{
			m_pDetailView->Add(m_pSettlementView);
			m_pSettlementView->Show(true);
			break;
		}
	case(VIEW_SYSTEM):
		{
			m_pDetailView->Add(m_pSystemView);
			m_pSystemView->Show(true);
			break;
		}
	}
	m_CurView = a_ViewType;
}

void GameInst::Select(void* a_pSelectee, SelectListener::Type a_SelectedType)
{
	switch(a_SelectedType)
	{
	case(SelectListener::LISTENER_TRADER):
		{
			if(a_pSelectee)
			{
				ShowDetailView(VIEW_TRADER);
				Trader* pTrader = (Trader*)a_pSelectee;
				m_pSelectedTrader = (Trader*)a_pSelectee;
			}
			break;
		}
	case(SelectListener::LISTENER_SETTLEMENT):
		{
			if(a_pSelectee)
			{
				ShowDetailView(VIEW_SETTLEMENT);
				HabitableObject* pObj = (HabitableObject*)a_pSelectee;
				m_pSelectedSettlement = (HabitableObject*)a_pSelectee;
			}
			break;
		}
	case(SelectListener::LISTENER_COMPANY):
		{
			break;
		}
	case(SelectListener::LISTENER_SYSTEM):
		{
			if(a_pSelectee)
			{
				ShowDetailView(VIEW_SYSTEM);
				m_pSelectedSystem = (StarSystem*)a_pSelectee;
			}
			break;
		}
	}
}
