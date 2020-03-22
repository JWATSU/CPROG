#include "PlayerComponent.h"
#include <SDL_image.h>
#include "LaserComponent.h"
#include "Session.h"

namespace cprog
{
	PlayerComponent* PlayerComponent::getInstance(std::string playerTexturePath)
	{
		return new PlayerComponent(playerTexturePath);
	}
	PlayerComponent::~PlayerComponent()
	{

	}

	PlayerComponent::PlayerComponent(std::string playerTexturePath) 
	{
		SDL_Surface* surface = IMG_Load(playerTexturePath.c_str());
		setTexture(SDL_CreateTextureFromSurface(sys.get_renderer(), surface));
		setCoordinates(new SDL_Rect{ 0,0,surface->w, surface->h });
		SDL_FreeSurface(surface);
	}
	void PlayerComponent::draw() const
	{
		SDL_RenderCopy(sys.get_renderer(), getTexture(), NULL, getCoordinates());
	}

	void PlayerComponent::keyDown(const SDL_Event& event)
	{
		switch (event.key.keysym.sym)
		{
		case SDLK_DOWN:
			getCoordinates()->y += 10;
			if (getCoordinates()->y > WINDOW_HEIGHT - getCoordinates()->h)
			{
				getCoordinates()->y = WINDOW_HEIGHT - getCoordinates()->h;
			}
			break;
		case SDLK_UP:
			getCoordinates()->y -= 10;
			if (getCoordinates()->y < 0)
			{
				getCoordinates()->y = 0;
			}
			break;
		case SDLK_SPACE:
			LaserComponent* projectile = LaserComponent::getInstance(getCoordinates());
			session.add(projectile);
			break;
		}

	}
	void PlayerComponent::keyUp(const SDL_Event& event)
	{

	}

	void PlayerComponent::mouseMotion(const SDL_Event& event)
	{
		
	}
}
