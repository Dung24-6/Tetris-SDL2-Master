#include "Map.h"
#include "TextureManager.h"
#include "Sound.h"

//Ve map
int lvl1[mapWidthY][mapWidthX] = {
{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
{ 1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1 },
{ 1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1 },
{ 1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1 },
{ 1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1 },
{ 1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1 },
{ 1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1 },
{ 1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1 },
{ 1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1 },
{ 1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1 },
{ 1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1 },
{ 1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1 },
{ 1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1 },
{ 1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1 },
{ 1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1 },
{ 1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1 },
{ 1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1 },
{ 1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1 },
{ 1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1 },
{ 1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1 },
{ 1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1 },
{ 1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1 },
{ 1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1 },
{ 1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1 },
{ 1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1 },
{ 1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1 },
{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 }
};

int Map::map[mapWidthY][mapWidthX] = { 0 };

Map::Map() {
	//Load ảnh cho cục 1 và cục 0
	black = TextureManager::loadTexture("res/textures/black.png");
	grey = TextureManager::loadTexture("res/textures/kimcuongdep.png");

	//Loads map từ map vừa vẽ bên trên

	loadMap(lvl1);

	src.x = src.y = 0;
	dest.x = dest.y = 0;

	src.w = 32;
	src.h = 32;
	dest.w = tileSize;
	dest.h = tileSize;

	textNext	= new Text("Next",	11 * tileSize + int(tileSize * 0.84), 1 * tileSize, 0.7, 0.7);
	textScore	= new Text("Score",	11 * tileSize + int(tileSize * 0.69), 7 * tileSize, 0.7, 0.7);
	textTime	= new Text("Time",	11 * tileSize + int(tileSize * 0.78), 11 * tileSize, 0.7, 0.7);
	textSpeed	= new Text("Speed", 11 * tileSize + int(tileSize * 0.60), 15 * tileSize, 0.7, 0.7);
	textLines	= new Text("Lines", 11 * tileSize + int(tileSize * 0.73), 19 * tileSize, 0.7, 0.7);
	textBlocks	= new Text("Blocks", 11 * tileSize + int(tileSize * 0.54), 23 * tileSize, 0.7, 0.7);

	updateScore();
	updateTime("00:00");
	updateSpeed();
	updateLines();
	updateBlocks();
}

Map::~Map() {
	delete textNext;
	delete textScore;
	delete textTime;
	delete textSpeed;
	delete textLines;
	delete textBlocks;
	delete textScoreValue;
	delete textTimeValue;
	delete textSpeedValue;
	delete textLinesValue;
	delete textBlocksValue;
	SDL_DestroyTexture(black);
	SDL_DestroyTexture(grey);
}

void Map::loadMap(int arr[mapWidthY][mapWidthX]) {
	for (int i = 0; i < mapWidthX * mapWidthY; i++) {
		map[i / mapWidthX][i % mapWidthX] = arr[i / mapWidthX][i % mapWidthX];
	}
}

void Map::drawMap() {
	int type = 0;

	for (int i = 0; i < mapWidthX * mapWidthY; i++) {
		type = map[i / mapWidthX][i % mapWidthX];

		dest.x = (i % mapWidthX) * tileSize;
		dest.y = (i / mapWidthX) * tileSize;

		switch (type)
		{
		case 0:
			TextureManager::draw(black, src, dest);
			break;
		case 1:
			TextureManager::draw(grey, src, dest);
			break;
		case 10:
			TextureManager::draw(MainGame::t_tex0, src, dest);
			break;
		case 11:
			TextureManager::draw(MainGame::t_tex1, src, dest);
			break;
		case 12:
			TextureManager::draw(MainGame::t_tex2, src, dest);
			break;
		case 13:
			TextureManager::draw(MainGame::t_tex3, src, dest);
			break;
		case 14:
			TextureManager::draw(MainGame::t_tex4, src, dest);
			break;
		case 15:
			TextureManager::draw(MainGame::t_tex5, src, dest);
			break;
		case 16:
			TextureManager::draw(MainGame::t_tex6, src, dest);
			break;
		case 20:
			TextureManager::draw(MainGame::t_tex10, src, dest);
			break;
		default:
			break;
		}
	}

	drawText();
}

void Map::drawText(){
	textNext->render();
	textScore->render();
	textTime->render();
	textSpeed->render();
	textLines->render();
	textBlocks->render();
	textScoreValue->render();
	textTimeValue->render();
	textSpeedValue->render();
	textLinesValue->render();
	textBlocksValue->render();
}

void Map::addToMap(Tetromino* tetroCurrent) {
	int x = tetroCurrent->posX / tileSize;
	int y = tetroCurrent->posY / tileSize;

	for (int i = 0; i < 16; i++) {
		if (tetroCurrent->tetrominoType[i / 4][i % 4] == 1) {
			map[y + (i / 4)][x + (i % 4)] = tetroCurrent->tetroColor;
		}
	}
}

int Map::checkLines() {
	bool isLineFull = false;
	int lineCount = 0;

	for (int row = 25; row > 0; row--) {
		for (int column = 1; column < 9; column++) {
			if (map[row][column] != 0) {
				isLineFull = true;
			}
			else {
				isLineFull = false;
				break;
			}
		}

		if (isLineFull == true) {
			removeLine(row);
			row++;
			lineCount++;
		}
	}

	return lineCount;
}

void Map::removeLine(int line) {
	int height = 25;
	int width = 8;

	Mix_PlayChannel(-1, Sound::soundLine, 0);




	for (int colum = 0; colum < width; colum++) {
		map[line][colum + 1] = 20;
	}

	//Clears renderer
	SDL_RenderClear(MainGame::NewWindow->renderer);

	drawMap();

	//Draws the renderer to window
	SDL_RenderPresent(MainGame::NewWindow->renderer);

	//Delays time to see changed block
	SDL_Delay(300);

	for (int row = line; row > 1; row--) {
		for (int column = 0; column < width; column++) {
			map[row][column + 1] = map[row - 1][column + 1];
		}
	}

	//Clears renderer
	SDL_RenderClear(MainGame::NewWindow->renderer);

	drawMap();

	//Draws the renderer to window
	SDL_RenderPresent(MainGame::NewWindow->renderer);

	//Delays time to see changed block
	SDL_Delay(200);
}

void Map::updateScore() {
	delete textScoreValue;
	textScoreValue = new Text(std::to_string(MainGame::score), 11 * tileSize + int(0.4 * tileSize), 8 * tileSize, 0.9, 0.9);
}

void Map::updateTime(std::string time) {
	delete textTimeValue;
	textTimeValue = new Text(time, 11 * tileSize + int(0.4 * tileSize), 12 * tileSize, 0.9, 0.9);
}

void Map::updateSpeed() {
	gameSpeed++;
	delete textSpeedValue;
	textSpeedValue = new Text(std::to_string(gameSpeed), 11 * tileSize + int(0.4 * tileSize), 16 * tileSize, 0.9, 0.9);
}

void Map::updateLines() {
	delete textLinesValue;
	textLinesValue = new Text(std::to_string(linesDestroyed), 11 * tileSize + int(0.4 * tileSize), 20 * tileSize, 0.9, 0.9);
}

void Map::updateBlocks() {
	delete textBlocksValue;
	textBlocksValue = new Text(std::to_string(Tetromino::tetroCount), 11 * tileSize + int(0.4 * tileSize), 24 * tileSize, 0.9, 0.9);
}
