#include "Renderer.hpp"
#include "InputHandler.hpp"

#include <iostream>

#include <CEGUI/Cegui.h>
#include <CEGUI/CeguiBase.h>

#include <CEGUI/RendererModules/OpenGL/CEGUIOpenGLRenderer.h>
#include <SDL.h>
#include <GL3/gl3.h>

Renderer::Renderer()
:	m_AppTime(0)
,	m_DeltaT(0)
{
	//
}

bool Renderer::Init()
{
	if (SDL_Init(SDL_INIT_VIDEO)<0)
	{
		//fprintf(stderr, "Unable to initialise SDL: %s", SDL_GetError());
		//exit(0);
		std::cout << "Unable to initialise SDL: " << SDL_GetError() << std::endl;
		return false;
	}

	//Here we initialise SDL with video support. We need this for CEGUI. O.K. now SDL is ready to go. So let's fire up OpenGL:

	//SCREEN_WIDTH, SCREEN_HEIGHT
	if (SDL_SetVideoMode(800,600,0,SDL_OPENGL)==NULL)
	{
		std::cout << "Unable to set OpenGL videomode: " << SDL_GetError() << std::endl;
		return false;
		//fprintf(stderr, "Unable to set OpenGL videomode: %s", SDL_GetError());
		SDL_Quit();
		//exit(0);
	}
	SDL_WM_SetCaption("MilesChat v1.0", NULL);

	//Now OpenGL is ready. But we still need to set a decent configuration:

	glEnable(GL_CULL_FACE);
	glDisable(GL_FOG);
	glClearColor(0.0f,0.0f,0.0f,1.0f);
	glViewport(0,0, 800,600);

	//The OpenGL renderer that comes with CEGUI sets the matrices itself, so if you're using CEGUI for all your rendering needs this would be fine. Normally you would want the normal perspective projection setup though:

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, 800.0/600.0, 0.1,100.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//let sdl unicode symbols be recognised
	SDL_EnableUNICODE(1);

	//create renderer
	CEGUI::OpenGLRenderer* myRenderer = &CEGUI::OpenGLRenderer::bootstrapSystem();

	return true;
}

bool Renderer::Render()
{
	// send deltaT to SDL 
	inject_time_pulse();

	//inject SDL input into cegui
	bool must_quit = false;
	inject_input(must_quit);

	// clear the colour buffer
	glClear( GL_COLOR_BUFFER_BIT );
 
	// render the GUI :)
	CEGUI::System::getSingleton().renderGUI();
 
	// Update the screen 
	SDL_GL_SwapBuffers();

	return must_quit;
}

void Renderer::inject_time_pulse()
{
	// get current "run-time" in seconds
	double curTime = 0.001*SDL_GetTicks();
 
	//update deltaT
	m_DeltaT = curTime - m_AppTime;

	// inject the time that passed since the last call 
	CEGUI::System::getSingleton().injectTimePulse( float(m_DeltaT) );
 
	// store the new time as the last time
	m_AppTime = curTime;
}

double Renderer::GetAppTime()
{
	return m_AppTime;
}

double Renderer::GetDeltaT()
{
	return m_DeltaT;
}

Renderer::~Renderer()
{
	SDL_Quit();
}
