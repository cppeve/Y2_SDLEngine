#include <algorithm>
#include <iostream>
#include <assert.h>

#include "Mixer.h"

Mixer::Mixer()
{
    m_music = nullptr;
}

bool Mixer::Initialize(int frequency, int chunkSize)
{
    if (Mix_OpenAudio(frequency, AUDIO_S16SYS, 2, chunkSize) == -1)
    {
        std::cout << "Error initializing Audio" << std::endl;
        return false;
    }
    return false;
}

bool Mixer::Load(const std::string& filename)
{
    m_music = Mix_LoadMUS(filename.c_str());

    if (!m_music)
    {
        std::cout << "Error loading Auidio" << std::endl;
        return false;
    }
    return false;
}

void Mixer::Unload(const std::string& tag)
{
    Mix_FreeMusic(m_music);
}

void Mixer::Shutdown()
{
    Mix_CloseAudio();
}

void Mixer::SetVolume(float volume)
{
    volume = std::clamp(volume, 0.0f, 1.0f);
    Mix_VolumeMusic(static_cast<int>(volume * 128.0f));
}

bool Mixer::Play(Loop loop)
{
    if (!Mix_PlayingMusic())
    {
        if (Mix_PlayMusic(m_music, static_cast<int>(loop)) == -1)
        {
            std::cout << "Error playing Audio" << std::endl;
            return false;
        }
    }
    return false;
}

void Mixer::Pause()
{
    if (!Mix_PausedMusic())
    {
        Mix_PauseMusic();
    }
}

void Mixer::Resume()
{
    if (Mix_PausedMusic())
    {
        Mix_ResumeMusic();
    }
}

void Mixer::Stop()
{
    if (Mix_PlayingMusic())
    {
        Mix_HaltMusic();
    }
}
