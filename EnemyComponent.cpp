#include "EnemyComponent.h"
#include <SDL_image.h>
#include "Session.h"

namespace cprog
{
	EnemyComponent* EnemyComponent::getInstance(std::string enemyTexturePath)
	{
		return new EnemyComponent(enemyTexturePath);
	}

	EnemyComponent::EnemyComponent(std::string enemyTexturePath)
	{
		SDL_Surface* surface = IMG_Load(enemyTexturePath.c_str());
		setTexture(SDL_CreateTextureFromSurface(sys.get_renderer(), surface));

		int Min = 0;
		int Max = WINDOW_HEIGHT - surface->h;
		int randomizedYCoordinate = std::rand() % (Max + 1 - Min) + Min;

		SDL_Rect* enemyCoordinates = new SDL_Rect{ WINDOW_WIDTH, randomizedYCoordinate, surface->w, surface->h };

		setCoordinates(enemyCoordinates);
		SDL_FreeSurface(surface);
	}

	void EnemyComponent::tick()
	{
		if (getCoordinates()->x < 0)
		{

			session.remove(this);
		}
		else
		{
			getCoordinates()->x -= session.getEnemyTravelSpeed();
		}
	}

	void EnemyComponent::draw() const
	{
		SDL_RenderCopy(sys.get_renderer(), getTexture(), NULL, getCoordinates());
	}
}
