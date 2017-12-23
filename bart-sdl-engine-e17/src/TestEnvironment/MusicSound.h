#pragma once

#include "SDL_Mixer.h"
#include <map>

#define MUSICTEST "05-treasure-trove-cove.mp3"
// ATTENTION: si le fichier de sons est au dessu de 196 kbps il est probable qu'il ne joue pas

class MusicSound
{
public:
	MusicSound();
	~MusicSound();

	void LoadMedia();
	Mix_Music* LoadMusic(const char* music);

	void LoadSound();
	Mix_Chunk * MusicSound::LoadSound(const char * sound);

	void PlayMusic(const char* SelectedMusic);
	void StopMusic();

	void PlaySound(const char* SelectedSound);

private:

	std::map<const char*, Mix_Music*> musics;
	std::map<const char*, Mix_Chunk*> sounds;
};

