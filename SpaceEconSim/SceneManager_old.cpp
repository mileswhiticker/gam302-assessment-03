#include "SceneManager.hpp"
#include "Scene.hpp"

#include <CEGUI/CEGUIWindow.h>

#include <iostream>

SceneManager::SceneManager()
:	m_pMainMenu(NULL)
,	m_pFindServer(NULL)
,	m_pChatClient(NULL)
,	m_ppCurrentScene(&m_pMainMenu)
,	m_pBackground(NULL)
{
	//
}

void SceneManager::SetMainMenuElements(std::vector<CEGUI::Window*> a_pSceneElements)
{
	if(m_pMainMenu)
		delete m_pMainMenu;
	m_pMainMenu = new Scene(a_pSceneElements);
	m_pMainMenu->HideScene();
	//std::cout << "Main menu set and hidden" << std::endl;
}

void SceneManager::SetChatClientElements(std::vector<CEGUI::Window*> a_pSceneElements)
{
	if(m_pChatClient)
		delete m_pChatClient;
	m_pChatClient = new Scene(a_pSceneElements);
	m_pChatClient->HideScene();
	//std::cout << "Chat client set and hidden" << std::endl;
}

void SceneManager::SetFindServerElements(std::vector<CEGUI::Window*> a_pSceneElements)
{
	if(m_pFindServer)
		delete m_pFindServer;
	m_pFindServer = new Scene(a_pSceneElements);
	m_pFindServer->HideScene();
	//std::cout << "Find server set and hidden" << std::endl;
}

bool SceneManager::GotoMainMenu()
{
	//std::cout << "Loading main menu..." << std::endl;
	bool success = false;
	//
	if(m_pMainMenu)
	{
		if(*m_ppCurrentScene && !(*m_ppCurrentScene)->HideScene())
			std::cout << "	Warning: could not hide previous scene." << std::endl;
		if(m_pMainMenu && !m_pMainMenu->DisplayScene())
		{
			//std::cout << "	Could not display main menu!." << std::endl;
		}
		else
		{
			m_ppCurrentScene = &m_pMainMenu;
			//std::cout << "	Main menu displayed successfully." << std::endl;
			success = true;
		}
	}
	else
	{
		//std::cout << "	Main menu not found!" << std::endl;
	}
	m_pBackground->moveToBack();
	return success;
}

bool SceneManager::GotoChatClient()
{
	//std::cout << "Loading chat client..." << std::endl;
	bool success = false;
	//
	if(m_pChatClient)
	{
		if(*m_ppCurrentScene && !(*m_ppCurrentScene)->HideScene())
			std::cout << "	Warning: could not hide previous scene." << std::endl;
		if(m_pChatClient && !m_pChatClient->DisplayScene())
		{
			//std::cout << "	Could not display chat client!." << std::endl;
		}
		else
		{
			m_ppCurrentScene = &m_pChatClient;
			//std::cout << "	Chat client displayed successfully." << std::endl;
			success = true;
		}
	}
	else
	{
		std::cout << "	Chat client not found!" << std::endl;
	}
	m_pBackground->moveToBack();
	return success;
}

bool SceneManager::GotoFindServer()
{
	std::cout << "Loading find server..." << std::endl;
	bool success = false;
	//
	if(m_pFindServer)
	{
		if(*m_ppCurrentScene && !(*m_ppCurrentScene)->HideScene())
			std::cout << "	Warning: could not hide previous scene." << std::endl;
		if(m_pFindServer && !m_pFindServer->DisplayScene())
		{
			std::cout << "	Could not display find server!." << std::endl;
		}
		else
		{
			m_ppCurrentScene = &m_pFindServer;
			std::cout << "	Find server displayed successfully." << std::endl;
			success = true;
		}
	}
	else
	{
		std::cout << "	Find server not found!" << std::endl;
	}
	m_pBackground->moveToBack();
	return success;
}

void SceneManager::SetBackgroundImage(CEGUI::Window* a_pNewBackground)
{
	m_pBackground = a_pNewBackground;
}
