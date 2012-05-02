#ifndef APP_HPP
#define APP_HPP

class Renderer;
class WindowManager;
class ResourceManager;

class App
{
public:
	App(Renderer& a_Renderer, WindowManager& a_WindowMgr);
	~App();
	//
	bool Update(float a_Dt);
	bool CleanUp();
	//
private:
	bool m_Initialized;
	//
	Renderer& m_Renderer;
	WindowManager& m_WindowMgr;
	ResourceManager* m_pResourceManager;
	bool m_IsQuittingNextUpdate;
};

#endif	//APP_HPP