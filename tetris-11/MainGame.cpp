#include <ctime>
#include "MainGame.h"
#include "TextureManager.h"
#include "Text.h"
#include "Map.h"
#include "Tetromino.h"
#include "Score.h"
#include "Sound.h"
#include "Error.h"

//Initilaizes static game-objects
Window* MainGame::NewWindow = nullptr;
TTF_Font* MainGame::textFont = nullptr;
SDL_Texture* MainGame::t_tex0 = nullptr;
SDL_Texture* MainGame::t_tex1 = nullptr;
SDL_Texture* MainGame::t_tex2 = nullptr;
SDL_Texture* MainGame::t_tex3 = nullptr;
SDL_Texture* MainGame::t_tex4 = nullptr;
SDL_Texture* MainGame::t_tex5 = nullptr;
SDL_Texture* MainGame::t_tex6 = nullptr;
SDL_Texture* MainGame::t_tex10 = nullptr;
Map* map = nullptr;
Tetromino* tetroCurrent = nullptr;
Tetromino* tetroNext = nullptr;
int MainGame::score = 0;
int MainGame::timeCounter = 0;
bool MainGame::isPaused = false;
std::string MainGame::playerName;

MainGame::MainGame(){
	NewWindow = new Window(mapWidthX * tileSize, mapWidthY * tileSize, title.c_str());
	NewWindow->initSystems();


	textFont = TTF_OpenFont("res/fonts/arial.ttf", tileSize);// Dùng phông chữ arial

	t_tex0 = TextureManager::loadTexture("res/textures/tetro_gr.png");
	t_tex1 = TextureManager::loadTexture("res/textures/tetro_or.png");
	t_tex2 = TextureManager::loadTexture("res/textures/tetro_bl.png");
	t_tex3 = TextureManager::loadTexture("res/textures/tetro_pr.png");
	t_tex4 = TextureManager::loadTexture("res/textures/tetro_tl.png");
	t_tex5 = TextureManager::loadTexture("res/textures/tetro_rd.png");
	t_tex6 = TextureManager::loadTexture("res/textures/tetro_yl.png");
	t_tex10 = TextureManager::loadTexture("res/textures/tetro_ex.png");

	initTetroIndex();
	initTetronimo();

	Menu::initMenu();
	Sound::initSound();
}

MainGame::~MainGame(){
	delete tetroCurrent;
	delete tetroNext;
	delete map;

	SDL_DestroyTexture(t_tex0);
	SDL_DestroyTexture(t_tex1);
	SDL_DestroyTexture(t_tex2);
	SDL_DestroyTexture(t_tex3);
	SDL_DestroyTexture(t_tex4);
	SDL_DestroyTexture(t_tex5);
	SDL_DestroyTexture(t_tex6);
	NewWindow->~Window();

	NewWindow = nullptr;
	textFont = nullptr;
	t_tex0 = nullptr;
	t_tex1 = nullptr;
	t_tex2 = nullptr;
	t_tex3 = nullptr;
	t_tex4 = nullptr;
	t_tex5 = nullptr;
	t_tex6 = nullptr;
	map = nullptr;
	tetroCurrent = nullptr;
	tetroNext = nullptr;

	Menu::deleteMenu();
	Score::scoreErase();
	Sound::closeSound();
}

void MainGame::initTetroIndex() {
	srand(int(time(0)));
	Tetromino::tetroIndex = rand();
}

void MainGame::initTetronimo() {
	// thông tin demo của các khối
	srand(Tetromino::tetroIndex);
	int tetroType = rand() % 7;

	int tetro_0[4][4] = {	0,0,1,0,
							0,0,1,0,
							0,0,1,0,
							0,0,1,0 };

	int tetro_1[4][4] = {	0,0,1,0,
							0,1,1,0,
							0,1,0,0,
							0,0,0,0 };

	int tetro_2[4][4] = {	0,1,0,0,
							0,1,1,0,
							0,0,1,0,
							0,0,0,0 };

	int tetro_3[4][4] = {	0,0,0,0,
							0,1,1,0,
							0,1,1,0,
							0,0,0,0 };

	int tetro_4[4][4] = {	0,0,1,0,
							0,1,1,0,
							0,0,1,0,
							0,0,0,0 };

	int tetro_5[4][4] = {	0,1,1,0,
							0,0,1,0,
							0,0,1,0,
							0,0,0,0 };

    /*int tetro_8[4][4] = {	1,1,1,1,
							1,1,0,0,
							1,1,0,0,
							1,0,0,0 };8*/

	int tetro_6[4][4] = {	0,1,1,0,
							0,1,0,0,
							0,1,0,0,
							0,0,0,0 };
 /*int tetro_7[4][4] = {	1,1,1,1,
							1,1,1,1,
							1,1,1,1,
							1,1,1,1 };*/

	//Chọn các loại khối 4*4
	switch (tetroType) {
	case 0:
		for (int row = 0; row < 4; row++) {
			for (int column = 0; column < 4; column++) {
				tetrominoType[row][column] = tetro_0[row][column];
			}
		}
		break;
	case 1:
		for (int row = 0; row < 4; row++) {
			for (int column = 0; column < 4; column++) {
				tetrominoType[row][column] = tetro_1[row][column];
			}
		}
		break;
	case 2:
		for (int row = 0; row < 4; row++) {
			for (int column = 0; column < 4; column++) {
				tetrominoType[row][column] = tetro_2[row][column];
			}
		}
		break;
	case 3:
		for (int row = 0; row < 4; row++) {
			for (int column = 0; column < 4; column++) {
				tetrominoType[row][column] = tetro_3[row][column];
			}
		}
		break;
	case 4:
		for (int row = 0; row < 4; row++) {
			for (int column = 0; column < 4; column++) {
				tetrominoType[row][column] = tetro_4[row][column];
			}
		}
		break;
	case 5:
		for (int row = 0; row < 4; row++) {
			for (int column = 0; column < 4; column++) {
				tetrominoType[row][column] = tetro_5[row][column];
			}
		}
		break;
	case 6:
		for (int row = 0; row < 4; row++) {
			for (int column = 0; column < 4; column++) {
				tetrominoType[row][column] = tetro_6[row][column];
			}
		}
		break;
	default:
		break;
	}

	int textureType = rand() % 7;

	//chọn màu cho các khối
	switch (textureType) {
	case 0:
		tetronimoTexture = t_tex0;
		tetrominoColor = 10;
		break;
	case 1:
		tetronimoTexture = t_tex1;
		tetrominoColor = 11;
		break;
	case 2:
		tetronimoTexture = t_tex2;
		tetrominoColor = 12;
		break;
	case 3:
		tetronimoTexture = t_tex3;
		tetrominoColor = 13;
		break;
	case 4:
		tetronimoTexture = t_tex4;
		tetrominoColor = 14;
		break;
	case 5:
		tetronimoTexture = t_tex5;
		tetrominoColor = 15;
		break;
	case 6:
		tetronimoTexture = t_tex6;
		tetrominoColor = 16;
		break;
	default:
		break;
	}
}

void MainGame::initObjects() {
	//Bắt đầu khởi tạo
	map = new Map();
	tetroCurrent = new Tetromino(tetronimoTexture, 3 * tileSize, 1 * tileSize, tetrominoType, tetrominoColor);
	initTetronimo();
	tetroNext = new Tetromino(tetronimoTexture, 10 * tileSize, 2 * tileSize, tetrominoType, tetrominoColor);

	//Khởi tạo vị trí của khối
	Tetromino::tetroIndex--;
	Tetromino::tetroCount = 0;

	//Các biến trong game
	score = 0;
	timeCounter = 0;
	destroyedLines = 0;
	gameSpeed = 60;

	//Updates rendered text in map
	map->updateScore();
	map->updateSpeed();
	map->updateLines();
	map->updateBlocks();
}

void MainGame::deleteObjects() {
	delete map;
	map = nullptr;

	delete tetroCurrent;
	tetroCurrent = nullptr;

	delete tetroNext;
	tetroNext = nullptr;

	//Clears player name
	if (!playerName.empty()) {
		playerName.clear();
	}
}

void MainGame::playGame() {
	//Màn hình ban đầu
	if (newGame == false) {
		whileStart();
	}

	while (isQuit == false) {
		newGame = false;

		//khởi tạo ( xóa cũ)
		init();

		//vòng lặp game
		gameLoop();


		isClosed = false;

		//chơi thua
		if (gameOver == true) {
			Mix_PlayChannel(-1, Sound::soundEnd, 0);
			Mix_PlayMusic(Sound::musicEnd, -1);

			if (checkScore() >= 0) {
				whileNewScore();
				if (isQuit == false) {
					whileScore();
				}
			}

			if (isQuit == false) {
				whileEnd();
			}
		}
	}
}

void MainGame::init() {
	//xóa các vật trước
	deleteObjects();

	//tạo hiện tại
	initObjects();
}

void MainGame::gameLoop(){				//tỉ lệ khung hình
	const int frameDelay = 1000 / FPS;
	int speedCounter = 0;				//tốc độ game
	int frameCounter = 0;
	timeCounter = 0;					//tính time
	std::string timeCounterString;		// chuỗi để hiển thị time

	Uint32 frameStart;
	int frameTime;

	Mix_PlayMusic(Sound::musicGame, -1);

	while (!isClosed) {
		//dùng SDL để tính time trôi qua
		frameStart = SDL_GetTicks();


		processInput();

		if (isQuit == false) {
			//Updates vật thể
			update();

			//tiếp tục render map and objects
			render();

			//thời gian chơi game
			frameTime = SDL_GetTicks() - frameStart;

			//delay 1 xíu nếu quá nhanh
			if (frameDelay > frameTime) {
				SDL_Delay(frameDelay - frameTime);
			}

			//đếm thời gian khối di chuyển xuống
			speedCounter++;

			//Khi khối đạt xuống max rùi
			if (speedCounter > gameSpeed - 1) {
				if (tetroCurrent->canPieceMove(0, moveSpeed)) {
					tetroCurrent->update(0, moveSpeed);
					Mix_PlayChannel(-1, Sound::soundRotate, 0);
					speedCounter = 0;
				}
				else {

					speedCounter = 0;
					lockInPlace();
					Mix_PlayChannel(-1, Sound::soundLock, 0);
				}
			}


			frameCounter++;
			if (frameCounter == 60) {
				updateTimeCounter(&frameCounter, &timeCounter);
			}
		}
	}
}

void MainGame::processInput(){
	SDL_Event evnt;

	//Checks if keys are pressed
	if (SDL_PollEvent(&evnt)) {
		switch (evnt.type)
		{
		case SDL_QUIT:
			isClosed = true;
			isQuit = true;
			break;
		case SDL_KEYDOWN:
			switch (evnt.key.keysym.sym) {
			case SDLK_ESCAPE:
				whilePaused();
				break;
			case SDLK_LEFT:
				if (tetroCurrent->canPieceMove(-moveSpeed, 0)) {
					tetroCurrent->update(-moveSpeed, 0);
				}
				break;
			case SDLK_RIGHT:
				if (tetroCurrent->canPieceMove(moveSpeed, 0)) {
					tetroCurrent->update(moveSpeed, 0);
				}
				break;
			case SDLK_DOWN:
				if (tetroCurrent->canPieceMove(0, moveSpeed)) {
					tetroCurrent->update(0, moveSpeed);
				}
				else {
					lockInPlace();
					Mix_PlayChannel(-1, Sound::soundLock, 0);
				}
				break;
			case SDLK_SPACE:
				if (tetroCurrent->canPieceMove(0, 0, true)) {
					tetroCurrent->rotate();
					Mix_PlayChannel(-1, Sound::soundRotate, 0);
				}
				else {
					Mix_PlayChannel(-1, Sound::soundRotateFail, 0);
				}
				break;
			case SDLK_PAUSE:
				whilePaused();
				break;
			}
			break;
		default:
			break;
		}
	}
}

void MainGame::update() {
	//update vị trí
	tetroCurrent->update(0, 0);
	tetroNext->update(0, 0);
}

void MainGame::render() {

	SDL_RenderClear(NewWindow->renderer);

	//Renders map và khối
	renderObjects();

	//vẽ ra
	SDL_RenderPresent(NewWindow->renderer);
}

void MainGame::renderObjects() {
	//vẽ map và khối
	map->drawMap();
	tetroCurrent->render();
	tetroNext->render();
}

void MainGame::lockInPlace() {
	int lineCount = 0;

	//Dravs tetromino to map
	map->addToMap(tetroCurrent);

	//Increments score for added block
	score += 5;

	//Cheks if there are lines
	lineCount = map->checkLines();

	if (lineCount > 0) {
		//Saves destroyed lines
		map->linesDestroyed += lineCount;
		destroyedLines += lineCount;
		map->updateLines();
		//Increses speed
		if (destroyedLines > 4) {
			gameSpeed = gameSpeed - int(gameSpeed * 0.1);
			destroyedLines -= 5;
			map->updateSpeed();
		}
	}

	//Increments score for solid lines
	switch (lineCount) {
	case 1:
		score += 15;
		break;
	case 2:
		score += 35;
		break;
	case 3:
		score += 75;
		break;
	case 4:
		score += 145;
		break;
	default:
		break;
	}

	map->updateScore();

	//Initializes properties for new tetronimo
	initTetronimo();

	//Deletes old an creates new tetronimo object
	delete tetroCurrent;
	tetroCurrent = new Tetromino(tetronimoTexture, 3 * tileSize, 1 * tileSize, tetrominoType, tetrominoColor);
	initTetronimo();
	delete tetroNext;
	tetroNext = new Tetromino(tetronimoTexture, 10 * tileSize, 2 * tileSize, tetrominoType, tetrominoColor);
	Tetromino::tetroIndex--;

	//Updates trtromino count
	Tetromino::tetroCount++;
	map->updateBlocks();

	//Checks if spawned tetromino can move
	if (!tetroCurrent->canPieceMove(0, 0)) {
		isClosed = true;
		gameOver = true;
	}
}

void MainGame::updateTimeCounter(int* fCnt, int* tCnt) {
	int timeCounter = *tCnt;
	std::string timeCounterString;

	timeCounter++;
	*tCnt = timeCounter;
	if (timeCounter % 60 < 10 && timeCounter < 600) {
		timeCounterString = "0" + std::to_string(timeCounter / 60) + ":0" + std::to_string(timeCounter % 60);
		map->updateTime(timeCounterString);
		*fCnt = 0;
	}
	else if (timeCounter < 600) {
		timeCounterString = "0" + std::to_string(timeCounter / 60) + ":" + std::to_string(timeCounter % 60);
		map->updateTime(timeCounterString);
		*fCnt = 0;
	}
	else if (timeCounter % 60 < 10) {
		timeCounterString = std::to_string(timeCounter / 60) + ":0" + std::to_string(timeCounter % 60);
		map->updateTime(timeCounterString);
		*fCnt = 0;
	}
	else {
		timeCounterString = std::to_string(timeCounter / 60) + ":" + std::to_string(timeCounter % 60);
		map->updateTime(timeCounterString);
		*fCnt = 0;
	}
}

void MainGame::whileStart() {
	bool getKey = false;

	Mix_PlayMusic(Sound::musicIntro, -1);

	while (getKey == false) {
		Menu::renderStart();

		SDL_Event evnt;

		//Checks if keys are pressed
		if (SDL_PollEvent(&evnt)) {
			switch (evnt.type)
			{
			case SDL_QUIT:
				isQuit = true;
				getKey = true;
				break;
			case SDL_KEYDOWN:
				switch (evnt.key.keysym.sym) {
				case SDLK_ESCAPE:
					isQuit = true;
					getKey = true;
					break;
				}
				break;
			case SDL_MOUSEBUTTONDOWN:
				if ((evnt.motion.x > (5.5 * tileSize) && evnt.motion.x < (11.5 * tileSize)) &&
					(evnt.motion.y > (8   * tileSize) && evnt.motion.y < (10   * tileSize))) {
					newGame = true;
					getKey = true;
				}
				else if ((evnt.motion.x > (5.5 * tileSize) && evnt.motion.x < (11.5 * tileSize)) &&
						 (evnt.motion.y > (11  * tileSize) && evnt.motion.y < (13   * tileSize))) {
					whileInstructions();
					if (isQuit == true)
						getKey = true;
					break;
				}
				else if ((evnt.motion.x > (5.5 * tileSize) && evnt.motion.x < (11.5 * tileSize)) &&
						 (evnt.motion.y > (14  * tileSize) && evnt.motion.y < (16   * tileSize))) {
					whileScore();
					if (isQuit == true)
						getKey = true;
					break;
				}
				else if ((evnt.motion.x >(5.5 * tileSize) && evnt.motion.x < (11.5 * tileSize)) &&
						(evnt.motion.y > (17  * tileSize) && evnt.motion.y < (19   * tileSize))) {
					isQuit = true;
					getKey = true;
				}
				break;
			default:
				break;
			}
		}
	}
}

void MainGame::whileScore() {
	bool getKey = false;

	Score::scoreRead();

	Menu::renderScore();

	SDL_Event evnt;

	while (getKey == false) {
		//Checks if keys are pressed
		if (SDL_PollEvent(&evnt)) {
			switch (evnt.type)
			{
			case SDL_QUIT:
				isQuit = true;
				isClosed = true;
				getKey = true;
				break;
			case SDL_KEYDOWN:
				switch (evnt.key.keysym.sym) {
				case SDLK_ESCAPE:
					getKey = true;
					break;
				}
				break;
			case SDL_MOUSEBUTTONDOWN:
				if ((evnt.motion.x > (5.5 * tileSize) && evnt.motion.x < (11.5 * tileSize)) &&
					(evnt.motion.y > (17  * tileSize) && evnt.motion.y < (19   * tileSize))) {
					getKey = true;
				}
				break;
			default:
				break;
			}
		}
	}

	Score::scoreErase();
}

void MainGame::whileInstructions() {
	bool getKey = false;

	Menu::renderInstructions();

	SDL_Event evnt;

	while (getKey == false) {
		//Checks if keys are pressed
		if (SDL_PollEvent(&evnt)) {
			switch (evnt.type)
			{
			case SDL_QUIT:
				isQuit = true;
				isClosed = true;
				isPaused = false;
				getKey = true;
				break;
			case SDL_KEYDOWN:
				switch (evnt.key.keysym.sym) {
				case SDLK_ESCAPE:
					getKey = true;
					break;
				}
				break;
			case SDL_MOUSEBUTTONDOWN:
				if ((evnt.motion.x > (5.5 * tileSize) && evnt.motion.x < (11.5 * tileSize)) &&
					(evnt.motion.y > (17  * tileSize) && evnt.motion.y < (19   * tileSize))) {
					getKey = true;
				}
				break;
			default:
				break;
			}
		}
	}
}

void MainGame::whilePaused(){
	isPaused = true;

	Menu::renderPause();

	while (isPaused == true) {
		SDL_Event evntPaused;

		//Checks if keys are pressed
		if (SDL_PollEvent(&evntPaused)) {
			switch (evntPaused.type)
			{
			case SDL_QUIT:
				isClosed = true;
				isQuit = true;
				isPaused = false;
				break;
			case SDL_KEYDOWN:
				switch (evntPaused.key.keysym.sym) {
				case SDLK_ESCAPE:
					isPaused = false;
					break;
				case SDLK_PAUSE:
					isPaused = false;
					break;
				}
				break;
			case SDL_MOUSEBUTTONDOWN:
				if ((evntPaused.motion.x > (5.5 * tileSize) && evntPaused.motion.x < (11.5 * tileSize)) &&
					(evntPaused.motion.y > (8   * tileSize) && evntPaused.motion.y < (10   * tileSize))) {
					isPaused = false;
				}
				else if ((evntPaused.motion.x > (5.5 * tileSize) && evntPaused.motion.x < (11.5 * tileSize)) &&
						 (evntPaused.motion.y > (11  * tileSize) && evntPaused.motion.y < (13   * tileSize))) {
					Tetromino::tetroCount = 0;
					newGame = true;
					isClosed = true;
					isPaused = false;
				}
				else if ((evntPaused.motion.x > (5.5 * tileSize) && evntPaused.motion.x < (11.5 * tileSize)) &&
						 (evntPaused.motion.y > (14  * tileSize) && evntPaused.motion.y < (16   * tileSize))) {
					whileInstructions();
					Menu::renderPause();
				}
				else if ((evntPaused.motion.x > (5.5 * tileSize) && evntPaused.motion.x < (11.5 * tileSize)) &&
						 (evntPaused.motion.y > (17  * tileSize) && evntPaused.motion.y < (19   * tileSize))) {
					isClosed = true;
					isQuit = true;
					isPaused = false;
				}
				break;
			default:
				break;
			}
		}
	}
}

void MainGame::whileEnd() {
	bool getKey = false;

	while (getKey == false) {
		Menu::renderEnd();

		SDL_Event evnt;

		//Checks if keys are pressed
		if (SDL_PollEvent(&evnt)) {
			switch (evnt.type)
			{
			case SDL_QUIT:
				isQuit = true;
				getKey = true;
				break;
			case SDL_KEYDOWN:
				switch (evnt.key.keysym.sym) {
				case SDLK_ESCAPE:
					isQuit = true;
					getKey = true;
					break;
				}
				break;
			case SDL_MOUSEBUTTONDOWN:
				if ((evnt.motion.x > (5.5 * tileSize) && evnt.motion.x < (11.5 * tileSize)) &&
					(evnt.motion.y > (8   * tileSize) && evnt.motion.y < (10   * tileSize))) {
					isQuit = false;
					gameOver = false;
					getKey = true;
				}
				else if ((evnt.motion.x > (5.5 * tileSize) && evnt.motion.x < (11.5 * tileSize)) &&
						 (evnt.motion.y > (11  * tileSize) && evnt.motion.y < (13   * tileSize))) {
					whileInstructions();
					break;
				}
				else if ((evnt.motion.x > (5.5 * tileSize) && evnt.motion.x < (11.5 * tileSize)) &&
						 (evnt.motion.y > (14  * tileSize) && evnt.motion.y < (16   * tileSize))) {
					whileScore();
					break;
				}
				else if ((evnt.motion.x > (5.5 * tileSize) && evnt.motion.x < (11.5 * tileSize)) &&
						 (evnt.motion.y > (17  * tileSize) && evnt.motion.y < (19   * tileSize))) {
					isQuit = true;
					getKey = true;
				}
				break;
			default:
				break;
			}
		}
	}
}

int MainGame::checkScore() {
	int lastScorePos = 18;
	int ret = -1;

	Score::scoreRead();

	for (int i = 0; i < 5; i++) {
		if (score > std::stoi(Score::scoreVect[lastScorePos - i * 4])) {
			ret = lastScorePos - i * 4 - 2;
		}
		else {
			return ret;
		}
	}

	return ret;
}

void MainGame::whileNewScore() {
	unsigned int maxNameSize = 12;
	bool getKey = false;

	Menu::renderNewScore();

	SDL_Event evnt;
	while (getKey == false) {
		//Checks if keys are pressed
		if (SDL_PollEvent(&evnt)) {
			switch (evnt.type)
			{
			case SDL_QUIT:
				isQuit = true;
				getKey = true;
				return;
			case SDL_KEYDOWN:
				switch (evnt.key.keysym.sym) {
				case SDLK_ESCAPE:
					getKey = true;
					break;
				case SDLK_BACKSPACE:
					if (!playerName.empty()) {
						playerName.erase(playerName.length() - 1);
					}
					Menu::renderNewScore();
					break;
				case SDLK_RETURN:
					if (!playerName.empty()) {
						getKey = true;
					}
					break;
				}
				break;
			case SDL_TEXTINPUT:
				if (playerName.length() < maxNameSize) {
					playerName += evnt.text.text;
				}
				Menu::renderNewScore();
				break;
			case SDL_MOUSEBUTTONDOWN:
				if ((evnt.motion.x > (5.5 * tileSize) && evnt.motion.x < (11.5 * tileSize)) &&
					(evnt.motion.y > (17  * tileSize) && evnt.motion.y < (19   * tileSize)) &&
					!playerName.empty()) {
					getKey = true;
				}
				break;
			default:
				break;
			}
		}
	}

	std::string timeCounterString;

	if (timeCounter % 60 < 10 && timeCounter < 600) {
		timeCounterString = "0" + std::to_string(timeCounter / 60) + ":0" + std::to_string(timeCounter % 60);
	}
	else if (timeCounter < 600) {
		timeCounterString = "0" + std::to_string(timeCounter / 60) + ":" + std::to_string(timeCounter % 60);
	}
	else if (timeCounter % 60 < 10) {
		timeCounterString = std::to_string(timeCounter / 60) + ":0" + std::to_string(timeCounter % 60);
	}
	else {
		timeCounterString = std::to_string(timeCounter / 60) + ":" + std::to_string(timeCounter % 60);
	}

	Score::scoreUpdate(checkScore(), playerName, score, timeCounterString);
}
