#include "WindowManager.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
//#include <SFML/Window.hpp>
//#include <SFML/System.hpp>

#include <iostream>
#include "Callbacks.hpp"

using namespace sf;

WindowManager::WindowManager()
:	m_pSFMLRenderWindow(new RenderWindow())
,	m_IsQuittingNextUpdate(false)
{
	//
}

bool WindowManager::Init()
{
	//sf::Window window;
	//m_pSFMLRenderWindow->create(VideoMode(800,600),"Space Economy Sim");
	m_pSFMLRenderWindow->create(sf::VideoMode(800,600),"Space Economy Sim");
	sf::Image Icon;
	if (Icon.loadFromFile("media/icon[617x480].bmp") && m_pSFMLRenderWindow)
		m_pSFMLRenderWindow->setIcon(617, 480, Icon.getPixelsPtr());
	return true;
}

bool WindowManager::CheckQuitNextUpdate()
{
	return m_IsQuittingNextUpdate;
}

bool WindowManager::Display(float a_Dt)
{
	//show next frame
	m_pSFMLRenderWindow->display();

	return true;
}

void WindowManager::HandleEvents()
{
	//poll for events
	Event curEvent;
	while(m_pSFMLRenderWindow->pollEvent(curEvent))
	{
		switch(curEvent.type)
		{
		case(Event::MouseButtonPressed):
			{
				Callback::MouseClick(curEvent.mouseButton);
				break;
			}
		case(Event::KeyPressed):
			{
				Callback::KeyPress(curEvent.key);
				break;
			}
		case(Event::Closed):
			{
				m_IsQuittingNextUpdate = true;
			}
		}
	}
}

sf::RenderTarget& WindowManager::GetRenderTarget()
{
	return *m_pSFMLRenderWindow;
}

/*bool WindowManager::GetNextEvent(Event& EventReceived)
{
	return m_pSFMLRenderWindow->GetEvent(EventReceived);
}*/

void WindowManager::CleanUp()
{
	m_pSFMLRenderWindow->close();
	delete m_pSFMLRenderWindow;
}

sf::Vector2f WindowManager::GetWindowDim()
{
	sf::Vector2f out;
	out.y = (float)m_pSFMLRenderWindow->getSize().y;
	out.x = (float)m_pSFMLRenderWindow->getSize().x;
	return out;
}
