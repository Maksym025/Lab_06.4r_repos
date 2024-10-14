#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_06.4r/Lab_06.4r.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			int const n = 10;
			int arr[n] = { 1,4,6,0,5,5,5,0,6,3 };
			int product = ProductBetweenZeros(arr, n);

			Assert::AreEqual(product, 125);
		}
	};
}
