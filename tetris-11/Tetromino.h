#pragma once
#include "dep\include\SDL\SDL.h"

class Tetromino
{
public:
	Tetromino(SDL_Texture* tex, int x, int y, int tetroCurrent[4][4], int color = 0);
	~Tetromino();
public:
	void update(int x, int y);
	void render();
	void rotate();
	bool canPieceMove(int x, int y, bool r = false);
public:
	int posX;
	int posY;
	int tetrominoType[4][4];
	int tetroColor;
	static int tetroIndex;
	static int tetroCount;
private:
	void loadTetromino(int arr[4][4]);
private:
	SDL_Texture* tetro_tex;
	SDL_Rect srcRect, destRect;
};

