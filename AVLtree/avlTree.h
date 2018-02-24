#include "stdafx.h"
#pragma once
#ifndef  AVLTREE_H
#define AVLTREE_H

#include <queue>
#include <stack>
#include <vector>
#include <iostream>
#include "Exception.h"
#include "avlNode.h"
using namespace std;

template<typename T>
class Stack : public stack<T>
{};

template<typename T>
class Queue : public queue<T>
{
public:
	T dequeue()
	{
		T tempQueue = queue<T>::front();
		queue<T>::pop();

		return tempQueue;
	}

	void enqueue(const T & inVal)
	{
		queue<T>::push(inVal);
	}
};

template<typename T>
class avlTree 
{
public:
	avlTree() { m_root = nullptr; }
	~avlTree();
public:
	void SetFunction(void (*visit) (avlNode<T>* node)) { m_visit = visit; }
	void preorder() { preorder(m_root); }
	void inorder() { inorder(m_root); }
	void postorder() { postorder(m_root); }
	void breadthfirst();
	void insertAVL(T inElm) { m_insertAVL(m_root, inElm); }
	void deleteAVL(T inElm) { findAndDeleteAVL(m_root, inElm); }
public:
	avlNode<T> * getRoot() { return m_root; }
	bool isEmpty() const;
	T * search(avlNode<T> * inNode, const T & inElm) const;
public:
	int nodeDepth(avlNode<T> * inNode);
	void purgeTree(avlNode<T> * inNode);
public:
	bool isBalance(avlNode<T>* &inNode);
	avlNode<T> * rightRotation(avlNode<T> * &inNode);
	avlNode<T> * twiceRightRotation(avlNode<T> * &inNode);
	avlNode<T> * leftRotation(avlNode<T> * &inNode);
	avlNode<T> * twiceLeftRotation(avlNode<T> * &inNode);
	avlNode<T> * findLargestValueNode(avlNode<T> * inNode);
	avlNode<T> * findSmallestValueNode(avlNode<T> * inNode);
public:
	avlNode<T> * m_insertAVL(avlNode<T> * & inNode, T inElm);
	void insertRecursively(avlNode<T>* inNode, T inElm);
	avlNode<T> * deleteLeftBalance(avlNode<T>* inNode);
	avlNode<T> * deleteRightBalance(avlNode<T>* inNode);
	avlNode<T> * findAndDeleteAVL(avlNode<T>* inNode, const T & inElm);

private:
	avlNode<T> * m_root;
	void(*m_visit)(avlNode<T> * inNode);
	void preorder(avlNode<T> * inNode);
	void inorder(avlNode<T> * inNode);
	void postorder(avlNode<T> * inNode);
	virtual void visit(avlNode<T> * inNode) { inNode->elementVal; }

};

template<typename T>
inline avlTree<T>::~avlTree()
{
	purgeTree(m_root);
}

template<typename T>
inline bool avlTree<T>::isEmpty() const
{
	return m_root == nullptr;
}

template<typename T>	
inline T * avlTree<T>::search(avlNode<T>* inNode, const T & inElm) const
{
	while (inNode != nullptr)
	{
		if (inElm == inNode->elementVal) {
				return &inNode->elementVal;
		}
		else if (inElm < inNode->elementVal) {
			return search(inNode->left, inElm);
		}
		else if (inElm > inNode->elementVal) {
			return search(inNode->right, inElm);
		}
	}
	return nullptr;
}

template<typename T>
inline int avlTree<T>::nodeDepth(avlNode<T>* inNode)
{
	if (inNode == nullptr) {
		return -1;
	}

	int leftDepth = nodeDepth(inNode->left);
	int rightDepth = nodeDepth(inNode->right);
	int totalDepth = max(leftDepth, rightDepth) + 1;

	return totalDepth;
}

template<typename T>
inline void avlTree<T>::purgeTree(avlNode<T>* inNode)
{
	while (inNode != nullptr)
	{
		m_root = inNode;
		if (inNode->left != nullptr) {
			purgeTree(inNode->left);
		}
		if (inNode->right != nullptr) {
			purgeTree(inNode->right);
		}

		delete inNode;
		inNode = nullptr;
		m_root = nullptr;
	}
}

template<typename T>
inline bool avlTree<T>::isBalance(avlNode<T>* &inNode)
{
	bool balance = true;
	if (nodeDepth(inNode->left) - nodeDepth(inNode->right) <= -2 || 
		nodeDepth(inNode->left) - nodeDepth(inNode->right) >= 2)
	{
		balance = false;
	}
	return balance;
}

template<typename T>
inline avlNode<T>* avlTree<T>::rightRotation(avlNode<T>* &inNode)
{
	avlNode<T> * movingNode = inNode->left;
	inNode->left = movingNode->right;
	movingNode->right = inNode;
	
	inNode->m_depth = max(nodeDepth(inNode->left), nodeDepth(inNode->right)) + 1;
	movingNode->m_depth = max(nodeDepth(inNode->left), inNode->m_depth) + 1;

	return movingNode;
}

template<typename T>
inline avlNode<T>* avlTree<T>::twiceRightRotation(avlNode<T>*& inNode)
{
	inNode->left = leftRotation(inNode->left);
	return rightRotation(inNode);
}

template<typename T>
inline avlNode<T>* avlTree<T>::leftRotation(avlNode<T>* &inNode)
{
	avlNode<T> * movingNode = inNode->right;
	inNode->right = movingNode->left;	
	movingNode->left = inNode;

	inNode->m_depth = max(nodeDepth(inNode->left), nodeDepth(inNode->right)) + 1;
	movingNode->m_depth = max(nodeDepth(inNode->right), inNode->m_depth) + 1;

	return movingNode;
}

template<typename T>
inline avlNode<T>* avlTree<T>::twiceLeftRotation(avlNode<T>*& inNode)
{
	inNode->right = rightRotation(inNode->right);
	return leftRotation(inNode);
}

template<typename T>
inline avlNode<T>* avlTree<T>::findSmallestValueNode(avlNode<T>* inNode)
{
	if (inNode == nullptr) {
		return nullptr;
	}
	else if (inNode->left == nullptr) {
		return inNode;
	}
	else {
		return findSmallestValueNode(inNode->left);
	}
}

template<typename T>
inline avlNode<T>* avlTree<T>::findLargestValueNode(avlNode<T>* inNode)
{
	if (inNode == nullptr) {
		return nullptr;
	}
	else if (inNode->right == nullptr) {
		return inNode;
	}
	else {
		return findLargestValueNode(inNode->right);
	}
}

template<typename T>
inline avlNode<T> * avlTree<T>::m_insertAVL(avlNode<T> * & inNode, T inElm)
{
	if (inNode == nullptr) { 
		inNode = new avlNode<T>();
		inNode->elementVal = inElm;
	}
	
	if (inElm < inNode->elementVal)
	{
		inNode->left = m_insertAVL(inNode->left, inElm);	// Left subtree
		if (!isBalance(inNode))
		{
			if (inElm < inNode->left->elementVal) {
				inNode = rightRotation(inNode);
			}
			else {
				inNode = twiceRightRotation(inNode);
			}
		}
	}
	else if (inElm > inNode->elementVal)
	{
		inNode->right = m_insertAVL(inNode->right, inElm);	// Right subtree 
		if (!isBalance(inNode))
		{
			if (inElm > inNode->right->elementVal) {
				inNode = leftRotation(inNode);
			}
			else {
				inNode = twiceLeftRotation(inNode);
			}
		}
	}
	inNode->m_depth = max(nodeDepth(inNode->left), nodeDepth(inNode->right)) + 1;
	return inNode;
}

template<typename T>
inline void avlTree<T>::insertRecursively(avlNode<T>* inNode, T inElm)
{
	if (inNode == nullptr) {
		avlNode<T>* newNode;
		newNode->elementVal = inElm;
		newNode = inNode;

		delete newNode;
	}
	else {
		if (inElm < inNode->elementVal) {
			insertRecursively(inNode->left, inElm);
		}
		else {
			insertRecursively(inNode->right, inElm);
		}
	}
}

template<typename T>
inline avlNode<T> * avlTree<T>::deleteLeftBalance(avlNode<T>* inNode)
{
	avlNode<T> * tempContainer = inNode;

	if (!isBalance(inNode)) {
		inNode->left->left = inNode->left;

		if ((nodeDepth(inNode->left->left) - nodeDepth(inNode->left->right)) == 1) {
			return leftRotation(inNode);    //Right-Right case
		}
		else {
			return twiceLeftRotation(inNode);   //Right-Left case
		}
		delete tempContainer;
	}
	return inNode;
}

template<typename T>
inline avlNode<T> * avlTree<T>::deleteRightBalance(avlNode<T>* inNode)
{
	avlNode<T> * tempContainer = inNode;

	if (!isBalance(inNode)) {
		inNode->right->right = inNode->right;

		if ((nodeDepth(inNode->right->right) - nodeDepth(inNode->right->left)) == 1) {
			return rightRotation(inNode);	//Left-Left case
		}
		else {
			return twiceRightRotation(inNode);	//Left-Right case
		}
		delete tempContainer;
	}
	return inNode;
}

template<typename T>
inline avlNode<T> * avlTree<T>::findAndDeleteAVL(avlNode<T>* inNode, const T & inElm)
{
	if (inNode == nullptr) {
		throw Exception("Exception caught: Tree is empty or the element is unlisted on the tree.");
	}
	
	if (inElm < inNode->elementVal) {
		inNode->left = findAndDeleteAVL(inNode->left, inElm);

		if (nodeDepth(inNode->left) > nodeDepth(inNode->right)) {
			inNode = deleteRightBalance(inNode);
		}
	}	
	else if (inElm > inNode->elementVal) {
		inNode->right = findAndDeleteAVL(inNode->right, inElm);

		if (nodeDepth(inNode->right) > nodeDepth(inNode->left)) {
			inNode = deleteLeftBalance(inNode);
		}
	}	//node to delete is found
	else if (inElm == inNode->elementVal) {	
		avlNode<T> * nodeToDelete = nullptr;
		avlNode<T> * successorNode = nullptr;
		//node has NO right-sub (1 child)
		if (inNode->right == nullptr) {	 
			inNode = inNode->left;
		}	//node has NO left-sub (1 child)
		else if (inNode->left == nullptr) { 
			inNode = inNode->right;
		}
		else {  //node has right-left-subs (2 children)
			nodeToDelete = inNode;
			successorNode = findLargestValueNode(inNode->left); 
			//re-attach the right-sub to the successor node
			successorNode->right = findLargestValueNode(inNode->right); 
			inNode = successorNode;
			
			if (!isBalance(inNode)) {
				inNode = deleteRightBalance(inNode);
			}
		}
		delete nodeToDelete;
	}
	return inNode; 
}

template<typename T>
inline void avlTree<T>::preorder(avlNode<T>* inNode)
{
	if (inNode != nullptr) {
		visit(inNode);
		cout << inNode->elementVal << "  ";
		preorder(inNode->left);
		preorder(inNode->right);
	}
}

template<typename T>
inline void avlTree<T>::inorder(avlNode<T>* inNode)
{
	if (inNode != nullptr) {
		inorder(inNode->left);
		visit(inNode);
		cout << inNode->elementVal << "  ";
		inorder(inNode->right);
	}
}

template<typename T>
inline void avlTree<T>::postorder(avlNode<T>* inNode)
{
	if (inNode != nullptr) {
		postorder(inNode->left);
		postorder(inNode->right);
		visit(inNode);
		cout << inNode->elementVal << "  ";
	}
}

template<typename T>
inline void avlTree<T>::breadthfirst()
{
	Queue<avlNode<T> *>  queue;
	avlNode<T> * traverse = m_root;

	if (traverse != nullptr) {
		queue.enqueue(traverse);

		while (!queue.empty())
		{
			traverse = queue.dequeue();
			cout << traverse->elementVal << "  ";

			if (traverse->left != nullptr) {
				queue.enqueue(traverse->left);
			}
			if (traverse->right != nullptr) {
				queue.enqueue(traverse->right);
			}
		}
	}
}

#endif