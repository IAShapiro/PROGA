#include "stdafx.h"
#include "CppUnitTest.h"
#include "../MatrixMulThread/Matrix.h"
#include "../MatrixMulThread/Matrix.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(CorrectMul)
		{
			matrix A(2, 3), B(3,3), C(A.getSize1(),B.getSize2()), D;
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
			D = (A * B);
			Assert::IsTrue(A * B == C);
		}

		TEST_METHOD(IsError)
		{
			try
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
				
				matrix C = A * B;
				Assert::Fail();
				//Assert::ExpectException<std::invalid_argument>([A, B]() { A * B; });
			}
			catch (std::exception ex)
			{
				Assert::IsTrue(1 == 1);
			}
		}
	};
}