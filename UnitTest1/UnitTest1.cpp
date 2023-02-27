#include "pch.h"
#include "CppUnitTest.h"
#include "../OperacionConjuntos/GraphSet.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(GraphSetTest)
	{
	public:
		
		TEST_METHOD(drawBigO_nlogn())
		{GraphSet graph;
			graph.drawBigO_nlogn();
		}
	};
}
