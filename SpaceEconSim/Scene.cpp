#include "Scene.hpp"
//#include "ObjectManager.hpp"
#include "App.hpp"
#include "Renderer.hpp"

//#include "Button.hpp"
//#include "SpeechBubble.hpp"

#include <iostream>

Scene::Scene(std::string a_BGPath)
:	m_pNextScene(NULL)
,	m_pPreviousScene(NULL)
,	m_pBackgroundImage(NULL)
,	m_BGPath(a_BGPath)
{
	//
}

Scene::~Scene()
{
	/*while(Buttons.size())
	{
		delete Buttons.back();
		Buttons.pop_back();
		//
	}
	while(SpeechBubbles.size())
	{
		delete SpeechBubbles.back();
		SpeechBubbles.pop_back();
		//
	}*/
}

void Scene::Update(float a_dt)
{
	//update SpeechBubbles
	/*for(unsigned short n=0;n<SpeechBubbles.size();n++)
	{
		SpeechBubbles[n]->Update(a_dt);
	}*/
}

/*Button* Scene::AddButton( std::string NewButtonText, sf::Vector2f Position, float a_RotVal )
{
	Button* newButton = new Button(NewButtonText,a_RotVal);
	newButton->SetPosition(Position);
	//
	Buttons.push_back(newButton);
	return newButton;
}*/

void Scene::AddMiscSprite( _In_ sf::Sprite* a_pSprite )
{
	m_pMiscSprites.push_back(a_pSprite);
}

void Scene::AddMiscAnim( _In_ Anim* a_pAnim )
{
	m_pMiscAnims.push_back(a_pAnim);
}

std::vector<Button*> Scene::GetButtons()
{
	return Buttons;
}

void Scene::ShowScene()
{
	//show background image, if there is one
	/*if(pBackgroundImage)
		Renderer::GetReference().SetBackgroundImage(pBackgroundImage);*/

	//show buttons
	//ObjMgr::GetReference().ShowButtons(Buttons);

	//show misc sprites
	//for(unsigned short n=0;n<m_pMiscSprites.size();n++)
	//{
	//	ObjMgr::GetReference().ShowMiscSprite(m_pMiscSprites[n]);
	//}

	//show misc anims
	//for(unsigned short m=0;m<m_pMiscAnims.size();m++)
	//{
	//	ObjMgr::GetReference().ShowMiscAnim(m_pMiscAnims[m]);
	//}
}

void Scene::HideScene()
{
	//ObjMgr::GetReference().ClearScene();
}

void Scene::SetBackground(sf::Sprite* a_pBGImage)
{
	m_pBackgroundImage = a_pBGImage;
}

std::string Scene::GetBGPath()
{
	return m_BGPath;
}

void Scene::ProcKeyEvent(sf::Event::KeyEvent KeyEvent)
{
	//
}

sf::Sprite* Scene::GetBackground()
{
	return m_pBackgroundImage;
}
