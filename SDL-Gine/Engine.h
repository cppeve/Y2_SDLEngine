#include "Vector.h"
#include "Input.h";
#include "Screen.h";
#include "Image.h";
#include "Mixer.h";
#include "Text.h";

class SDLEngine
{
public:
	SDLEngine();
	void Update();

	void Close();
	
	void Refresh();

	void ScreenPresent();
	bool GetIsgamerunning();

	Screen* screen = new Screen();
	Mixer* mixer = new Mixer();

private:
	bool isgamerunning = true;
};