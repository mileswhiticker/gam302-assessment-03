#ifndef MAIN_MENU_HPP
#define MAIN_MENU_HPP

#include "Scene.hpp"

class MainMenu : public Scene
{
public:
	MainMenu(GUIManager& a_GUIMgr);
	//
private:
	void Quit();
	//
};

#endif	//MAIN_MENU_HPP