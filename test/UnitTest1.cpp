#include "pch.h"
#include "CppUnitTest.h"

#include "../../src/Canvas.h"
#include "../../src/Circle.h"
#include "../../src/float_deal.h"
#include "../../src/IO_class.h"
#include "../../src/Line.h"
#include "../../src/Point.h"
#include "../../src/main.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		int argc = 5;
		char* argv[5];

		
		TEST_METHOD(TestMethod1)
		{
			Line l((string)"L -1 -1 3 3 ");
			Assert::AreEqual(1.0, l.A);
			Assert::AreEqual(-1.0, l.B);
			Assert::AreEqual(0.0, l.C);
		}

		TEST_METHOD(TestMethod2)
		{
			vector<string>* input = new vector<string>();
			input->clear();
			input->push_back("L 0 0 1 0");
			input->push_back("L 0 0 0 1");
			input->push_back("C -1 -1 1");
			Canvas canvas = Canvas();
			size_t i = canvas.draw(input);
			Assert::AreEqual((size_t)3, i);
		}
	};
}
