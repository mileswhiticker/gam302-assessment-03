#include <SFGUI/SFGUI.hpp>

#include "SceneManager.hpp"
#include "Renderer.hpp"
#include "ResourceManager.hpp"
#include "GUIManager.hpp"

#include "MainMenu.hpp"
#include "OptionsMenu.hpp"
#include "GameInst.hpp"

enum SceneInd
{
	SCENE_MAINMENU = 0,
	SCENE_OPTIONSMENU,
	SCENE_GAMEINST
};

SceneManager::SceneManager(GUIManager& a_GUIMgr, ResourceManager& a_ResMgr, Renderer& a_Renderer)
:	m_ResMgr(a_ResMgr)
,	m_GUIMgr(a_GUIMgr)
,	m_Renderer(a_Renderer)
//
,	m_pCurScene(NULL)
{
	//sfg::WeakPtr<sfg::Desktop> pDesktop = m_GUIMgr.GetDesktop();
	//--------------- main menu ---------------//

	//scene
	m_pScenes.push_back(new Scene(m_GUIMgr));
	Backgrounds.push_back(new sf::Sprite());
	a_ResMgr.CreateSprite("media/menubackground[1920x1080].jpg", &Backgrounds.back());
	m_pScenes.back()->SetBackground(Backgrounds.back());

	//widgets
	m_GUIMgr.CreateNewWindow();
	//sfg::Window::Ptr window( sfg::Window::Create() );
	//pDesktop->Add(window);
	//sfg::Button::Ptr quit_button( sfg::Button::Create( "Quit" ) );
	//pDesktop->Add(quit_button);
	//quit_button->OnLeftClick.Connect( &DesktopExample::OnFrontClick, this );
	
	//scale bg to fit the screen
	sf::FloatRect bgSize = Backgrounds.back()->getLocalBounds();
	sf::Vector2f screenDim = m_Renderer.GetWindowDim();
	float scalar = screenDim.x/bgSize.width;
	if(scalar < screenDim.y/bgSize.height)
		scalar = screenDim.y/bgSize.height;
	Backgrounds.back()->setScale(scalar, scalar);
	
	//widgets
	//sfg::Button::Ptr quit_button( sfg::Button::Create( "Quit" ) );
	//quit_button->OnLeftClick.Connect( &DesktopExample::OnFrontClick, this );

	//--------------- options menu ---------------//
	m_pScenes.push_back(new Scene(m_GUIMgr));
	Backgrounds.push_back(new sf::Sprite());
	m_pScenes.back()->SetBackground(Backgrounds.back());

	//--------------- application screen ---------------//
	m_pScenes.push_back(new Scene(m_GUIMgr));
	Backgrounds.push_back(new sf::Sprite());
	a_ResMgr.CreateSprite("media/starry[1280x853].bmp", &Backgrounds.back());
	m_pScenes.back()->SetBackground(Backgrounds.back());

	//scale bg to fit the screen
	bgSize = Backgrounds.back()->getLocalBounds();
	scalar = screenDim.x/bgSize.width;
	if(scalar < screenDim.y/bgSize.height)
		scalar = screenDim.y/bgSize.height;
	Backgrounds.back()->setScale(scalar, scalar);

	EnableSceneByID(SCENE_MAINMENU);
	//m_GUIMgr.CreateNewWindow(sf::Vector2f(0.1f,0.1f), sf::Vector2f(0.2f,0.2f));
}

SceneManager::~SceneManager()
{
	//
}

bool SceneManager::EnableSceneByID(unsigned short s_SceneID)
{
	if(s_SceneID < m_pScenes.size())
	{
		m_pCurScene = m_pScenes[s_SceneID];
		m_Renderer.SetBackground(m_pCurScene->GetBackground());
		return true;
	}
	return false;
}
