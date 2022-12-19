#pragma once
#include "pch.h"

class SOUNDSYSTEM_API SoundDevice
{
public:
	static SoundDevice* get();
	SoundDevice();
	~SoundDevice();
private:
	

	ALCdevice* p_ALCDevice;
	ALCcontext* p_ALCContext;

};

class SOUNDSYSTEM_API SoundSource
{
public:
	SoundSource(float pitch, float gain, float position[3], float velocity[3], bool LoopSoound, ALuint buffer);
	SoundSource()
	{
		alGenSources(1, &p_Source);
		alSourcef(p_Source, AL_PITCH, 1.0);
		alSourcef(p_Source, AL_GAIN, 1.0);
		alSource3f(p_Source, AL_POSITION, 0.0, 0.0, 0.0);
		alSource3f(p_Source, AL_VELOCITY, 0.0, 0.0, 0.0);
		alSourcei(p_Source, AL_LOOPING, 0);
		alSourcei(p_Source, AL_BUFFER, 0);
	}
	~SoundSource();

	ALuint p_Source;
};

class SOUNDSYSTEM_API SoundSystem 
{
public:
	SoundSystem();
	void loadscene(std::string filename);
	void playsound(std::string sound_name);
	ALuint loadsound(std::string filename);

private:
	std::unordered_map<std::string, SoundSource> sources;
	SoundDevice* device;
};

