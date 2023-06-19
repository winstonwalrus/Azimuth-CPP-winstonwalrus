#include <Azimuth/Resources/FontResource.h>

FontResource::FontResource(string _path)
	: Resource(LoadFont, UnloadFont, _path)
{
}
