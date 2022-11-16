#include "Engine.h"

#include <iostream>
#include "Vector.h"
#include "Input.h";
#include "Screen.h";
#include "Image.h";
#include "Mixer.h";
#include "Text.h";

SDLEngine::SDLEngine()
{
	screen->Initialize();
	mixer->Initialize();
}

// Run Every Frame
void SDLEngine::Update()
{
	/*while (isgamerunning)
	{
		screen.refresh();
		render game objects;
		screen.present;

	}*/

	Input::Instance()->Update();

	if (Input::Instance()->IsMouseClicked())
	{
		std::cout << "clicked" << std::endl;
	}

	// Close Window
	if (Input::Instance()->IsWindowClosed())
	{
		isgamerunning = false;
	}
}

void SDLEngine::Close()
{
	screen->Shutdown();
}

void SDLEngine::Refresh()
{
	screen->Refresh();
}

void SDLEngine::ScreenPresent()
{
	screen->Present();
}

bool SDLEngine::GetIsgamerunning()
{
	return isgamerunning;
}
