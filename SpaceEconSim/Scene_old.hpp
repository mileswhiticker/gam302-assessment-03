#ifndef SCENE_HPP
#define SCENE_HPP

#include <vector>

namespace CEGUI
{
	class Window;
};

class Scene
{
public:
	Scene(std::vector<CEGUI::Window*> a_pSceneElements);
	//
	bool HideScene();
	bool DisplayScene();
private:
	std::vector<CEGUI::Window*> m_pSceneElements;
	//
};

#endif	//SCENE_HPP