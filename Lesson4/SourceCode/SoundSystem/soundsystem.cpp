// dllmain.cpp : Определяет точку входа для приложения DLL.
#include "pch.h"
#include "soundsystem.h"
#include<assert.h>

SoundDevice* SoundDevice::get()
{
	static SoundDevice* snd_device = new SoundDevice();
	return snd_device;
}

SoundDevice::SoundDevice()
{
	p_ALCDevice = alcOpenDevice(nullptr); 
	if (!p_ALCDevice)
		throw("failed to get sound device");

	p_ALCContext = alcCreateContext(p_ALCDevice, nullptr);  
	if (!p_ALCContext)
		throw("Failed to set sound context");

	if (!alcMakeContextCurrent(p_ALCContext))   
		throw("failed to make context current");

	const ALCchar* name = nullptr;
	if (alcIsExtensionPresent(p_ALCDevice, "ALC_ENUMERATE_ALL_EXT"))
		name = alcGetString(p_ALCDevice, ALC_ALL_DEVICES_SPECIFIER);
	if (!name || alcGetError(p_ALCDevice) != AL_NO_ERROR)
		name = alcGetString(p_ALCDevice, ALC_DEVICE_SPECIFIER);
	printf("Opened \"%s\"\n", name);
}

SoundDevice::~SoundDevice()
{
	if (!alcMakeContextCurrent(nullptr))
		throw("failed to set context to nullptr");

	alcDestroyContext(p_ALCContext);
	if (p_ALCContext)
		throw("failed to unset during close");

	if (!alcCloseDevice(p_ALCDevice))
		throw("failed to close sound device");
}

SoundSource::SoundSource(float pitch, float gain, float position[3], float velocity[3], bool loopsound, ALuint buffer)
{
	alGenSources(1, &p_Source);
	alSourcef(p_Source, AL_PITCH, pitch);
	alSourcef(p_Source, AL_GAIN, gain);
	alSource3f(p_Source, AL_POSITION, position[0], position[1], position[2]);
	alSource3f(p_Source, AL_VELOCITY, velocity[0], velocity[1], velocity[2]);
	alSourcei(p_Source, AL_LOOPING, loopsound);
	alSourcei(p_Source, AL_BUFFER, buffer);
}

SoundSource::~SoundSource()
{
	alDeleteSources(1, &p_Source);
}

void SoundSystem::playsound(std::string sound_name) 
{
	alSourcePlay(sources[sound_name].p_Source);

	ALint state = AL_PLAYING;;
	while (state == AL_PLAYING && alGetError() == AL_NO_ERROR)
	{
		alGetSourcei(sources[sound_name].p_Source, AL_SOURCE_STATE, &state);
	}
}



ALuint SoundSystem::loadsound(std::string filename)
{
	ALenum err, format;
	ALuint buffer;
	SNDFILE* sndfile;
	SF_INFO sfinfo;
	short* membuf;
	sf_count_t num_frames;
	ALsizei num_bytes;
	sndfile = sf_open(filename.c_str(), SFM_READ, &sfinfo);
	
	format = AL_NONE;
	if (sfinfo.channels == 1)
		format = AL_FORMAT_MONO16;
	else if (sfinfo.channels == 2)
		format = AL_FORMAT_STEREO16;
	else if (sfinfo.channels == 3)
	{
		if (sf_command(sndfile, SFC_WAVEX_GET_AMBISONIC, NULL, 0) == SF_AMBISONIC_B_FORMAT)
			format = AL_FORMAT_BFORMAT2D_16;
	}
	else if (sfinfo.channels == 4)
	{
		if (sf_command(sndfile, SFC_WAVEX_GET_AMBISONIC, NULL, 0) == SF_AMBISONIC_B_FORMAT)
			format = AL_FORMAT_BFORMAT3D_16;
	}

	membuf = static_cast<short*>(malloc((size_t)(sfinfo.frames * sfinfo.channels) * sizeof(short)));

	num_frames = sf_readf_short(sndfile, membuf, sfinfo.frames);
	
	num_bytes = (ALsizei)(num_frames * sfinfo.channels) * (ALsizei)sizeof(short);

	buffer = 0;
	alGenBuffers(1, &buffer);
	alBufferData(buffer, format, membuf, num_bytes, sfinfo.samplerate);

	free(membuf);
	sf_close(sndfile);
	return buffer;
}


void SoundSystem::loadscene(std::string filename)
{
	auto reader = XmlReader();
	reader.LoadFile(filename.c_str());
	auto sounds = reader.ParseFile();
	float pitch = 1.0; 
	float gain = 1.0; 
	float position[3] = {0, 0, 0};
	float velocity[3] = {0, 0, 0};
	bool loop = false;
	ALuint buffer = 0;
	for (auto& sound : sounds)
	{
		for (auto component : sound)
		{
			if (component.first == "position")
			{
				auto xyz = XmlReader::ParseLine<3>(component.second);
				position[0] = xyz[0];
				position[1] = xyz[1];
				position[2] = xyz[2];
			}
			if (component.first == "velocity")
			{
				auto xyz = XmlReader::ParseLine<3>(component.second);
				velocity[0] = xyz[0];
				velocity[1] = xyz[1];
				velocity[2] = xyz[2];
			}
			if (component.first == "pitch")
			{
				pitch = std::stoi(component.second);
			}
			if (component.first == "gain")
			{
				gain = std::stof(component.second);
			}
			if (component.first == "loop")
			{
				if (component.second == "false")
					loop = 0;
				else
					loop = 1;
			}
			if (component.first == "file")
			{
				buffer = loadsound(component.second.c_str());
			}
			if (component.first == "name")
			{
				SoundSource src = SoundSource(pitch, gain, position, velocity, loop, buffer);
				sources.insert(std::pair<std::string, SoundSource>(component.second, src));
			}
		}
	}
}

SoundSystem::SoundSystem()
{
	device = SoundDevice::get();
}