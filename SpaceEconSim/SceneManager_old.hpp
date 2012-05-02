#ifndef SCENEMANAGER_HPP
#define SCENEMANAGER_HPP

#include <vector>

namespace CEGUI
{
	class Window;
};
class Scene;

class SceneManager
{
public:
	static SceneManager& GetInstance()
	{
		static SceneManager instance;
		return instance;
	}
	//
	void SetMainMenuElements(std::vector<CEGUI::Window*> a_pSceneElements);
	bool GotoMainMenu();
	//
	void SetChatClientElements(std::vector<CEGUI::Window*> a_pSceneElements);
	bool GotoChatClient();
	//
	void SetFindServerElements(std::vector<CEGUI::Window*> a_pSceneElements);
	bool GotoFindServer();
	//
	void SetBackgroundImage(CEGUI::Window* a_pNewBackground);
private:
	SceneManager();
	CEGUI::Window* m_pBackground;
	//
	Scene** m_ppCurrentScene;
	Scene* m_pMainMenu;
	Scene* m_pFindServer;
	Scene* m_pChatClient;
};

#endif	//SCENEMANAGER_HPP