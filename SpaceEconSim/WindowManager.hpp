#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <SFML/Window/Event.hpp>
#include <SFML/System/Vector2.hpp>

namespace sf
{
	class RenderWindow;
	class RenderTarget;
}

class WindowManager
{
public:
	WindowManager();
	bool Init();
	/*static WindowMgr& GetReference()
	{
		static WindowMgr instance;
		return instance;
	}*/
	//bool GetNextEvent(sf::Event& EventReceived);
	sf::Vector2f GetWindowDim();
	sf::RenderTarget& GetRenderTarget();
	//
	void HandleEvents();
	bool Display(float a_Dt);
	//
	bool CheckQuitNextUpdate();
	//
	void CleanUp();
private:
	sf::RenderWindow* m_pSFMLRenderWindow;
	bool m_IsQuittingNextUpdate;
	//
};

#endif