#include "TextureManager.h"
#include "Window.h"
#include "Error.h"

SDL_Texture* TextureManager::loadTexture(const char* texture) {
	//Creates a surface
	SDL_Surface* tempSurface = IMG_Load(texture);
	//Check if temprorary surface created succesfully
	if (tempSurface == nullptr) {
		Error SDL("Failed to create temprorary surface!");
	}

	//Creates a texture from surface
	SDL_Texture* tex = SDL_CreateTextureFromSurface(MainGame::NewWindow->renderer, tempSurface);
	//Check if texture created succesfully
	if (!tex) {
		Error SDL("Failed to create texture!");
	}

	//After texture created, destroys temp surface
	SDL_FreeSurface(tempSurface);

	return tex;
}

void TextureManager::draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest) {
	SDL_RenderCopy(MainGame::NewWindow->renderer, tex, &src, &dest);
}