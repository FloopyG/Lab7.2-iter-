#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab7.2(iter).cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest72iter
{
	TEST_CLASS(UnitTest72iter)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int t;

			int rowCount = 3;
			int colCount = 1;
			int** P = new int* [rowCount];
			for (int i = 0; i < rowCount; i++)
				P[i] = new int[colCount];
			P[0][0] = 1;
			P[1][0] = 1;
			P[2][0] = 4;
			t = colMax(P, rowCount, 0, P[0][0]);

			Assert::AreEqual(t, 4);
		}
	};
}
