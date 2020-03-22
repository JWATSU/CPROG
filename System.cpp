#include "System.h"

namespace cprog
{
	System::System()
	{
		SDL_Init(SDL_INIT_EVERYTHING);
		window = SDL_CreateWindow("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
		renderer = SDL_CreateRenderer(window, -1, 0);
		TTF_Init();
		font = TTF_OpenFont("c:/Windows/Fonts/arial.ttf", 36);

	}

	System::~System()
	{
		Mix_FreeChunk(musicPlayer);
		Mix_CloseAudio();
		TTF_CloseFont(font);
		TTF_Quit();
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
		SDL_Quit();
	}

	void System::enableMusic(std::string filePath)
	{
		Mix_OpenAudio(20050, AUDIO_S16SYS, 2, 4096);
		musicPlayer = Mix_LoadWAV(filePath.c_str());
		Mix_PlayChannel(-1, musicPlayer, -1);
	}

	SDL_Renderer* System::get_renderer() const 
	{
		return renderer;
	}

	TTF_Font* System::get_font() const
	{
		return font;
	}
	//A static object. The constructor of sys will run before main is run and its destrutor will run after main is finished.
	System sys;
}
