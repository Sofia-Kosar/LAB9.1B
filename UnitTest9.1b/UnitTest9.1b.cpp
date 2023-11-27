#include "pch.h"
#include "CppUnitTest.h"
#include "../LAB9.1B/LAB9.1B.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest91b
{
	TEST_CLASS(UnitTest91b)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			const int N = 3;  
			Student students[N];
			students[0] = { "Student1", 1, PHYSICS, { 0 }, 5, 5, 0 };
			students[1] = { "Student2", 2, KI, { 1 }, 5, 4, 0 };
			students[2] = { "Student3", 3, INF, { 0 }, 4, 5, 0 };
	        double result = CalculatePercentGoodPhysicsMath(students, N);
			Assert::AreEqual(33.33, result, 0.01);
			
		}
	};
}
