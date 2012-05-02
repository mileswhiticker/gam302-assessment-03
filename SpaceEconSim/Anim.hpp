#ifndef ANIM_HPP
#define ANIM_HPP

//#include <SFML/Graphics/Drawable.hpp>
#include <vector>
#include <SFML/System/Vector2.hpp>

namespace sf
{
	class Sprite;
};

class Anim
{
public:
	Anim( std::vector<sf::Sprite*> a_Frames, float a_FrameTime );
	~Anim();
	void Draw(float Dt);
	//
	void PlayLoop();
	void PlayOnce();
	void Pause();
	void Reset();
	//
	void FlipTheX(bool a_Flipped);
	//
	void SetPosition(sf::Vector2f a_Pos);
	void SetPosition(float x, float y);
	sf::Vector2f GetPosition();
	//
	//void SetCenter(sf::Vector2f a_Pos);
	//void SetCenter(float x, float y);
	//sf::Vector2f GetCenter();
	//
	void SetScale(sf::Vector2f a_Pos);
	void SetScale(float x, float y);
	sf::Vector2f GetScale();
	//
	sf::Vector2f GetSize();
	//
private:
	bool Playing;
	bool Looping;
	int CurFrame;
	float TimePerFrame;
	float tAfterPreviousFrame;
	//
	bool Flipped;
	//
	sf::Vector2f FramePosition;
	sf::Vector2f FrameCentre;
	sf::Vector2f FrameSize;
	//
	std::vector<sf::Sprite*> Frames;
	//
};

#endif