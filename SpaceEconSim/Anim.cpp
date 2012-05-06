#include "Anim.hpp"

#include "Renderer.hpp"
#include "WindowManager.hpp"

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

/*
Anim::Anim( std::vector<sf::Sprite*> a_Frames, float a_TimePerFrame )
:	Frames(a_Frames)
,	TimePerFrame(a_TimePerFrame)
,	tAfterPreviousFrame(0)
,	Playing(false)
,	Looping(true)
,	CurFrame(0)
,	Flipped(false)
{
	//grab the dimensions of the first frame
	FramePosition = Frames.front()->getPosition();
	FrameCentre = Frames.front()->GetCenter();
	FrameSize = Frames.front()->GetSize();

	//ensure all the frames have the same dimensions
	for(unsigned short n=0;n<Frames.size();n++)
	{
		sf::Vector2f vec = Frames[n]->GetPosition();
		if(vec != FramePosition)
		{
			Frames[n]->SetPosition(FramePosition);
		}
		//
		vec = Frames[n]->GetCenter();
		if(vec != FrameCentre)
		{
			Frames[n]->SetCenter(FrameCentre);
		}
		//
		vec = Frames[n]->GetSize();
		if(vec != FrameSize)
		{
			sf::Vector2f scale;
			scale.x = FrameSize.x / vec.x;
			scale.y = FrameSize.y / vec.y;
			Frames[n]->SetScale(scale);
		}
		//
	}
}

void Anim::Draw(float Dt)
{
	if(Playing)
	{
		tAfterPreviousFrame += Dt;
		while(tAfterPreviousFrame > TimePerFrame)
		{
			tAfterPreviousFrame -= TimePerFrame;
			CurFrame++;
			if((unsigned int)CurFrame >= Frames.size())
			{
				CurFrame = 0;
				if(!Looping)
					Playing = false;
			}
		}
	}
	Frames[CurFrame]->FlipX(Flipped);
	sf::RenderTarget* renderTarget = WindowMgr::GetReference().GetRenderTarget();
	renderTarget->Draw(*Frames[CurFrame]);
}

void Anim::PlayLoop()
{
	Playing = true;
	Looping = true;
}

void Anim::PlayOnce()
{
	Playing = true;
	Looping = false;
}

void Anim::Pause()
{
	Playing = false;
}

void Anim::Reset()
{
	Playing = false;
	CurFrame = 0;
	tAfterPreviousFrame = 0;
}

void Anim::FlipTheX(bool a_Flipped)
{
	Flipped = a_Flipped;
}

//position mutators
void Anim::SetPosition(sf::Vector2f a_Pos)
{
	for(unsigned short n=0;n<Frames.size();n++)
	{
		Frames[n]->SetPosition(a_Pos);
	}
	FramePosition = a_Pos;
}

void Anim::SetPosition(float x, float y)
{
	SetPosition(sf::Vector2f(x,y));
}

sf::Vector2f Anim::GetPosition()
{
	return Frames[0]->getPosition();
}
*/

//centrepoint mutators
/*void Anim::SetCenter(sf::Vector2f a_Pos)
{
	for(unsigned short n=0;n<Frames.size();n++)
	{
		Frames[n]->SetCenter(a_Pos);
	}
	FrameCentre = a_Pos;
}*/

/*void Anim::SetCenter(float x, float y)
{
	SetCenter(sf::Vector2f(x,y));
}*/

/*sf::Vector2f Anim::GetCenter()
{
	return Frames[0]->GetCenter();
}*/

//scale mutators
/*
void Anim::SetScale(sf::Vector2f a_Pos)
{
	for(unsigned short n=0;n<Frames.size();n++)
	{
		Frames[n]->setScale(a_Pos);
	}
	FrameSize = Frames[0]->getSize();
}
void Anim::SetScale(float x, float y)
{
	SetScale(sf::Vector2f(x,y));
}

sf::Vector2f Anim::GetScale()
{
	return Frames[0]->getScale();
}

//size accessor
sf::Vector2f Anim::GetSize()
{
	return Frames[0]->getSize();
}

Anim::~Anim()
{
	while(Frames.size())
	{
		delete Frames.back();
		Frames.pop_back();
	}
}
*/