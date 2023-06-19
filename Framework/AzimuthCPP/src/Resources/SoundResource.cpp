#include <Azimuth/Resources/SoundResource.h>

SoundResource::SoundResource(string _path)
	: Resource(LoadSound, UnloadSound, _path)
{
}
