#include "Session.h"
#include <SDL.h>
#include "System.h"
#include <SDL_image.h>
#include <string>
#include "EnemyComponent.h"
namespace cprog
{
	Session::Session()
	{

	}
	Session::~Session()
	{

	}

	void Session::add(Component* c)
	{
		toBeAdded.push_back(c);
	}

	void Session::remove(Component* c)
	{
		toBeRemoved.push_back(c);
	}

	void Session::run()
	{
		//SDL_Surface* surface = IMG_Load(getBackgroundFilePath().c_str());
		//SDL_Texture* texture = SDL_CreateTextureFromSurface(sys.get_renderer(), surface);
		//SDL_FreeSurface(surface);

		//An alternative to the code above? Not sure if it works
		SDL_Texture* texture = IMG_LoadTexture(sys.get_renderer(), backgroundFilePath.c_str());

		bool quit = false;

		Uint32 frameDelay = 1000 / FPS;
		Uint32 frameStart;
		int frameTime;

		while (!quit)
		{
			frameStart = SDL_GetTicks();

			SDL_Event event;
			while (SDL_PollEvent(&event))
			{
				switch (event.type)
				{
				case SDL_QUIT:
					quit = true;
					break;
				case SDL_KEYDOWN:
					for (Component* c : components)
					{
						c->keyDown(event);
					}
					break;
				case SDL_KEYUP:
					for (Component* c : components)
					{
						c->keyUp(event);
					}
					break;
				case SDL_MOUSEMOTION:
				{
					for (Component* c : components)
					{
						c->mouseMotion(event);
					}
				}
				}
			}
			SDL_RenderCopy(sys.get_renderer(), texture, NULL, NULL);

			enemyLimiter++;
			if (enemyLimiter > 250)
			{
				EnemyComponent* enemy = EnemyComponent::getInstance(enemyTextureFilePath);
				add(enemy);
				enemyLimiter = 0;
			}

			for (Component* s : components)
			{
				for (std::vector<Component*>::iterator i = components.begin(); i != components.end(); i++)
					if (s->hasCollision(*i)) {
						toBeRemoved.push_back(s);
						toBeRemoved.push_back(*i);
					}
			}

			for (Component* c : components)
			{
				c->tick();
			}
			for (Component* c : toBeAdded)
			{
				components.push_back(c);
			}
			toBeAdded.clear();

			for (Component* c : toBeRemoved)
			{
				for (std::vector<Component*>::iterator i = components.begin(); i != components.end();)
				{
					if (*i == c)
					{
						delete c;
						i = components.erase(i);
					}
					else
					{
						i++;
					}
				}
			}
			toBeRemoved.clear();

			for (Component* c : components)
			{
				c->draw();
			}

			SDL_RenderPresent(sys.get_renderer());

			frameTime = SDL_GetTicks() - frameStart;
			if (frameDelay > frameTime)
			{
				SDL_Delay(frameDelay - frameTime);
			}
		}
		SDL_DestroyTexture(texture);

	}
	Session session;
}