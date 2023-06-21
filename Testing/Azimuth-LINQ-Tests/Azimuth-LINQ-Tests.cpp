#include "pch.h"
#include "CppUnitTest.h"

#include <Azimuth/Utils/LINQ.h>

#include "Random.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace AzimuthLINQTests
{
	TEST_CLASS(AzimuthLINQTests)
	{
	public:
		// ------------------- BEGIN VARIABLES ------------------- //
		struct Data
		{
			int i;
			bool b;
			char c;
			float f;

			Data(int _i, bool _b, char _c, float _f)
				: i(_i), b(_b), c(_c), f(_f) {}
		};

		static int valueCount;
		// -------------------- END VARIABLES -------------------- //

	public:
		// -------------------- BEGIN HELPERS -------------------- //
		static bool IsEven(int _value) { return _value % 2 == 0; }

		static Data RandomData() { return Data(rand(), rand() % 2 == 0, (char)(rand() % 255), (float)rand()); }

		static int SelectInt(Data _data) { return _data.i; }
		// --------------------- END HELPERS --------------------- //
		
	public:
		// --------------------- BEGIN TESTS --------------------- //
		TEST_METHOD_INITIALIZE(InitTests)
		{
			valueCount = (rand() % 500) + 1;
		}

		TEST_METHOD(VectorAny)
		{
			vector<int> vector = Random::IntVector(valueCount);

			Assert::IsTrue(LINQ<int>::Any(vector, &AzimuthLINQTests::IsEven));
		}
		
		TEST_METHOD(VectorAll)
		{
			vector<int> vector = Random::IntVector(valueCount, true);

			Assert::IsTrue(LINQ<int>::All(vector, &AzimuthLINQTests::IsEven));
		}
		
		TEST_METHOD(VectorWhere)
		{
			vector<int> vector = Random::IntVector(valueCount);

			vector = LINQ<int>::Where(vector, &AzimuthLINQTests::IsEven);
			Assert::IsTrue(LINQ<int>::All(vector, &AzimuthLINQTests::IsEven));
		}

		TEST_METHOD(VectorSelect)
		{
			vector<Data> data = Random::TemplateVector<Data>(valueCount, &AzimuthLINQTests::RandomData);

			vector<int> list = LINQ<Data>::Select<int>(data, &AzimuthLINQTests::SelectInt);

			Assert::IsTrue(*list.begin() == data.begin()->i);
		}
		
		TEST_METHOD(ListAny)
		{
			list<int> list = Random::IntList(valueCount);

			Assert::IsTrue(LINQ<int>::Any(list, &AzimuthLINQTests::IsEven));
		}
		
		TEST_METHOD(ListAll)
		{
			list<int> list = Random::IntList(valueCount, true);

			Assert::IsTrue(LINQ<int>::All(list, &AzimuthLINQTests::IsEven));
		}
		
		TEST_METHOD(ListWhere)
		{
			list<int> list = Random::IntList(valueCount);

			list = LINQ<int>::Where(list, &AzimuthLINQTests::IsEven);
			Assert::IsTrue(LINQ<int>::All(list, &AzimuthLINQTests::IsEven));
		}
		
		TEST_METHOD(ListSelect)
		{
			list<Data> data = Random::TemplateList<Data>(valueCount, &AzimuthLINQTests::RandomData);

			list<int> list = LINQ<Data>::Select<int>(data, &AzimuthLINQTests::SelectInt);

			Assert::IsTrue(*list.begin() == data.begin()->i);
		}
		// ---------------------- END TESTS ---------------------- //
	};

	int AzimuthLINQTests::valueCount = 0;
}
