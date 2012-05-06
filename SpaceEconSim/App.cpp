#include "App.hpp"
#include "Renderer.hpp"
#include "WindowManager.hpp"
#include "ResourceManager.hpp"
#include "SceneManager.hpp"

#include <iostream>

App::App(Renderer& a_Renderer, WindowManager& a_WindowMgr)
:	m_Renderer(a_Renderer)
,	m_WindowMgr(a_WindowMgr)
,	m_pResourceMgr(new ResourceManager())
,	m_pSceneMgr(new SceneManager(*m_pResourceMgr, m_Renderer))
	//
,	m_IsQuittingNextUpdate(false)
,	m_Initialized(false)
{
	//initialise window manager
	if(!m_WindowMgr.Init())
		m_IsQuittingNextUpdate = true;

	//initialise renderer
	if(!m_Renderer.Init())
		m_IsQuittingNextUpdate = true;

	//setup default background image
	//m_pResourceMgr->

	//
	m_Initialized = true;
}

bool App::Update(float a_Dt)
{
	//process
	//

	bool quit = m_IsQuittingNextUpdate;
	//render everything
	if(m_Renderer.Render(a_Dt))
		quit = true;

	//poll for window events
	m_WindowMgr.HandleEvents();

	//check if user has tried to close the application
	if(m_WindowMgr.CheckQuitNextUpdate())
		quit = true;

	return quit;
}

App::~App()
{
	//
}

bool App::CleanUp()
{
	if(m_Initialized)
	{
		m_Renderer.CleanUp();
		m_WindowMgr.CleanUp();
		//
		m_Initialized = false;
		return true;
	}
	return false;
}