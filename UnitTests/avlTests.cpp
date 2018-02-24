#include "stdafx.h"
#include "CppUnitTest.h"
#include "CrtCheckMemory.h"
#include "avlNode.h"
#include "avlTree.h"
#include <vector>
using std::vector;

#define _CRTDBG_MAP_ALLOC

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	static vector<size_t> Traversal;

	TEST_CLASS(AVLTest)
	{
	public:
		static void Visit(avl<size_t> *node)
		{
			Traversal.push_back(node->GetData());
		}

		TEST_METHOD_INITIALIZE(Init)
		{
			Traversal.clear();
		}

		TEST_METHOD(PreOrderTest)
		{
			BinarySearchTree<size_t> myTree;
			size_t correctOrder[] = { 11, 12, 18, 20, 22, 25 };

			myTree.SetFunction(Visit);

			myTree.Insert(20);
			myTree.Insert(12);
			myTree.Insert(25);
			myTree.Insert(11);
			myTree.Insert(18);
			myTree.Insert(22);

			myTree.preorder();

			for (size_t i = 0; i < Traversal.size(); ++i)
			{
				Assert::AreEqual(correctOrder[i], Traversal[i]);
			}

		}

		TEST_METHOD(InOrderTest)
		{
			BinarySearchTree<size_t> myTree;
			size_t correctOrder[] = { 11, 12, 18, 20, 22, 25 };

			myTree.SetFunction(Visit);

			myTree.Insert(20);
			myTree.Insert(12);
			myTree.Insert(25);
			myTree.Insert(11);
			myTree.Insert(18);
			myTree.Insert(22);

			myTree.inorder();

			for (size_t i = 0; i < Traversal.size(); ++i)
			{
				Assert::AreEqual(correctOrder[i], Traversal[i]);
			}
		};
	}