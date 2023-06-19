#include <Azimuth/Resources/ImageResource.h>

ImageResource::ImageResource(string _path)
	: Resource(LoadImage, UnloadImage, _path)
{
}
