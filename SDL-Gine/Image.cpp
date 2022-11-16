#include <iostream>
#include <SDL_image.h>
#include "Image.h"
#include "Screen.h"

Image::Image(int width, int height)
{
	m_dimension.x = width;
	m_dimension.y = height;
}

bool Image::Load(Screen& screen, const std::string& filename)
{
	SDL_Surface* imageData = IMG_Load(filename.c_str());
	if (!imageData)
	{
		std::cout << "Error Loading Image" << std::endl;
		return false;
	}
	else std::cout << "Image Loaded Successfuly" << std::endl;

	m_texture = SDL_CreateTextureFromSurface(screen.GetRenderer(), imageData);
	return true;
}

//TODO - Is this required? Why is it empty?
void Image::Unload()
{

}

void Image::SetDimension(int width, int height)
{
	m_dimension.x = width;
	m_dimension.y = height;
}

void Image::Render(Screen& screen, int x, int y)
{
	SDL_Rect src;
	SDL_Rect dst;

	src.x = 0;
	src.y = 0;
	src.w = m_dimension.x;
	src.h = m_dimension.y;

	dst.x = x;
	dst.y = y;
	dst.w = m_dimension.x;
	dst.h = m_dimension.y;

	SDL_Point  centerp;
	centerp.x = m_dimension.x / 2;
	centerp.y = m_dimension.y / 2;

	SDL_RenderCopyEx(
		screen.GetRenderer(), m_texture, &src, &dst, 0.0, &centerp, SDL_FLIP_NONE);
}
