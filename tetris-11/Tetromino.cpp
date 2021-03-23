#include "Tetromino.h"
#include "MainGame.h"
#include "TextureManager.h"
#include "Map.h"

int Tetromino::tetroIndex;
int Tetromino::tetroCount = 0;

Tetromino::Tetromino(SDL_Texture* tex, int x, int y, int tetroCurrent[4][4], int color) {
	tetro_tex = tex;

	posX = x;
	posY = y;

	srcRect.x = 0;
	srcRect.y = 0;

	srcRect.h = 32;
	srcRect.w = 32;

	destRect.x = posX;
	destRect.y = posY;

	loadTetromino(tetroCurrent);

	tetroColor = color;

	tetroIndex++;
}

Tetromino::~Tetromino() {
	tetro_tex = nullptr;
}

void Tetromino::loadTetromino(int arr[4][4]) {
	for (int row = 0; row < 4; row++) {
		for (int column = 0; column < 4; column++) {
			tetrominoType[row][column] = arr[row][column];
		}
	}
}

void Tetromino::update(int x, int y) {
	posX += x;
	posY += y;

	destRect.x = posX;
	destRect.y = posY;

	destRect.w = tileSize;
	destRect.h = tileSize;
}

void Tetromino::render() {
	int type = 0;

	for (int i = 0; i < 4 * 4; i++) {
		type = tetrominoType[i / 4][i % 4];

		switch (type)
		{
		case 1:
			SDL_RenderCopy(MainGame::NewWindow->renderer, tetro_tex, &srcRect, &destRect);
			break;
		default:
			break;
		}

		destRect.x = posX + ((i + 1) % 4) * tileSize;
		destRect.y = posY + ((i + 1) / 4) * tileSize;
	}
}

void Tetromino::rotate() {
	int tmpTetromino[4][4] = { 0 };

	//quay khối -> lưu vào mảng trung gian
	for (int i = 0; i < 4 * 4; i++) {
		tmpTetromino[i % 4][3 - (i / 4)] = tetrominoType[i / 4][i % 4];
	}

	//biến mảng thành khối
	for (int i = 0; i < 4 * 4; i++) {
		tetrominoType[i / 4][i % 4] = tmpTetromino[i / 4][i % 4];
	}
}

bool Tetromino::canPieceMove(int x, int y, bool r) {
	int type = 0;
	int indX = posX + x;
	int indY = posY + y;

	if (r == false) {
		for (int i = 0; i < 4 * 4; i++) {
			type = tetrominoType[i / 4][i % 4];

			switch (type)
			{
			case 1:
				if (Map::map[indY / tileSize][indX / tileSize] != 0) {
					return false;
				}
				break;
			default:
				break;
			}

			indX = posX + x + ((i + 1) % 4) * tileSize;
		    indY = posY + y + ((i + 1) / 4) * tileSize;
		}
	}
	else if (r == true) {
		int tmpTetromino[4][4] = { 0 };

		for (int i = 0; i < 4 * 4; i++) {
			tmpTetromino[i % 4][3 - (i / 4)] = tetrominoType[i / 4][i % 4];
		}

		for (int i = 0; i < 4 * 4; i++) {
			type = tmpTetromino[i / 4][i % 4];

			switch (type)
			{
			case 1:
				if (Map::map[indY / tileSize][indX / tileSize] != 0) {
					return false;
				}
				break;
			default:
				break;
			}

			indX = posX + x + ((i + 1) % 4) * tileSize;
			indY = posY + y + ((i + 1) / 4) * tileSize;
		}
	}

	return true;
}
