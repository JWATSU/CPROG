#pragma once
#include "Component.h"
#include <SDL.h>
#include "System.h"
namespace cprog
{
	class LaserComponent :public Component
	{
	public:
		static LaserComponent* getInstance(SDL_Rect* playerCoordinates);
		void draw() const;
		void tick();
		bool hasCollision(Component* other);
	protected:
		LaserComponent(SDL_Rect* playerCoordinates);
	};
}


