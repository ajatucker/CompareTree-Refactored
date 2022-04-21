#include "pch.h"
#include "CppUnitTest.h"
#include "../CIS376-CompareTrees-TermProject/tree.h"
#include "../CIS376-CompareTrees-TermProject/avlTree.h"
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
		
		TEST_METHOD(testInsertBST)
		{
			tree* t = new tree();
			t->insertNode(1);
			t->insertNode(3);
			t->insertNode(4);

			Assert::AreEqual(t->findHeight(), 2);
		}

		TEST_METHOD(testInsertAVL)
		{
			tree* t = new avl();
			
			t->insertNode(1);
			t->insertNode(3);
			t->insertNode(4);

			Assert::AreEqual(t->findHeight(), 1);
		}


		TEST_METHOD(testInsertSplay)
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
			t->deleteItem(5);

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
			t->deleteItem(5);

			bool stat = false;
			t->searchNode(4, stat);
			Assert::AreEqual(stat, false);
		}

		TEST_METHOD(testBSTDelete)
		{
			tree* t = new tree();
			t->insertNode(1);
			t->insertNode(3);
			t->insertNode(4);

			t->deleteItem(1);
			t->deleteItem(3);
			t->deleteItem(4);
			t->deleteItem(5);

			bool stat = false;
			t->searchNode(4, stat);
			Assert::AreEqual(stat, false);
		}

		TEST_METHOD(testBSTSearch)
		{
			tree* t = new tree();
			t->insertNode(1);
			t->insertNode(3);
			t->insertNode(4);

			bool stat = false;
			t->searchNode(4, stat);
			Assert::AreEqual(stat, true);
		}

		TEST_METHOD(testAVLSearch)
		{
			tree* t = new avl();
			t->insertNode(1);
			t->insertNode(3);
			t->insertNode(4);

			bool stat = false;
			t->searchNode(4, stat);
			Assert::AreEqual(stat, true);
		}

		TEST_METHOD(testSplaySearch)
		{
			tree* t = new splay();
			t->insertNode(1);
			t->insertNode(3);
			t->insertNode(4);

			bool stat = false;
			t->searchNode(4, stat);
			Assert::AreEqual(stat, true);
		}

		TEST_METHOD(testTreeBoundary)
		{
			tree* t = new splay();
			t->insertNode(-200);
			t->insertNode(50);
			t->insertNode(200);

			Assert::AreEqual(t->findHeight(), 2);
		}
		
	};
}
