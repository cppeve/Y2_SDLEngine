#include "Screen.h"

#include <iostream>

Screen::Screen()
{
	m_window = nullptr;
	m_renderer = nullptr;
}
Screen::~Screen()
{ }

bool Screen::Initialize()
{
	// ==================================================

	if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
	{
		std::cout << "SDL did not initialize..." << std::endl;
		return false;
	}

	// ==================================================

	m_window = SDL_CreateWindow("My Game",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		1600, 900,
		0);
	if (!m_window)
	{
		std::cout << "The Window did not initialize..." << std::endl;
		return false;
	}

	m_renderer = SDL_CreateRenderer(
		m_window,
		-1,
		SDL_RENDERER_ACCELERATED);
	if (!m_renderer)
	{
		std::cout << "The Window did not initialize..." << std::endl;
		return false;
	}

	// ==================================================

	return true;
}

void Screen::Refresh()
{
	SDL_RenderClear(m_renderer);
}

void Screen::Present()
{
	SDL_RenderPresent(m_renderer);
}

void Screen::Shutdown()
{
	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyWindow(m_window);
	SDL_Quit();
}

SDL_Renderer* Screen::GetRenderer()
{
	return m_renderer;
}