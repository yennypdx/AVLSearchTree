#include "stdafx.h"
#pragma once
#ifndef  AVLNODE_H
#define AVLNODE_H

#include <iostream>
using namespace std;

template<typename T>
class avlNode
{
public:
	avlNode();
	avlNode(const T & newVal);
	~avlNode();
public:
	int max(int node1, int node2);

public:
	T elementVal;
	int m_depth;
	avlNode<T> * left;
	avlNode<T> * right;
	
};

template<typename T>
inline avlNode<T>::avlNode()
{
	m_depth = 0;
	left = nullptr;
	right = nullptr;
}

template<typename T>
inline avlNode<T>::avlNode(const T & newVal)
{
	elementVal = newVal;
	m_depth = 0;
	left = nullptr;
	right = nullptr;
}

template<typename T>
inline avlNode<T>::~avlNode()
{
	left = nullptr;
	right = nullptr;
}

template<typename T>
inline int avlNode<T>::max(int node1, int node2)
{
	return  (node1 > node2)? node1: node2;
}

#endif 