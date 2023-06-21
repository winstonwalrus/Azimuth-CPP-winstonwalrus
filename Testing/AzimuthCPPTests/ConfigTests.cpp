#include "pch.h"
#include "CppUnitTest.h"

#include <Azimuth/Utils/Config.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace AzimuthCPPTests
{
	TEST_CLASS(ConfigTests)
	{
	public:

		static Config* config;

		TEST_CLASS_INITIALIZE(ConfigTestInit)
		{
			config = new Config("test");
		}
		
		TEST_METHOD(ConfigCreation)
		{
			Assert::IsNotNull(config, L"Config was null");
		}

		TEST_METHOD(ConfigInts)
		{
			Assert::IsTrue(*config->Get<int>("Ints", "foo") == 69);
			Assert::IsTrue(*config->Get<int>("Ints", "bar") == 420);
			Assert::IsTrue(*config->Get<int>("Ints", "fooBar") == 1337);
		}

		TEST_CLASS_CLEANUP(ConfigTestCleanup)
		{
			if (config != nullptr)
			{
				delete config;
				config = nullptr;
			}
		}
	};

	Config* ConfigTests::config = nullptr;
}
