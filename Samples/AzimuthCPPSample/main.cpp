#include <Azimuth/Application.h>

#include "SampleGame.h"

int main(int _argc, char* _argv[])
{
	return Application::Run<SampleGame>(_argv);
}