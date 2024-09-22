#pragma once

template<class T>
struct Node
{
	T value;
	Node* right;
	Node* left;

	Node(T value);
};

template class Node<int>;
