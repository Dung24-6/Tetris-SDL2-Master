#include "Menu.h"
#include "Score.h"

SDL_Texture* Menu::menu_tex = nullptr;
SDL_Texture* Menu::menuScreen_tex = nullptr;
SDL_Rect Menu::srcRectMenu;
SDL_Rect Menu::destRectMenu;
SDL_Rect Menu::srcRectScreen;
SDL_Rect Menu::destRectScreen;

void Menu::initMenu() {
	menu_tex = TextureManager::loadTexture("res/textures/Button.png");
	menuScreen_tex = TextureManager::loadTexture("res/textures/galaxy.png");

	srcRectMenu.x = 0;
	srcRectMenu.y = 0;
	srcRectMenu.w = menuWidth;
	srcRectMenu.h = menuHeight;
	destRectMenu.x = 5 * tileSize;
	destRectMenu.y = 8 * tileSize;
	destRectMenu.w = 6 * tileSize;
	destRectMenu.h = 2 * tileSize;

	srcRectScreen.x = 0;
	srcRectScreen.y = 0;
	srcRectScreen.w = screenWidth;
	srcRectScreen.h = screenHeight;
	destRectScreen.x = 0;
	destRectScreen.y = 0;
	destRectScreen.w = 16 * tileSize;
	destRectScreen.h = 27 * tileSize;
}

void Menu::deleteMenu() {
	SDL_DestroyTexture(menu_tex);
	SDL_DestroyTexture(menuScreen_tex);

	menu_tex = nullptr;
	menuScreen_tex = nullptr;
}

void Menu::renderStart() {
	//Clears renderer
	SDL_RenderClear(MainGame::NewWindow->renderer);

	renderMenuScreen();

	destRectMenu.y = 8 * tileSize;

	SDL_RenderCopy(MainGame::NewWindow->renderer, menu_tex, &srcRectMenu, &destRectMenu);
	Text menuText1("New Game", destRectMenu.x + int(tileSize * 0.5), destRectMenu.y + int(tileSize * 0.4), 1, 1);

	destRectMenu.y = 11 * tileSize;

	SDL_RenderCopy(MainGame::NewWindow->renderer, menu_tex, &srcRectMenu, &destRectMenu);
	Text menuText2("Instructions", destRectMenu.x + int(tileSize * 0.45), destRectMenu.y + int(tileSize * 0.4), 1, 1);

	destRectMenu.y = 14 * tileSize;

	SDL_RenderCopy(MainGame::NewWindow->renderer, menu_tex, &srcRectMenu, &destRectMenu);
	Text menuText3("Score", destRectMenu.x + int(tileSize * 1.65), destRectMenu.y + int(tileSize * 0.4), 1, 1);

	destRectMenu.y = 17 * tileSize;

	SDL_RenderCopy(MainGame::NewWindow->renderer, menu_tex, &srcRectMenu, &destRectMenu);
	Text menuText4("Quit", destRectMenu.x + int(tileSize * 2), destRectMenu.y + int(tileSize * 0.4), 1, 1);

	menuText1.render();
	menuText2.render();
	menuText3.render();
	menuText4.render();

	//Draws the renderer to window
	SDL_RenderPresent(MainGame::NewWindow->renderer);
}

void Menu::renderScore() {
	SDL_RenderClear(MainGame::NewWindow->renderer);

	renderMenuScreen();

	Text scoreText0("High-Score", int(tileSize * 5.5), int(tileSize * 2), 1, 1);

	Text scoreText1_1(Score::scoreVect[0],  int(tileSize * 1.5), int(tileSize * 4  ), 1, 1);
	Text scoreText1_2(Score::scoreVect[4],  int(tileSize * 1.5), int(tileSize * 5.5), 1, 1);
	Text scoreText1_3(Score::scoreVect[8],  int(tileSize * 1.5), int(tileSize * 7  ), 1, 1);
	Text scoreText1_4(Score::scoreVect[12], int(tileSize * 1.5), int(tileSize * 8.5), 1, 1);
	Text scoreText1_5(Score::scoreVect[16],	int(tileSize * 1.5), int(tileSize * 10 ), 1, 1);

	Text scoreText2_1(Score::scoreVect[1],  int(tileSize * 3), int(tileSize * 4  ), 1, 1);
	Text scoreText2_2(Score::scoreVect[5],  int(tileSize * 3), int(tileSize * 5.5), 1, 1);
	Text scoreText2_3(Score::scoreVect[9],  int(tileSize * 3), int(tileSize * 7  ), 1, 1);
	Text scoreText2_4(Score::scoreVect[13], int(tileSize * 3), int(tileSize * 8.5), 1, 1);
	Text scoreText2_5(Score::scoreVect[17], int(tileSize * 3), int(tileSize * 10 ), 1, 1);

	Text scoreText3_1(Score::scoreVect[2],  int(tileSize * 9), int(tileSize * 4  ), 1, 1);
	Text scoreText3_2(Score::scoreVect[6],  int(tileSize * 9), int(tileSize * 5.5), 1, 1);
	Text scoreText3_3(Score::scoreVect[10], int(tileSize * 9), int(tileSize * 7  ), 1, 1);
	Text scoreText3_4(Score::scoreVect[14], int(tileSize * 9), int(tileSize * 8.5), 1, 1);
	Text scoreText3_5(Score::scoreVect[18], int(tileSize * 9), int(tileSize * 10 ), 1, 1);

	Text scoreText4_1(Score::scoreVect[3],  int(tileSize * 12), int(tileSize * 4  ), 1, 1);
	Text scoreText4_2(Score::scoreVect[7],  int(tileSize * 12), int(tileSize * 5.5), 1, 1);
	Text scoreText4_3(Score::scoreVect[11], int(tileSize * 12), int(tileSize * 7  ), 1, 1);
	Text scoreText4_4(Score::scoreVect[15], int(tileSize * 12), int(tileSize * 8.5), 1, 1);
	Text scoreText4_5(Score::scoreVect[19], int(tileSize * 12), int(tileSize * 10 ), 1, 1);

	destRectMenu.x = 5 * tileSize;
	destRectMenu.y = 17 * tileSize;

	SDL_RenderCopy(MainGame::NewWindow->renderer, menu_tex, &srcRectMenu, &destRectMenu);
	Text menuText1("Back", destRectMenu.x + int(tileSize * 1.9), destRectMenu.y + int(tileSize * 0.4), 1, 1);

	scoreText0.render();

	scoreText1_1.render();
	scoreText1_2.render();
	scoreText1_3.render();
	scoreText1_4.render();
	scoreText1_5.render();

	scoreText2_1.render();
	scoreText2_2.render();
	scoreText2_3.render();
	scoreText2_4.render();
	scoreText2_5.render();

	scoreText3_1.render();
	scoreText3_2.render();
	scoreText3_3.render();
	scoreText3_4.render();
	scoreText3_5.render();

	scoreText4_1.render();
	scoreText4_2.render();
	scoreText4_3.render();
	scoreText4_4.render();
	scoreText4_5.render();

	menuText1.render();

	//Draws the renderer to window
	SDL_RenderPresent(MainGame::NewWindow->renderer);
}

void Menu::renderInstructions() {
	SDL_RenderClear(MainGame::NewWindow->renderer);

	renderMenuScreen();

	Text insText1("Arrows to move",		int(tileSize * 2), int(tileSize * 2  ), 1, 1);
	Text insText2("Space to rotate",	int(tileSize * 2), int(tileSize * 3.5), 1, 1);
	Text insText3("ESC to quit",		int(tileSize * 2), int(tileSize * 5  ), 1, 1);
	Text insText4("PAUSE to.. pause",	int(tileSize * 2), int(tileSize * 6.5), 1, 1);
    Text insText5("Game xep hinh toc do de",	int(tileSize * 2), int(tileSize * 8), 1, 1);
    Text insText6(" HA VAN QUOC DUNG",	int(tileSize * 2), int(tileSize * 9.5), 1, 1);
    Text insText7(" Ma SV : 20020378",	int(tileSize * 2), int(tileSize * 11), 1, 1);
    Text insText8(" <3 ",	int(tileSize * 2), int(tileSize * 12.5), 1, 1);
	destRectMenu.x = 5 * tileSize;
	destRectMenu.y = 17 * tileSize;

	SDL_RenderCopy(MainGame::NewWindow->renderer, menu_tex, &srcRectMenu, &destRectMenu);
	Text menuText1("Back", destRectMenu.x + int(tileSize * 1.9), destRectMenu.y + int(tileSize * 0.4), 1, 1);

	insText1.render();
	insText2.render();
	insText3.render();
	insText4.render();
	insText5.render();
    insText6.render();
    insText7.render();
    insText8.render();

	menuText1.render();

	//Draws the renderer to window
	SDL_RenderPresent(MainGame::NewWindow->renderer);
}

void Menu::renderMenuScreen() {
	SDL_RenderCopy(MainGame::NewWindow->renderer, menuScreen_tex, &srcRectScreen, &destRectScreen);
}

void Menu::renderPause() {
	//Clears renderer
	SDL_RenderClear(MainGame::NewWindow->renderer);

	//Renders game objects in background
	MainGame::renderObjects();

	destRectMenu.y = 8 * tileSize;

	renderMenuScreen();

	SDL_RenderCopy(MainGame::NewWindow->renderer, menu_tex, &srcRectMenu, &destRectMenu);
	Text menuText1("Resume", destRectMenu.x + int(tileSize * 1.2), destRectMenu.y + int(tileSize * 0.4), 1, 1);

	destRectMenu.y = 11 * tileSize;

	SDL_RenderCopy(MainGame::NewWindow->renderer, menu_tex, &srcRectMenu, &destRectMenu);
	Text menuText2("New Game", destRectMenu.x + int(tileSize * 0.5), destRectMenu.y + int(tileSize * 0.4), 1, 1);

	destRectMenu.y = 14 * tileSize;

	SDL_RenderCopy(MainGame::NewWindow->renderer, menu_tex, &srcRectMenu, &destRectMenu);
	Text menuText3("Instructions", destRectMenu.x + int(tileSize * 0.45), destRectMenu.y + int(tileSize * 0.4), 1, 1);

	destRectMenu.y = 17 * tileSize;

	SDL_RenderCopy(MainGame::NewWindow->renderer, menu_tex, &srcRectMenu, &destRectMenu);
	Text menuText4("Quit", destRectMenu.x + int(tileSize * 2), destRectMenu.y + int(tileSize * 0.4), 1, 1);

	menuText1.render();
	menuText2.render();
	menuText3.render();
	menuText4.render();

	//Draws the renderer to window
	SDL_RenderPresent(MainGame::NewWindow->renderer);
}

void Menu::renderEnd() {
	//Clears renderer
	SDL_RenderClear(MainGame::NewWindow->renderer);

	//Renders game objects in background
	MainGame::renderObjects();

	destRectMenu.y = 8 * tileSize;

	renderMenuScreen();

	SDL_RenderCopy(MainGame::NewWindow->renderer, menu_tex, &srcRectMenu, &destRectMenu);
	Text menuText1("New Game", destRectMenu.x + int(tileSize * 0.5), destRectMenu.y + int(tileSize * 0.4), 1, 1);

	destRectMenu.y = 11 * tileSize;

	SDL_RenderCopy(MainGame::NewWindow->renderer, menu_tex, &srcRectMenu, &destRectMenu);
	Text menuText2("Instructions", destRectMenu.x + int(tileSize * 0.45), destRectMenu.y + int(tileSize * 0.4), 1, 1);

	destRectMenu.y = 14 * tileSize;

	SDL_RenderCopy(MainGame::NewWindow->renderer, menu_tex, &srcRectMenu, &destRectMenu);
	Text menuText3("Score", destRectMenu.x + int(tileSize * 1.65), destRectMenu.y + int(tileSize * 0.4), 1, 1);

	destRectMenu.y = 17 * tileSize;

	SDL_RenderCopy(MainGame::NewWindow->renderer, menu_tex, &srcRectMenu, &destRectMenu);
	Text menuText4("Quit", destRectMenu.x + int(tileSize * 2), destRectMenu.y + int(tileSize * 0.4), 1, 1);

	menuText1.render();
	menuText2.render();
	menuText3.render();
	menuText4.render();

	//Draws the renderer to window
	SDL_RenderPresent(MainGame::NewWindow->renderer);
}

void Menu::renderNewScore() {
	SDL_RenderClear(MainGame::NewWindow->renderer);

	renderMenuScreen();

	Text scoreText1("New High-Score!",		int(tileSize * 4.3), int(tileSize * 2.0), 1, 1);
	Text scoreText2("Please enter name",	int(tileSize * 3.8), int(tileSize * 3.5), 1, 1);

	//Text thats beign entered
	if (MainGame::playerName == "") {
		Text scoreText3("Enter name", int(tileSize * 3.8), int(tileSize * 6.5), 1, 1);
		scoreText3.render();
	}
	else {
		Text scoreText3(MainGame::playerName, int(tileSize * 3.8), int(tileSize * 6.5), 1, 1);
		scoreText3.render();
	}

	destRectMenu.y = 17 * tileSize;

	SDL_RenderCopy(MainGame::NewWindow->renderer, menu_tex, &srcRectMenu, &destRectMenu);
	Text menuText1("Done", destRectMenu.x + int(tileSize * 1.85), destRectMenu.y + int(tileSize * 0.4), 1, 1);

	scoreText1.render();
	scoreText2.render();

	menuText1.render();

	//Draws the renderer to window
	SDL_RenderPresent(MainGame::NewWindow->renderer);
}
