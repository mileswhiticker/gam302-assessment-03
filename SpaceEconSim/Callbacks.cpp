#include "Callbacks.hpp"
#include "Renderer.hpp"
#include "App.hpp"

#include <iostream>

void Callback::KeyPress(sf::Event::KeyEvent KeyEvent)
{
	//App::GetReference().ProcKeyEvent(KeyEvent);
}

void Callback::GoToScene(Scene* TargetScene)
{
	//App::GetReference().ShowScene(TargetScene);
}

void Callback::Quit()
{
	//App::GetReference().ShowScene(NULL);
}

void Callback::MouseClick(sf::Event::MouseButtonEvent MouseButtonEvent)
{
	//std::cout << "Callback::MouseClick" << std::endl;
	sf::Vector2f clickPos;
	clickPos.x = (float)MouseButtonEvent.x;
	clickPos.y = (float)MouseButtonEvent.y;
	//Renderer::GetReference().MouseClick(clickPos);
}
