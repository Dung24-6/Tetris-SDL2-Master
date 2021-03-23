#pragma once
#include "MainGame.h"

class TextureManager
{
public:
	static SDL_Texture* loadTexture(const char* fileName);
	static void draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest);
};