#pragma once

#include <string>
#include <SDL_image.h>
#include "Vector.h"
#include "Screen.h"

class Image
{

public:


	Image(int width = 0, int height = 0);

	bool Load(Screen&, const std::string& filename);
	void Unload();

	void SetDimension(int width, int height);
	void Render(Screen&, int x = 0, int y = 0);

private:
	SDL_Texture* m_texture = nullptr;
	Vector<int> m_dimension;
};

