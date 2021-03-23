#pragma once
#include "TextureManager.h"
#include "Text.h"

class Menu
{
public:
	static void initMenu();
	static void deleteMenu();
	static void renderStart();
	static void renderScore();
	static void renderInstructions();
	static void renderPause();
	static void renderEnd();
	static void renderNewScore();
private:
	static void renderMenuScreen();
private:
	static SDL_Texture* menu_tex;
	static SDL_Texture* menuScreen_tex;
	static SDL_Rect srcRectMenu, destRectMenu;
	static SDL_Rect srcRectScreen, destRectScreen;
	static const int menuWidth = 192;
	static const int menuHeight = 64;
	static const int screenWidth = 512;
	static const int screenHeight = 864;
};

