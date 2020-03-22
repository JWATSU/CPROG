#pragma once
#include "Component.h"
#include <SDL.h>
#include <string>
#include "System.h"
namespace cprog
{
	class PlayerComponent :public Component
	{
	public:
		void keyDown(const SDL_Event& event);
		void keyUp(const SDL_Event& event);
		void mouseMotion(const SDL_Event&);
		static PlayerComponent* getInstance(std::string playerTexturePath);
		~PlayerComponent();
		void draw() const;
	protected:
		PlayerComponent(std::string playerTexturePath);
	};
}
