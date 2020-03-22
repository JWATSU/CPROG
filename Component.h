#pragma once
#include <SDL.h>

namespace cprog
{
	class Component
	{
	public:
		virtual ~Component();
		virtual void keyDown(const SDL_Event&) {}
		virtual void keyUp(const SDL_Event&) {}
		//Should not be needed, could be implemented to control with mouse?
		virtual void mouseMotion(const SDL_Event&) {}
		//Every subclass should implement draw(), therefore we set it to 0
		virtual void draw() const = 0;
		//Not ever subclass should implement tick(), therefore we leave it as an empty method
		virtual void tick() {}

		SDL_Texture* getTexture() const { return componentTexture; }
		void setTexture(SDL_Texture* newTexture) { componentTexture = newTexture; }

		SDL_Rect* getCoordinates() const { return coordinates; }
		void setCoordinates(SDL_Rect* newCoordinates) { coordinates = newCoordinates; }

		virtual bool hasCollision(Component* other) { return false; }
	protected:
		Component();
	private:
		SDL_Rect* coordinates;
		SDL_Texture* componentTexture = nullptr;
		//We want to prohibit copying and assigning to avoid the slicing effect
		Component(const Component& other) = delete;
		const Component& operator=(const Component& other) = delete;

	};
}


