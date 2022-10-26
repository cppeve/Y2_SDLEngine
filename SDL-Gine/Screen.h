#pragma once

#include <SDL.h>
#include <string>

class Screen
{

public:
	Screen();
	~Screen();

	bool Initialize();
	void Refresh();
	void Present();
	void Shutdown();

	SDL_Renderer* GetRenderer();

private:
	SDL_Window* m_window;
	SDL_Renderer* m_renderer;
};

