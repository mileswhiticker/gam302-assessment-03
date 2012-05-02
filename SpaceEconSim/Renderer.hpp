//Renderer class written by Miles Whiticker

#if !defined(RENDERER_H)
#define RENDERER_H

#include <list>
#include <vector>
#include <SFML/System/Vector2.hpp>

//predeclares
class WindowManager;
namespace sf
{
	class Drawable;
	class Sprite;
	class RenderTarget;
};

class Button;
class Entity;
class Anim;
class SpeechBubble;

class Renderer
{
public:
	Renderer(WindowManager& a_WindowMgr);
	/*static Renderer& GetReference()
	{
		static Renderer instance;
		return instance;
	}*/
	bool Init();
	bool Render(float a_dt);
	bool CleanUp();
	//
	void AddVisibleSprite( _In_ sf::Sprite* a_pSprite );
	void SetBackgroundImage( _In_ sf::Sprite* a_pBG );
	//
	void AddButtons( std::vector<Button*> NewButtons );
	void AddEntities( std::vector<Entity*> NewEntities );
	void AddEntity( Entity* pNewEntity );
	void AddSpeechBubble( SpeechBubble* pSpeechBubble );
	void ClearSpeechBubble( SpeechBubble* pSpeechBubble );
	//
	void ClearButton( Button* a_pButton );
	void ClearEntity( Entity* a_pEntity );
	//
	void MouseClick( sf::Vector2f ClickPos );
	//
	void RemoveAllVisible();
	//
private:
	WindowManager& m_WindowMgr;
	//
	sf::Sprite* m_pBackgroundImage;
	//std::vector<sf::Sprite*> m_pVisibleSprites;
	std::vector<SpeechBubble*> m_pSpeechBubbles;
	std::vector<Button*> m_pVisibleButtons;
	std::list<Entity*> m_pVisibleEntities;
};

#endif // RENDERER_H