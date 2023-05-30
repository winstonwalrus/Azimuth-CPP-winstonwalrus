#include "Azimuth/Resources/TextureResource.h"

TextureResource::TextureResource(string _path)
	: Resource(LoadTexture, UnloadTexture, _path)
{
}
