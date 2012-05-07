#define NOMINMAX
#define WIN32_LEAN_AND_MEAN
#include "Windows.h"

#include <iostream>
#include <time.h>
#include <string>

#include "guicon.h"

#include <SFML/System.hpp>
#include <SFGUI/SFGUI.hpp>

#include "App.hpp"
#include "ResourceManager.hpp"
#include "GUIManager.hpp"
#include "WindowManager.hpp"
#include "Renderer.hpp"

//don't use this, it's lazy
//#pragma comment(lib, "requiredLibrary.lib") 

//CEGUIBase_d.lib;CEGUIOpenGLRenderer_d.lib;OpenGL32.Lib;sdl.lib;glu32.lib

/*
//cegui error catching:

try
{
	// do some cegui code
}
catch (CEGUI::Exception& e)
{
	fprintf(stderr,"CEGUI Exception occured: %s", e.getMessage().c_str());
	// you could quit here
}

*/

int WINAPI WinMain(HINSTANCE a_hInst, HINSTANCE a_hPrevInst, LPSTR a_pCmdLine, int a_nCmdShow)
{
	RedirectIOToConsole();
	srand((unsigned int)time(0));
	//
	GUIManager guiMgr;
	WindowManager windowMgr;
	Renderer renderer(guiMgr,windowMgr);

	App app(windowMgr,guiMgr,renderer);
	//
	sf::Clock deltaTimer;
	bool quit = false;
	while(!quit)
	{
		float deltaT = deltaTimer.restart().asSeconds();
		if(app.Update(deltaT))
		{
			app.CleanUp();
			break;
		}
	}

	return 0;
}
