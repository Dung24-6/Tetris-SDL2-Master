#pragma once
#include "Window.h"

class Sound
{
public:
	static void initSound();
	static void closeSound();
public:
	static Mix_Music* musicIntro;
	static Mix_Music* musicGame;
	static Mix_Music* musicEnd;
	static Mix_Chunk* soundEnd;
	static Mix_Chunk* soundLine;
	static Mix_Chunk* soundRotate;
	static Mix_Chunk* soundRotateFail;
	static Mix_Chunk* soundLock;
};

