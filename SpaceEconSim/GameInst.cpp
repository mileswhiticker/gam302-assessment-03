#include "GameInst.hpp"
#include "Game.hpp"
#include "GUIManager.hpp"
#include "Helpers.hpp"

GameInst::GameInst(GUIManager& a_GUIMgr)
:	Scene(a_GUIMgr)
,	m_pGame(new Game())
,	m_Running(false)
,	m_pQuitMenuButton(sfg::Button::Create("Quit to Main Menu"))
,	m_CurView(VIEW_TRADER)
	//
,	m_pDetailView(sfg::Window::Create(2))		//sfg::Window::Style::BACKGROUND
,	m_pListView(sfg::Notebook::Create())
	//
,	m_pAnnouncementList(sfg::Window::Create(2))
,	m_pTraderList(sfg::Window::Create(2))
,	m_pCompanyList(sfg::Window::Create(2))
,	m_pSettlementList(sfg::Window::Create(2))
,	m_pSystemList(sfg::Window::Create(2))
	//
,	m_pCompanyView(sfg::Window::Create(2))
,	m_pSettlementView(sfg::Window::Create(2))
,	m_pSystemView(sfg::Window::Create(2))
	//
,	m_pTraderView(sfg::Table::Create())
,	m_pSelectedTrader(NULL)
	//column1
,	m_pTraderName(sfg::Label::Create("m_pTraderName"))
,	m_pTraderWealth(sfg::Label::Create("m_pTraderWealth"))
,	m_pDecisiveness(sfg::Label::Create("m_pDecisiveness"))
,	m_pRiskTaker(sfg::Label::Create("m_pRiskTaker"))
,	m_pCautious(sfg::Label::Create("m_pCautious"))
,	m_pAmbitious(sfg::Label::Create("m_pAmbitious"))
,	m_pPride(sfg::Label::Create("m_pPride"))
,	m_pRestlessness(sfg::Label::Create("m_pRestlessness"))
	//column2
,	m_pShipName(sfg::Label::Create("m_pShipName"))
,	m_pFuel(sfg::Label::Create("m_pFuel"))
,	m_pStorage(sfg::Label::Create("m_pStorage"))
,	m_pMaintenance(sfg::Label::Create("m_pMaintenance"))
,	m_pSpeed(sfg::Label::Create("m_pSpeed"))
,	m_pRange(sfg::Label::Create("m_pRange"))
,	m_pLocation(sfg::Label::Create("m_pLocation"))
,	m_pDestination(sfg::Label::Create("m_pDestination"))
{
	//column3
	for(unsigned short i=0;i<8;i++)
	{
		StorageSlots.push_back(sfg::Label::Create("storage slot " + Num2Str(i+1)));
	}
	//setup gui
	sf::Vector2f windowDim = m_GUIMgr.GetWindowDim();
	sf::FloatRect allocRect;
	//double invHeightScalar = 10;
	//double invWidthScalar = 5;
	
	//quit to menu button
	//sfg::Context::Get().GetEngine().SetProperty("Button", "FontSize", 20.0f);
	m_pQuitMenuButton->SetRequisition( sf::Vector2f(windowDim.x / 20, windowDim.y / 20) );
	allocRect = m_pQuitMenuButton->GetAllocation();
	m_pQuitMenuButton->SetPosition( sf::Vector2f(5, 5) );
	//m_pListView->OnLeftClick.Connect(&GameInst::DummyFunction, this);
	//m_pListView->OnMouseLeftPress.Connect(&GameInst::DummyFunction, this);
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

	//trader detail view
	SetupTraderDetailGUI();
	
	//company detail view
	SetupCompanyDetailGUI();
	
	//settlement detail view
	SetupSettlementDetailGUI();
	
	//star system detail view
	SetupSystemDetailGUI();
}

bool GameInst::Start()
{
	if(m_pGame->CheckInitialised())
	{
		m_Running = true;
		return true;
	}
	m_pGame->CreateNewWorld();
	m_Running = true;
	return false;
}

void GameInst::Stop()
{
	m_Running = false;
}

void GameInst::Update(float a_dt)
{
	//run the game update function... lotta shit happens here
	if(m_Running)
	{
		m_pGame->Update(a_dt);
		switch(m_CurView)
		{
		case(VIEW_TRADER):
			{
				UpdateTraderDetailGUI();
				break;
			}
		case(VIEW_COMPANY):
			{
				UpdateCompanyDetailGUI();
				break;
			}
		case(VIEW_SETTLEMENT):
			{
				UpdateSettlementDetailGUI();
				break;
			}
		case(VIEW_SYSTEM):
			{
				UpdateSystemDetailGUI();
				break;
			}
		}
	}

	//update the gui
}

void GameInst::UpdateGUISizes()
{
	//
}

void GameInst::ShowDetailView(DETAIL_VIEW a_ViewType)
{
	//remove the previous detailed view, if there is one
	sfg::Widget::Ptr child = m_pDetailView->GetChild();
	if(child)
	{
		m_pDetailView->Remove(child);
	}
	//add a new detailed view, if there is one
	switch(a_ViewType)
	{
	case(VIEW_TRADER):
		{
			m_pDetailView->Add(m_pTraderView);
			break;
		}
	case(VIEW_COMPANY):
		{
			m_pDetailView->Add(m_pCompanyView);
			break;
		}
	case(VIEW_SETTLEMENT):
		{
			m_pDetailView->Add(m_pSettlementView);
			break;
		}
	case(VIEW_SYSTEM):
		{
			m_pDetailView->Add(m_pSystemView);
			break;
		}
	}
	m_CurView = a_ViewType;
}
