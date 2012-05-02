#ifndef WINDOWMANAGER_HPP
#define WINDOWMANAGER_HPP

#include <string>

namespace CEGUI
{
	class EventArgs;
	class Window;
	class Editbox;
}

class WindowManager
{
public:
	static WindowManager& GetInstance()
	{
		static WindowManager instance;
		return instance;
	}
	void Init();
	bool CheckQuitNextUpdate();
	//
private:
	WindowManager();
	//
	bool GotoMainMenu(const CEGUI::EventArgs& args);
	bool Quit(const CEGUI::EventArgs& args);
	//
	bool m_IsQuittingNextUpdate;
	//
	CEGUI::Window* m_pRootWindow;
	CEGUI::Editbox* m_pIPInput;
};

#endif	//WINDOWMANAGER_HPP