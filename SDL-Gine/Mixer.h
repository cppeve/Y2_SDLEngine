#pragma once

#include<string>
#include<SDL_mixer.h>

class Mixer
{

public:
	enum class Loop
	{
		Once = 1,
		Ongoing = -1
	};

	Mixer();

	bool Initialize(int frequency = 44100, int chunkSize = 1024);
	bool Load(const std::string& filename);
	void Unload(const std::string& tag = "");
	void Shutdown();

	void SetVolume(float volume);

	bool Play(Loop loop = Loop::Once);
	void Pause();
	void Resume();
	void Stop();

private:
	Mix_Music* m_music;

};

