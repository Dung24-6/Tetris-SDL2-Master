#pragma once

#include <string>
#include "Window.h"
#include "Menu.h"

static const int mapWidthX = 16;
static const int mapWidthY = 27;
static const int tileSize = 25;

class MainGame
{
public:
	MainGame();
	~MainGame();
public:
	void initTetronimo();
	void playGame();
	void gameLoop();
	void processInput();
	void update();
	void render();
	static void renderObjects();
public:
	static Window* NewWindow;
	static TTF_Font* textFont;
	static SDL_Texture* t_tex0;
	static SDL_Texture* t_tex1;
	static SDL_Texture* t_tex2;
	static SDL_Texture* t_tex3;
	static SDL_Texture* t_tex4;
	static SDL_Texture* t_tex5;
	static SDL_Texture* t_tex6;
	static SDL_Texture* t_tex10;
	SDL_Texture* tetronimoTexture;	//Random texture for tetromino
	int tetrominoType[4][4];		//Random tetronimo type
	int tetrominoColor;				//Index for tetronimo texture used
	static int score;
	static int timeCounter;
	static bool isPaused;
	bool isClosed = false;
	bool isQuit = false;
	bool newGame = false;
	bool gameOver = false;
	static std::string playerName;
private:
	void initObjects();
	void deleteObjects();
	void init();
	void lockInPlace();
	void initTetroIndex();
	void updateTimeCounter(int* fCnt, int* tCnt);
	void whileStart();
	void whileScore();
	void whileInstructions();
	void whilePaused();
	void whileEnd();
	void whileNewScore();
	int checkScore();
private:
	const int FPS = 60;				//Game FPS
	const int moveSpeed = tileSize;	//Move speed - one title wide
	int gameSpeed = 60;				//Game speed to calculate down-movement of tetromino
	int destroyedLines = 0;
	std::string title = "KP Tetris 2.0";
};
