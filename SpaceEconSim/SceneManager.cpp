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
	//--------------- main menu ---------------//

	//scene
	m_pScenes.push_back(new Scene(m_GUIMgr));
	Backgrounds.push_back(new sf::Sprite());
	a_ResMgr.CreateSprite("media/menubackground[1920x1080].jpg", &Backgrounds.back());
	m_pScenes.back()->SetBackground(Backgrounds.back());

	//widgets
	sfg::Button::Ptr quit_button( sfg::Button::Create( "Quit" ) );
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
