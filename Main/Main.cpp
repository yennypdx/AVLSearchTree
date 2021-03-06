#include "stdafx.h"
#pragma once

#define _CRTDBG_MAP_ALLOC
#include <iostream>
#include <crtdbg.h>
#include <cassert>
#include <queue>
#include <stack>
#include <vector>
#include "avlNode.h"
#include "avlTree.h"
#include "Exception.h"
using namespace std;

void PrintTestHeader(const char *testName)
{
	cout << "\n************* " << testName << " ************" << endl;
}

void PrintTestPass(const char * test)
{
	cout << "\t" << test << ": TEST PASS" << endl;
}

void PrintTestPassForGoodMeasure(const char * test)
{
	cout << "\t" << test << ": TEST FAIL" << endl;
}

void PrintTestFail(const char * test, const char * message)
{
	cerr << message << endl;
	cerr << "\t" << test << ": TEST FAIL" << endl;;
}

void PrintTestFailForGoodMeasure(const char * test, const char * message)
{
	cerr << message << endl;
	cerr << "\t" << test << ": TEST PASS" << endl;
}

void testingGenericInsertion()
{
	const char * test = "Testing Integer Value Insertion";
	PrintTestHeader(test);

	avlTree<int> * atree = new avlTree<int>();
	cout << "Case: Inserting values of 8, 9, 10, 2, 1, 5, 3, 6, 4, 7, 11, consecutively." << endl;
	atree->insertAVL(8);
	atree->insertAVL(9);
	atree->insertAVL(10);
	atree->insertAVL(2);
	atree->insertAVL(1);
	atree->insertAVL(5);
	atree->insertAVL(3);
	atree->insertAVL(6);
	atree->insertAVL(4);
	atree->insertAVL(7);
	atree->insertAVL(11);

	try
	{
		cout << "Test tool: isEmpty()" << endl << endl;
		assert(atree->isEmpty() != true);

		PrintTestPass(test);
	}
	catch (Exception e) {
		PrintTestFail(test, e.getMessage());
	}
	delete atree;
	cout << " --------------------------------------------------------------------------------------" << endl;
}

void testingPreorder()
{
	const char * test = "Testing Preorder Method";
	PrintTestHeader(test);

	avlTree<int> * atree = new avlTree<int>();
	cout << "Case: Inserting values of 8, 9, 10, 2, 1, 5, 3, 6, 4, 7, 11, consecutively." << endl;
	atree->insertAVL(8);
	atree->insertAVL(9);
	atree->insertAVL(10);
	atree->insertAVL(2);
	atree->insertAVL(1);
	atree->insertAVL(5);
	atree->insertAVL(3);
	atree->insertAVL(6);
	atree->insertAVL(4);
	atree->insertAVL(7);
	atree->insertAVL(11);

	try {
		cout << "Test tool: isEmpty() and preorder()" << endl << endl;
		cout << "Output projection:" << endl;
		cout << "5  3  2  1  4  8  6  7  10  9  11" << endl;
		cout << "Printing elements preorder from the tree: " << endl;
		atree->preorder();

		assert(atree->isEmpty() != true);
		cout << endl << endl;
		PrintTestPass(test);
	}
	catch (Exception e)
	{
		PrintTestFail(test, e.getMessage());
	}
	delete atree;
	cout << " --------------------------------------------------------------------------------------" << endl;
}

void testingInorder()
{
	const char * test = "Testing Inorder Method";
	PrintTestHeader(test);

	avlTree<int> * atree = new avlTree<int>();
	cout << "Case: Inserting values of 8, 9, 10, 2, 1, 5, 3, 6, 4, 7, 11, consecutively." << endl;
	atree->insertAVL(8);
	atree->insertAVL(9);
	atree->insertAVL(10);
	atree->insertAVL(2);
	atree->insertAVL(1);
	atree->insertAVL(5);
	atree->insertAVL(3);
	atree->insertAVL(6);
	atree->insertAVL(4);
	atree->insertAVL(7);
	atree->insertAVL(11);

	try {
		cout << "Test tool: isEmpty() and inorder()" << endl << endl;
		cout << "Output projection:" << endl;
		cout << "1  2  3  4  5  6  7  8  9  10  11" << endl;
		cout << "Printing elements inorder from the tree: " << endl;
		atree->inorder();

		assert(atree->isEmpty() != true);
		cout << endl << endl;
		PrintTestPass(test);
	}
	catch (Exception e)
	{
		PrintTestFail(test, e.getMessage());
	}
	delete atree;
	cout << " --------------------------------------------------------------------------------------" << endl;
}

void testingPostorder()
{
	const char * test = "Testing Postorder Method";
	PrintTestHeader(test);

	avlTree<int> * atree = new avlTree<int>();
	cout << "Case: Inserting values of 8, 9, 10, 2, 1, 5, 3, 6, 4, 7, 11, consecutively." << endl;
	atree->insertAVL(8);
	atree->insertAVL(9);
	atree->insertAVL(10);
	atree->insertAVL(2);
	atree->insertAVL(1);
	atree->insertAVL(5);
	atree->insertAVL(3);
	atree->insertAVL(6);
	atree->insertAVL(4);
	atree->insertAVL(7);
	atree->insertAVL(11);

	try {
		cout << "Test tool: isEmpty() and postorder()" << endl << endl;
		cout << "Output projection:" << endl;
		cout << "1  2  4  3  7  6  9  11  10  8  5" << endl;
		cout << "Printing elements postorder from the tree: " << endl;
		atree->postorder();

		assert(atree->isEmpty() != true);
		cout << endl << endl;
		PrintTestPass(test);
	}
	catch (Exception e)
	{
		PrintTestFail(test, e.getMessage());
	}
	delete atree;
	cout << " --------------------------------------------------------------------------------------" << endl;
}

void testingBreadthfirst()
{
	const char * test = "Testing Breadth-First Method";
	PrintTestHeader(test);

	avlTree<int> * atree = new avlTree<int>();
	cout << "Case: Inserting values of 8, 9, 10, 2, 1, 5, 3, 6, 4, 7, 11, consecutively." << endl;
	atree->insertAVL(8);
	atree->insertAVL(9);
	atree->insertAVL(10);
	atree->insertAVL(2);
	atree->insertAVL(1);
	atree->insertAVL(5);
	atree->insertAVL(3);
	atree->insertAVL(6);
	atree->insertAVL(4);
	atree->insertAVL(7);
	atree->insertAVL(11);

	try {
		cout << "Test tool: isEmpty() and breadthfirst()" << endl << endl;
		cout << "Output projection:" << endl;
		cout << "5  3  8  2  4  6  10  1  7  9  11" << endl;
		cout << "Printing elements breadthfirst from the tree: " << endl;
		atree->breadthfirst();

		cout << endl << endl;
		PrintTestPass(test);
	}
	catch (Exception e)
	{
		PrintTestFail(test, e.getMessage());
	}
	delete atree;
	cout << " --------------------------------------------------------------------------------------" << endl;
}

void testingLeftSubTreeDeletion()
{
	const char * test = "Testing Left-Subtree Node Deletion";
	PrintTestHeader(test);

	avlTree<int> * atree = new avlTree<int>();
	cout << "Case: Inserting values of 8, 9, 10, 2, 1, 5, 3, 6, 4, 7, 11, consecutively." << endl;
	atree->insertAVL(8);
	atree->insertAVL(9);
	atree->insertAVL(10);
	atree->insertAVL(2);
	atree->insertAVL(1);
	atree->insertAVL(5);
	atree->insertAVL(3);
	atree->insertAVL(6);
	atree->insertAVL(4);
	atree->insertAVL(7);
	atree->insertAVL(11);

	try {
		cout << "Test tool: isEmpty(), findAndDeleteNode() and inorder()" << endl << endl;
		cout << "Deleting 3 from the tree..." << endl;
		atree->deleteAVL(3);
		cout << "Output projection:" << endl;
		cout << "1  2  4  5  6  7  8  9  10  11" << endl;
		cout << "Printing elements after deletion from the tree: " << endl;
		atree->inorder();

		assert(atree->isEmpty() != true);
		cout << endl << endl;
		PrintTestPass(test);
	}
	catch (Exception e)
	{
		PrintTestFail(test, e.getMessage());
	}
	delete atree;
	cout << " --------------------------------------------------------------------------------------" << endl;
}

void testingRightSubTreeDeletion()
{
	const char * test = "Testing Right-Subtree Node Deletion";
	PrintTestHeader(test);

	avlTree<int> * atree = new avlTree<int>();
	cout << "Case: Inserting values of 8, 9, 10, 2, 1, 5, 3, 6, 4, 7, 11, consecutively." << endl;
	atree->insertAVL(8);
	atree->insertAVL(9);
	atree->insertAVL(10);
	atree->insertAVL(2);
	atree->insertAVL(1);
	atree->insertAVL(5);
	atree->insertAVL(3);
	atree->insertAVL(6);
	atree->insertAVL(4);
	atree->insertAVL(7);
	atree->insertAVL(11);

	try {
		cout << "Test tool: isEmpty(), findAndDeleteNode() and inorder()" << endl << endl;
		cout << "Deleting 10 from the tree..." << endl;
		atree->deleteAVL(10);
		cout << "Output projection:" << endl;
		cout << "1  2  3  4  5  6  7  8  9  11" << endl;
		cout << "Printing elements after deletion from the tree: " << endl;
		atree->inorder();

		assert(atree->isEmpty() != true);
		cout << endl << endl;
		PrintTestPass(test);
	}
	catch (Exception e)
	{
		PrintTestFail(test, e.getMessage());
	}
	delete atree;
	cout << " --------------------------------------------------------------------------------------" << endl;
}

void testingPurgeTree()
{
	const char * test = "Testing Tree Purging Method";
	PrintTestHeader(test);

	avlTree<int> * atree = new avlTree<int>();
	cout << "Case: Inserting values of 8, 9, 10, 2, 1, 5, 3, 6, 4, 7, 11, consecutively." << endl;
	atree->insertAVL(8);
	atree->insertAVL(9);
	atree->insertAVL(10);
	atree->insertAVL(2);
	atree->insertAVL(1);
	atree->insertAVL(5);
	atree->insertAVL(3);
	atree->insertAVL(6);
	atree->insertAVL(4);
	atree->insertAVL(7);
	atree->insertAVL(11);

	try {
		cout << "Test tool: purgeTree() and isEmpty()" << endl << endl;
		atree->purgeTree(atree->getRoot());

		assert(atree->isEmpty() == true);
		cout << "Tree is flushed.";
		cout << endl << endl;
		PrintTestPass(test);
	}
	catch (Exception e)
	{
		PrintTestFail(test, e.getMessage());
	}
	delete atree;
	cout << " --------------------------------------------------------------------------------------" << endl;
}
//Rainy day tests
void testingUnavailValueDeletion()
{
	const char * test = "Testing Unlisted Data Deletion";
	PrintTestHeader(test);

	avlTree<int> * atree = new avlTree<int>();
	cout << "Case: Inserting values of 8, 9, 10, 2, 1, 5, 3, 6, 4, 7, 11, consecutively." << endl;
	atree->insertAVL(8);
	atree->insertAVL(9);
	atree->insertAVL(10);
	atree->insertAVL(2);
	atree->insertAVL(1);
	atree->insertAVL(5);
	atree->insertAVL(3);
	atree->insertAVL(6);
	atree->insertAVL(4);
	atree->insertAVL(7);
	atree->insertAVL(11);

	cout << "Test tool: inorder() and isEmpty()" << endl;

	try {
		cout << endl << "Deleting 12 from the tree..." << endl;
		atree->deleteAVL(12);
		cout << endl << endl;
		PrintTestPassForGoodMeasure(test);
	}
	catch (Exception e)
	{
		PrintTestFailForGoodMeasure(test, e.getMessage());
	}
	delete atree;
	cout << " --------------------------------------------------------------------------------------" << endl;
}

void testingEmptyTreeDeletion()
{
	const char * test = "Testing Empty Tree Deletion";
	PrintTestHeader(test);

	avlTree<int> * atree = new avlTree<int>();
	cout << "Case: Creating a tree with no values." << endl;
	cout << "Test tool: findAndDeleteNode()" << endl << endl;

	try
	{
		cout << "Deleting 11 from the tree..." << endl;
		atree->deleteAVL(11);

		assert(atree->isEmpty() == true);
		cout << endl << endl;
		PrintTestPassForGoodMeasure(test);
	}
	catch (Exception e)
	{
		PrintTestFailForGoodMeasure(test, e.getMessage());
	}
	delete atree;
	cout << " --------------------------------------------------------------------------------------" << endl;
}

void RunTest()
{
	testingGenericInsertion();
	testingPreorder();
	testingInorder();
	testingPostorder();
	testingBreadthfirst();
	testingLeftSubTreeDeletion();
	testingRightSubTreeDeletion();
	testingPurgeTree();
	testingUnavailValueDeletion();
	testingEmptyTreeDeletion();
}

int main() {

	RunTest();
	
	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDOUT);
	_CrtDumpMemoryLeaks();

	system("pause");
	return 0;
}