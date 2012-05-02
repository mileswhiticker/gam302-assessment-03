#include "Renderer.hpp"
#include "WindowManager.hpp"

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

Renderer::Renderer(WindowManager& a_WindowMgr)
:	m_WindowMgr(a_WindowMgr)
,	m_pBackgroundImage(NULL)
{
	//
}

bool Renderer::Init()
{
	//
	return true;
}

bool Renderer::Render(float a_dt)
{
	sf::RenderTarget& renderTarget = m_WindowMgr.GetRenderTarget();
	//sf::RenderStates::Default
	//first, draw the background image if there is one
	if(m_pBackgroundImage)
		renderTarget.draw(*m_pBackgroundImage);
	//
	m_WindowMgr.Display(a_dt);
	return false;
}

bool Renderer::CleanUp()
{
	//
	return true;
}