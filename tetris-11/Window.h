#pragma once

#include <string>
#include "dep\include\SDL\SDL.h"
#include "dep\include\SDL\SDL_image.h"
#include "dep\include\SDL\SDL_mixer.h"
#include "dep\include\SDL\SDL_ttf.h"

class Window
{
public:
	Window(int screenWidth, int screenHeight, std::string title);
	~Window();
public:
	void initSystems();
public:
	SDL_Window * window;
	static SDL_Renderer* renderer;
	int screenWidth;
	int screenHeight;
	std::string title;
};

