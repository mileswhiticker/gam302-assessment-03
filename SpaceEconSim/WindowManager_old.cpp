#include "WindowManager.hpp"
#include "SceneManager.hpp"
//#include "ChatManager.hpp"

#include <iostream>

#include <CEGUI/Cegui.h>

typedef CEGUI::UVector2 UVec2;
typedef CEGUI::UDim UDim1;

WindowManager::WindowManager()
:	m_IsQuittingNextUpdate(false)
,	m_pRootWindow(NULL)
,	m_pIPInput(NULL)
{
	//
}
//m_pMainMenu(new Scene())
void WindowManager::Init()
{
	//setup cegui
	CEGUI::SchemeManager::getSingleton().create("WindowsLook.scheme");
	CEGUI::WindowManager& wmgr = CEGUI::WindowManager::getSingleton();

	//setup a root window
	try
	{
		m_pRootWindow = wmgr.loadWindowLayout( "Main.layout" );
	}
	catch(CEGUI::Exception &e)
	{
		std::cout << "Error loading layout: " << e.getMessage().c_str() << std::endl;
	}
	CEGUI::System::getSingleton().setGUISheet( m_pRootWindow );

	//setup button event handling
	/*
	CEGUI::PushButton* FindServerButton = (CEGUI::PushButton*)m_pRootWindow->getChild("Root/FindServer");
	FindServerButton->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&WindowManager::FindServer,this));
	//
	CEGUI::PushButton* QuitButton = (CEGUI::PushButton*)m_pRootWindow->getChild("Root/Quit");
	QuitButton->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&WindowManager::Quit,this));
	//
	CEGUI::PushButton* HostButton = (CEGUI::PushButton*)m_pRootWindow->getChild("Root/HostServer");
	HostButton->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&WindowManager::HostNewServer,this));
	//
	CEGUI::PushButton* DisconnectButton = (CEGUI::PushButton*)m_pRootWindow->getChild("Root/Disconnect");
	DisconnectButton->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&WindowManager::DisconnectFromServer,this));
	//
	CEGUI::PushButton* BackButton = (CEGUI::PushButton*)m_pRootWindow->getChild("Root/Back");
	BackButton->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&WindowManager::Back,this));
	//
	CEGUI::PushButton* DirectConnectButton = (CEGUI::PushButton*)m_pRootWindow->getChild("Root/DirectConnect");
	DirectConnectButton->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&WindowManager::DirectConnect,this));
	//
	CEGUI::PushButton* ConnectToFirstAvailableButton = (CEGUI::PushButton*)m_pRootWindow->getChild("Root/ConnectToFirstAvailable");
	ConnectToFirstAvailableButton->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&WindowManager::ConnectToFirstAvailable,this));

	//tell scenemanager about background image
	SceneManager::GetInstance().SetBackgroundImage(m_pRootWindow->getChild("Root/Background"));

	//setup scenes
	std::vector<CEGUI::Window*> menuElements;
	menuElements.push_back(m_pRootWindow->getChild("Root/Title"));
	menuElements.push_back(m_pRootWindow->getChild("Root/FindServer"));
	menuElements.push_back(m_pRootWindow->getChild("Root/HostServer"));
	menuElements.push_back(m_pRootWindow->getChild("Root/Quit"));
	SceneManager::GetInstance().SetMainMenuElements(menuElements);
	
	std::vector<CEGUI::Window*> chatElements;
	chatElements.push_back(m_pRootWindow->getChild("Root/Disconnect"));
	chatElements.push_back(m_pRootWindow->getChild("Root/ChatInput"));
	chatElements.push_back(m_pRootWindow->getChild("Root/ChatOutput"));
	chatElements.push_back(m_pRootWindow->getChild("Root/PeerList"));
	SceneManager::GetInstance().SetChatClientElements(chatElements);
	
	std::vector<CEGUI::Window*> findserverElements;
	findserverElements.push_back(m_pRootWindow->getChild("Root/FindServerTitle"));
	findserverElements.push_back(m_pRootWindow->getChild("Root/IPInput"));
	findserverElements.push_back(m_pRootWindow->getChild("Root/DirectConnect"));
	findserverElements.push_back(m_pRootWindow->getChild("Root/Back"));
	findserverElements.push_back(m_pRootWindow->getChild("Root/ConnectToFirstAvailable"));
	SceneManager::GetInstance().SetFindServerElements(findserverElements);
	*/

	SceneManager::GetInstance().GotoMainMenu();

	/*
	//tell managers about relevant input / output elements
	ChatManager::GetInstance().SetChatOutput( (CEGUI::Listbox*)m_pRootWindow->getChild("Root/ChatOutput") );
	ChatManager::GetInstance().SetChatInput( (CEGUI::Editbox*)m_pRootWindow->getChild("Root/ChatInput") );

	//NetworkManager::GetInstance().SetPeerList( (CEGUI::Listbox*)m_pRootWindow->getChild("Root/PeerList") );

	m_pIPInput = (CEGUI::Editbox*)m_pRootWindow->getChild("Root/IPInput");
	*/
}

//button proc callbacks
bool WindowManager::Quit(const CEGUI::EventArgs& args)
{
	m_IsQuittingNextUpdate = true;
	//
	return true;
}

bool WindowManager::CheckQuitNextUpdate()
{
	return m_IsQuittingNextUpdate;
}

bool WindowManager::GotoMainMenu(const CEGUI::EventArgs& args)
{
	SceneManager::GetInstance().GotoMainMenu();
	return true;
}
