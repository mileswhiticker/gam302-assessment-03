#include "ResourceManager.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Rect.hpp>

#include "Anim.hpp"

#include <iostream>

ResourceManager::ResourceManager()
{
	//
}

bool ResourceManager::LoadSFMLImage( std::string FilePath, sf::Image** pOut )
{
	//create image
	sf::Image* image = new sf::Image();

	//if sfml loads it from file, then we are good to go
	if(image->loadFromFile(FilePath))
	{
		LoadedImages.push_back( std::pair<std::string, sf::Image*>(FilePath, image) );
		if(pOut)
			*pOut = image;
		return true;
	}

	//could not load the image from file
	return false;
}

bool ResourceManager::CreateSprite( std::string FilePath, sf::Sprite** pOut, _In_ sf::Rect<int>* a_pSubRect )
{
	short imageIndex = 0;
	//check to see if the image is already loaded
	for(unsigned short n=0;n<LoadedImages.size();n++)
	{
		if(!FilePath.compare(LoadedImages[n].first))
		{
			//found it
			imageIndex = n;
			goto create_sprite;
		}
	}
	LoadSFMLImage(FilePath);
	//check again to see if the image is loaded
	for(unsigned short n=0;n<LoadedImages.size();n++)
	{
		if(!FilePath.compare(LoadedImages[n].first))
		{
			//found it
			imageIndex = n;
			goto create_sprite;
		}
	}
	//if the code runs to here, then the image wasn't loaded
	*pOut = NULL;
	return false;

	create_sprite:
	//if sfml creates the sprite, then we're good
	sf::Sprite* sprite = new sf::Sprite(*LoadedImages[imageIndex].second);
	if(a_pSubRect)
		sprite->SetSubRect(*a_pSubRect);
	sf::Vector2f size = sprite->GetSize();
	if(pOut)
		*pOut = sprite;

	//now scale the sprite so that it matches the tile size
	/*sf::Vector2f spriteSize = sprite->GetSize();
	sf::Vector2f tileSize = FileLoader::GetTileSize();
	sf::Vector2f spriteScale;
	spriteScale.x = tileSize.x / spriteSize.x;
	spriteScale.y = tileSize.y / spriteSize.y;
	sprite->SetScale(spriteScale);*/

	//reset the centrepos
	spriteSize = sprite->GetSize();
	sprite->SetCenter(size.x/2,size.y);

	return true;
}

bool ResourceManager::CreateAnim(std::string FilePath, sf::Vector2f a_FrameSize, float FrameLength, short numFrames, _Out_ Anim** a_ppOut )
{
	sf::Sprite* pSpriteSheet = NULL;
	if(!CreateSprite(FilePath, &pSpriteSheet))
		return false;
	sf::Rect<int> frameRect;
	//
	sf::Vector2i framePos = sf::Vector2i(1,1);
	short curFrameNum = 1;
	std::vector<sf::Sprite*> frames;
	while(true)
	{
		frameRect.Bottom = (int)a_FrameSize.y * framePos.y;
		frameRect.Right = (int)a_FrameSize.x * framePos.x;
		frameRect.Left = (int)a_FrameSize.x * (framePos.x - 1);
		frameRect.Top = (int)a_FrameSize.y * (framePos.y - 1);
		//
		sf::Sprite* pFrame = NULL;
		if(!CreateSprite(FilePath, &pFrame, &frameRect))
			return false;
		//
		pFrame->SetScale(1.0f,1.0f);
		frames.push_back(pFrame);
		if(++framePos.x > 4)
		{
			framePos.x = 1;
			framePos.y++;
		}
		if(curFrameNum++ >= numFrames)
			break;
	}
	Anim* pNewAnim = new Anim(frames,FrameLength);
	if(a_ppOut)
		*a_ppOut = pNewAnim;
	return true;
}
