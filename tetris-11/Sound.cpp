#include "Sound.h"

Mix_Music* Sound::musicIntro = nullptr;
Mix_Music* Sound::musicGame = nullptr;
Mix_Music* Sound::musicEnd = nullptr;
Mix_Chunk* Sound::soundEnd = nullptr;
Mix_Chunk* Sound::soundLine = nullptr;
Mix_Chunk* Sound::soundRotate = nullptr;
Mix_Chunk* Sound::soundRotateFail = nullptr;
Mix_Chunk* Sound::soundLock = nullptr;

void Sound::initSound(){
	musicIntro	= Mix_LoadMUS("res/audio/music/musicmenu.ogg");
	musicGame	= Mix_LoadMUS("res/audio/music/musicscreen.ogg");
	musicEnd	= Mix_LoadMUS("res/audio/music/musicmenu.ogg");

	soundEnd		= Mix_LoadWAV("res/audio/effects/SFX-Tetri-Cleared.ogg");
	soundLine		= Mix_LoadWAV("res/audio/effects/SFX-Move-Piece.ogg");
	soundRotate		= Mix_LoadWAV("res/audio/effects/SFX-Piece-Rotate.ogg");
	soundRotateFail = Mix_LoadWAV("res/audio/effects/SFX-Piece-Drop.ogg");
	soundLock		= Mix_LoadWAV("res/audio/effects/SFX-Tetri-Cleared.ogg");
}


void Sound::closeSound(){
	Mix_FreeMusic(musicIntro);
	Mix_FreeMusic(musicGame);
	Mix_FreeMusic(musicEnd);

	Mix_FreeChunk(soundEnd);
	Mix_FreeChunk(soundLine);
	Mix_FreeChunk(soundRotate);
	Mix_FreeChunk(soundLock);

	Mix_CloseAudio();
}
