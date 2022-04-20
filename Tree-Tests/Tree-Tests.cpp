#include "pch.h"
#include "CppUnitTest.h"
#include "../CIS376-CompareTrees-TermProject/tree.h"
#include "../CIS376-CompareTrees-TermProject/avlTree.h"
#include "../CIS376-CompareTrees-TermProject/bsTree.h"
#include "../CIS376-CompareTrees-TermProject/splayTree.h"

using std::string;

using std::vector;

using std::ofstream;

using std::cout;

using std::endl;

using std::max;


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TreeTests
{
	TEST_CLASS(TreeTests)
	{
	public:
		
		TEST_METHOD(testWorkingAVL)
		{
			tree* t = new avl();
			t->insertNode(1);
			t->insertNode(3);
			t->insertNode(4);

			Assert::AreEqual(t->findHeight(), 2);
		}


		TEST_METHOD(testWorkingSplay)
		{
			tree* t = new splay();
			t->insertNode(1);
			t->insertNode(3);
			t->insertNode(4);

			Assert::AreEqual(t->findHeight(), 2);
		}

		TEST_METHOD(testSplayDelete)
		{
			tree* t = new splay();
			t->insertNode(1);
			t->insertNode(3);
			t->insertNode(4);

			t->deleteItem(1);
			t->deleteItem(3);
			t->deleteItem(4);

			bool stat = false;
			t->searchNode(4, stat);
			Assert::AreEqual(stat, false);
		}

		TEST_METHOD(testAVLDelete)
		{
			tree* t = new avl();
			t->insertNode(1);
			t->insertNode(3);
			t->insertNode(4);

			t->deleteItem(1);
			t->deleteItem(3);
			t->deleteItem(4);

			bool stat = false;
			t->searchNode(4, stat);
			Assert::AreEqual(stat, false);
		}


	};
}
