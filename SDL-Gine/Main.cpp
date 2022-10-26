#include "Engine.h"

SDLEngine sdlengine;


int main(int argc, char* argv[])
{

	Image background = Image(1600, 900);
	background.Load(*sdlengine.screen, "./image/back.jpg");

	sdlengine.mixer->Load("music/newbeg.mp3");
	sdlengine.mixer->SetVolume(0.5f);
	sdlengine.mixer->Play(Mixer::Loop::Ongoing);

	while (sdlengine.GetIsgamerunning())
	{
		sdlengine.Refresh();
		sdlengine.Update();

		background.Render(*sdlengine.screen, 0, 0);

		sdlengine.ScreenPresent();
	}

	sdlengine.Close();

	return 0;
}