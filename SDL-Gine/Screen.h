#pragma once

#include <SDL.h>
#include <string>

//TODO - Remove whitespace
//TODO - Make this a Singleton

class Screen
{

public:
	Screen();
	~Screen();

	//TODO - Pass arguments to setup the screen
	bool Initialize();

	void Refresh();
	void Present();
	void Shutdown();

	SDL_Renderer* GetRenderer();

private:
	SDL_Window* m_window;
	SDL_Renderer* m_renderer;
};

