#include "SimpleAudio.h"

ALuint saCreateAudioSource()
{
    ALuint source;

    alGenSources(1,&source);

    alSource3f(source,AL_POSITION,0,0,0);
	alSource3f(source,AL_VELOCITY,0,0,0);
	alSource3f(source,AL_DIRECTION,0,0,0);
	alSourcef(source,AL_ROLLOFF_FACTOR,0);
	alSourcei(source,AL_SOURCE_RELATIVE,AL_TRUE);
	alSourcei(source,AL_LOOPING,AL_FALSE);

    return source;
}

void saDestorySource(ALuint source)
{
    alDeleteSources(1,&source);
}

ALuint saCreateBuffer()
{
    int buffer;

    alGenBuffers(1,&buffer);

    return buffer;
}

void saDestoryBuffer(int buffer)
{
    alDeleteBuffers(1,&buffer);
}

void saLoadBuffer(ALuint buffer,void *pData,unsigned int sz)
{
    alBufferData(buffer,AL_FORMAT_STEREO16,pData,sz,44100);
}

void saSetSourceLooping(ALuint source,int bLoop)
{
    if(bLoop)
        alSourcei(source,AL_LOOPING,AL_TRUE);
    else
        alSourcei(source,AL_LOOPING,AL_FALSE);
}

void saPlaySound(ALuint source,ALuint buffer)
{
    alSourceStop(source);
    alSourcei(source,AL_BUFFER,buffer);
	alSourcePlay(source);
}

