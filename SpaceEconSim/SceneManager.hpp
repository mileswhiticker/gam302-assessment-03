#ifndef SCENE_MANAGER_HPP
#define SCENE_MANAGER_HPP

#include <vector>
class Scene;
class Renderer;
class ResourceManager;

class SceneManager
{
public:
	SceneManager(ResourceManager& a_ResMgr, Renderer& a_Renderer);
	~SceneManager();
	//
	bool EnableSceneByID(unsigned short s_SceneID);
	//
private:
	std::vector<Scene*> m_pScenes;
	Scene* m_pCurScene;
	//
	Renderer& m_Renderer;
	ResourceManager& m_ResMgr;
	//
};

#endif	//SCENE_MANAGER_HPP