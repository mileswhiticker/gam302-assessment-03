#ifndef SCENE_HPP
#define SCENE_HPP

#include <vector>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>

namespace sf
{
	class Sprite;
};

class Button;
class Entity;
class SpeechBubble;
class Anim;

class Scene
{
public:
	Scene(std::string a_BGPath = "media/starry[1280x853].bmp");
	~Scene();
	virtual void Update(float a_dt);
	//
	Button* AddButton( std::string NewButtonText, sf::Vector2f Position, float a_RotVal = 0 );
	void AddMiscSprite( _In_ sf::Sprite* a_pSprite );
	void AddMiscAnim( _In_ Anim* a_pAnim );
	//
	void SetBackground( _In_ sf::Sprite* a_pBGImage );
	sf::Sprite* GetBackground();
	std::string GetBGPath();
	std::vector<Button*> GetButtons();
	virtual void ShowScene();
	virtual void HideScene();
	//
	virtual void ProcKeyEvent(sf::Event::KeyEvent KeyEvent);
	//
	Scene* m_pNextScene;
	Scene* m_pPreviousScene;
protected:
	sf::Sprite* m_pBackgroundImage;
	std::string m_BGPath;
	std::vector<sf::Sprite*> m_pMiscSprites;
	std::vector<Anim*> m_pMiscAnims;
	//
	std::vector<Button*> Buttons;
	std::vector<SpeechBubble*> SpeechBubbles;
	//
};

#endif