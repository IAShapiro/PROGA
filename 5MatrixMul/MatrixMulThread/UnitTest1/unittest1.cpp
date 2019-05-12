#include "stdafx.h"
#include "CppUnitTest.h"
#include "../MatrixMulThread/Matrix.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			matrix A(2, 3), B(3,3), C(A.getSize1(),B.getSize2());
			for (auto i = 0; i < A.getSize1(); i++)
			{
				for (auto j = 0; j < A.getSize2(); j++)
				{
					A[i][j] = i + j;
				}
			}
			for (auto i = 0; i < B.getSize1(); i++)
			{
				for (auto j = 0; j < B.getSize2(); j++)
				{
					B[i][j] = i + j;
				}
			}
			for (auto i = 0; i < C.getSize1(); i++)
			{
				for (auto j = 0; j < C.getSize2(); j++)
				{
					C[i][j] = 3 * (i + j*(i + 1) + 2) - 1;
				}
			}
			//Assert::AreEqual(A * B == C, true);
			Assert::IsTrue(A * B == C);
		}

		TEST_METHOD(TestMethod2)
		{
			matrix A(2, 3), B(2, 3);
			for (auto i = 0; i < A.getSize1(); i++)
			{
				for (auto j = 0; j < A.getSize2(); j++)
				{
					A[i][j] = i + j;
				}
			}
			for (auto i = 0; i < B.getSize1(); i++)
			{
				for (auto j = 0; j < B.getSize2(); j++)
				{
					B[i][j] = i + j;
				}
			}
			Assert::ExpectException<std::exception>(A * B);
		}

	};
}