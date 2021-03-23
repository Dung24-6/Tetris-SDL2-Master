#pragma once
#include "MainGame.h"
#include "Tetromino.h"
#include "Text.h"

class Map
{
public:
	Map();
	~Map();
public:
	void loadMap(int arr[mapWidthY][mapWidthX]);
	void drawMap();
	void addToMap(Tetromino* tetroCurrent);
	int checkLines();
	void updateScore();
	void updateTime(std::string time);
	void updateSpeed();
	void updateLines();
	void updateBlocks();
public:
	static int map[mapWidthY][mapWidthX];
	int gameSpeed = -2;
	int linesDestroyed = 0;
private:
	void removeLine(int line);
	void drawText();
private:
	SDL_Rect src, dest;
	SDL_Texture* black;
	SDL_Texture* grey;
	Text* textScore = nullptr;
	Text* textNext = nullptr;
	Text* textTime = nullptr;
	Text* textSpeed = nullptr;
	Text* textLines = nullptr;
	Text* textBlocks = nullptr;
	Text* textScoreValue = nullptr;
	Text* textTimeValue = nullptr;
	Text* textSpeedValue = nullptr;
	Text* textLinesValue = nullptr;
	Text* textBlocksValue = nullptr;
};

