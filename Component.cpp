#include "Component.h"

namespace cprog
{
	Component::Component()
	{

	}

	Component::~Component()
	{
		delete coordinates;
		SDL_DestroyTexture(componentTexture);
	}
}