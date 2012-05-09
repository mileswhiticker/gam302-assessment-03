#include "SceneManager.hpp"
#include "GameInst.hpp"

#include <iostream>

void SceneManager::GotoGameScene()
{
	std::cout << "Beginning simulation." << std::endl;
	if(!m_pGameInst->Start())
		std::cout << "	Creating new world..." << std::endl;
	EnableSceneByID(SCENE_GAMEINST);
}

void SceneManager::GotoOptionsScene()
{
	std::cout << "Going to the options menu." << std::endl;
}

void SceneManager::Quit()
{
	std::cout << "Exiting the system, goodbye." << std::endl;
	m_IsQuittingNextUpdate = true;
}

void SceneManager::GotoMenuScene()
{
	std::cout << "Returning to main menu." << std::endl;
	m_pGameInst->Stop();
	std::cout << "	Halting world..." << std::endl;
	EnableSceneByID(SCENE_MAINMENU);
}
