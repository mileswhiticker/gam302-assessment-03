#ifndef GUI_MANAGER_HPP
#define GUI_MANAGER_HPP

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFGUI/Desktop.hpp>

namespace sf
{
	class RenderTarget;
};

namespace sfg
{
	class SFGUI;
	class Desktop;
};

class GUIManager
{
public:
	GUIManager();
	void RenderGui(sf::RenderWindow& a_RenderWindow);
	void GUIManager::Update(float a_Dt);
	void HandleEvent(sf::Event a_Event);
	//
	void CreateNewWindow(sf::Vector2f a_Scale1 = sf::Vector2f(0.1f,0.1f), sf::Vector2f a_Scale2 = sf::Vector2f(0.2f,0.2f));
	void AddWidget(sfg::SharedPtr<sfg::Widget> a_Widget);
	sfg::WeakPtr<sfg::Desktop> GetDesktop();
	//
private:
	sfg::SFGUI* m_psfgui;
	sfg::SharedPtr<sfg::Desktop> m_pDesktop;
	//
};

#endif	//GUI_MANAGER_HPP