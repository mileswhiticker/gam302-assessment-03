#include "Scene.hpp"

#include <CEGUI/CEGUIWindow.h>

#include <iostream>

Scene::Scene(std::vector<CEGUI::Window*> a_pSceneElements)
:	m_pSceneElements(a_pSceneElements)
{
	//
}

bool Scene::HideScene()
{
	for(std::vector<CEGUI::Window*>::iterator iter = m_pSceneElements.begin( ) ; iter != m_pSceneElements.end( ) ; iter++ )
	{
		CEGUI::Window* curElement = *iter;
		//curElement->setEnabled(true);
		curElement->setVisible(false);
		//std::cout << " - " << curElement->getName().c_str() << " hidden" << std::endl;
	}
	return true;
}

bool Scene::DisplayScene()
{
	for(std::vector<CEGUI::Window*>::iterator iter = m_pSceneElements.begin( ) ; iter != m_pSceneElements.end( ) ; iter++ )
	{
		CEGUI::Window* curElement = *iter;
		//curElement->setEnabled(true);
		curElement->setVisible(true);
		//std::cout << " - "  << curElement->getName().c_str() << " displayed" << std::endl;
	}
	return true;
}
