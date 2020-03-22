#include "LaserComponent.h"
#include <SDL_image.h>
#include "Session.h"
#include "EnemyComponent.h"
namespace cprog
{
	LaserComponent* LaserComponent::getInstance(SDL_Rect* playerCoordinates)
	{
		return new LaserComponent(playerCoordinates);
	}

	LaserComponent::LaserComponent(SDL_Rect* playerCoordinates)
	{
		SDL_Surface* surface = IMG_Load(session.getProjectileTextureFilePath().c_str());
		setTexture(SDL_CreateTextureFromSurface(sys.get_renderer(), surface));

		SDL_Rect* projectileCoordinates = new SDL_Rect{ playerCoordinates->w + 5 , playerCoordinates->y + playerCoordinates->h/2 ,surface->w, surface->h };
		setCoordinates(projectileCoordinates);

		SDL_FreeSurface(surface);
	}
	void LaserComponent::tick()
	{
		if (getCoordinates()->x > WINDOW_WIDTH) 
		{

			session.remove(this);
		}
		else
		{
			getCoordinates()->x += 5;
		}
	}
	void LaserComponent::draw() const
	{
		SDL_RenderCopy(sys.get_renderer(), getTexture(), NULL, getCoordinates());
	}

	bool LaserComponent::hasCollision(Component* other)
	{
		if (EnemyComponent* e = dynamic_cast<EnemyComponent*>(other)) 
		{
			return SDL_HasIntersection(getCoordinates(), other->getCoordinates());
		}

		return false;
	}
}
