#pragma once
#include "Node.h"

template <class T>
class BST
{
	Node<T>* root;
	void dfs(Node<T>* curr);
	void BFS(Node<T>* curr);
public:
	BST();
	bool find(T value);
	void insert(T value);
	void erase(T value);
	void print();
	~BST();
};

template class BST<int>;