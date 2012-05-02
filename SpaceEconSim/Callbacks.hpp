#ifndef CALLBACKS_HPP
#define CALLBACKS_HPP

#include <SFML/Window/Event.hpp>
#include <SFML/System/Vector2.hpp>

class Scene;

namespace Callback
{
	void KeyPress(sf::Event::KeyEvent KeyEvent);
	void GoToScene(Scene* TargetScene);
	void Quit();
	void MouseClick(sf::Event::MouseButtonEvent MouseButtonEvent);
};

#endif