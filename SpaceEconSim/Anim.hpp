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
	Anim( std::vector<sf::Sprite*> a_Frames, double a_FrameTime );
	~Anim();
	void Draw(double Dt);
	//
	void PlayLoop();
	void PlayOnce();
	void Pause();
	void Reset();
	//
	void FlipTheX(bool a_Flipped);
	//
	void SetPosition(sf::Vector2f a_Pos);
	void SetPosition(double x, double y);
	sf::Vector2f GetPosition();
	//
	//void SetCenter(sf::Vector2f a_Pos);
	//void SetCenter(double x, double y);
	//sf::Vector2f GetCenter();
	//
	void SetScale(sf::Vector2f a_Pos);
	void SetScale(double x, double y);
	sf::Vector2f GetScale();
	//
	sf::Vector2f GetSize();
	//
private:
	bool Playing;
	bool Looping;
	int CurFrame;
	double TimePerFrame;
	double tAfterPreviousFrame;
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