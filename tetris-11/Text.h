#pragma once
#include "Window.h"

class Text
{
public:
	Text(std::string text, int x, int y, double sX, double sY);
	~Text();
public:
	void render();
public:
private:
	SDL_Color textColor;
	SDL_Surface* textSurface;
	SDL_Texture* textTexture;
	SDL_Rect srcRect, destRect;
	float scaleX;
	float scaleY;
};

