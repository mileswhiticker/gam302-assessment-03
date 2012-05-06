#include "SceneManager.hpp"
#include "Scene.hpp"

#include "Renderer.hpp"
#include "ResourceManager.hpp"

SceneManager::SceneManager(ResourceManager& a_ResMgr, Renderer& a_Renderer)
:	m_pCurScene(NULL)
,	m_Renderer(a_Renderer)
,	m_ResMgr(a_ResMgr)
{
	//create default scene
	m_pScenes.push_back(new Scene());
	sf::Sprite* pSprite = NULL;
	a_ResMgr.CreateSprite(m_pScenes.back()->GetBGPath(), &pSprite);
	m_pScenes.back()->SetBackground(pSprite);
	EnableSceneByID(0);
}

SceneManager::~SceneManager()
{
	//
}

bool SceneManager::EnableSceneByID(unsigned short s_SceneID)
{
	if(s_SceneID < m_pScenes.size())
	{
		m_pCurScene = m_pScenes[s_SceneID];
		m_Renderer.SetBackground(m_pCurScene->GetBackground());
		return true;
	}
	return false;
}
