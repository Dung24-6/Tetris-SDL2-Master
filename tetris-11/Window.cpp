#include "Window.h"
#include "Error.h"

//Initializes renderer
SDL_Renderer* Window::renderer = nullptr;

Window::Window(int inputScreenWidth, int inputScreenHeight, std::string inputTitle) {
	window = nullptr;
	renderer = nullptr;
	screenWidth = inputScreenWidth;
	screenHeight = inputScreenHeight;
	title = inputTitle;
}

Window::~Window() {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
	Mix_Quit();
}

void Window::initSystems() {
	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {
		std::string sdlErrorString(SDL_GetError());
		Error SDL("SDL could not initialize! SDL_Error: " + sdlErrorString);
	}

	//Initializes SDL Image
	if (IMG_Init(IMG_INIT_PNG) != IMG_INIT_PNG) {
		Error SDL("Failed to initialize SDL_image!");
	}

	//Initializes SDL ttf
	if (TTF_Init() < 0) {
		Error SDL("Failed to initialize SDL_ttf!");
	}

	//Initializes SDL Mixer
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024) == -1) {
		Error SDL("Failed to initialize SDL_mixer!");
	}

	//Create window
	window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenWidth, screenHeight, 0);
	if (window == NULL) {
		std::string sdlErrorString(SDL_GetError());
		Error SDL("Window could not be created! SDL_Error: " + sdlErrorString);
	}

	//Create renderer
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	//Check if renderer created succesfully
	if (renderer == nullptr) {
		Error SDL("Failed to create renderer!");
	}
}
