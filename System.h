#pragma once
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#define WINDOW_HEIGHT 600
#define WINDOW_WIDTH 800
#include <string>

namespace cprog
{
	class System
	{
	public:
		System();
		~System();
		SDL_Renderer* get_renderer() const;
		TTF_Font* get_font() const;
		void enableMusic(std::string filePath);

	private:
		SDL_Window* window;
		SDL_Renderer* renderer;
		TTF_Font* font;
		Mix_Chunk* musicPlayer;
	};

	extern System sys;
}


