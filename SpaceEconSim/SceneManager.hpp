#ifndef SCENE_MANAGER_HPP
#define SCENE_MANAGER_HPP

#include <vector>

class Scene;
class Renderer;
class ResourceManager;
class GUIManager;

#define MAIN_MENU
#define OPTIONS_MENU
#define APPLICATION

namespace sf
{
	class Sprite;
};

namespace sfg
{
	class SFGUI;
};

class SceneManager
{
public:
	SceneManager(GUIManager& a_GUIMgr, ResourceManager& a_ResMgr, Renderer& a_Renderer);
	~SceneManager();
	//
	bool EnableSceneByID(unsigned short s_SceneID);
	//
private:
	std::vector<Scene*> m_pScenes;
	Scene* m_pCurScene;
	std::vector<sf::Sprite*> Backgrounds;
	//
	ResourceManager& m_ResMgr;
	GUIManager& m_GUIMgr;
	Renderer& m_Renderer;
};

#endif	//SCENE_MANAGER_HPP