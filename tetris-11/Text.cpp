#include "Text.h"
#include "MainGame.h"
#include "Error.h"


Text::Text(std::string text, int x, int y, double sX, double sY) {
	TTF_Font* textFont = MainGame::textFont;

	textColor = { 255, 255, 255, 255 };

	textSurface = TTF_RenderUTF8_Blended(textFont, text.c_str(), textColor);
	//Check if temprorary surface created succesfully
	if (textSurface == nullptr) {
		Error SDL("Failed to create temprorary text surface!");
	}

	textTexture = SDL_CreateTextureFromSurface(MainGame::NewWindow->renderer, textSurface);
	//Check if texture created succesfully
	if (textTexture == nullptr) {
		Error SDL("Failed to create text texture!");
	}

	//After texture created, destroys temp surface
	SDL_FreeSurface(textSurface);

	srcRect.x = 0;
	srcRect.y = 0;

	SDL_QueryTexture(textTexture, NULL, NULL, &srcRect.w, &srcRect.h);

	destRect.x = x;
	destRect.y = y;

	scaleX = float(sX);
	scaleY = float(sY);

	destRect.w = int(srcRect.w * scaleX);
	destRect.h = int(srcRect.h * scaleY);
}

Text::~Text() {
	SDL_DestroyTexture(textTexture);
}

void Text::render() {
	SDL_RenderCopy(MainGame::NewWindow->renderer, textTexture, &srcRect, &destRect);
}
