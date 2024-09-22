#include "BST.h"
#include <iostream>
#include <queue>
using namespace std;

template<class T>
BST<T>::BST() {
	root = nullptr;
}


template <class T>
bool BST<T>::find(T value) {
	Node<T> * curr = root;
	while (curr != nullptr)
	{
		if (value == curr->value) {
			return true;
		}
		if (value > curr->value) {
			curr = curr->right;
		}
		else {
			curr - curr->left;
		}
	}
	return false;
}


template <class T>
void BST<T>::insert(T value) {
	if (find(value)) {
		return;
	}
	Node<T>* newNode = new Node<T>(value);
	if (root == nullptr) {
		root = newNode;
		return;
	}
	Node<T>* curr = root;
	Node<T>* parent = root;
	while (curr != nullptr) {
		parent = curr;
		if (value > curr->value) {
			curr = curr->right;
		}
		else {
			curr = curr->left;
		}
	}
	if (value > parent->value) {
		parent->right = newNode;
	}
	else {
		parent->left = newNode;
	}
}

template <class T>
void BST<T>::erase(T value) {
	if (!find(value)) {
		return;
	}
	Node<T>* curr = root;
	Node<T>* parent = root;
	while (curr->value != value) {
		parent = curr;
		if (value > curr->value) {
			curr = curr->right;
		}
		else {
			curr = curr->left;
		}
	}
	///parent, curr-> Node to be deleted
	///1) leaf node
	if (curr->right == nullptr && curr->left == nullptr) {

		if (curr == root) {
			delete curr;
			root = nullptr;
			return;
		}
	
		if (value > parent->value) {
			parent->right = nullptr;
		}
		else {
			parent->left = nullptr;
		}
		delete curr;
	}
	else if (curr->right != nullptr && curr->left == nullptr) {
		if (curr == root) {
			root = root->right;
			delete curr;
			return;
		}
		if (value > parent->value) {
			parent->right = curr->right;

		}
		else {
			parent->left = curr->right;
		}
		delete curr;
	}
	else if (curr->left != nullptr && curr->right == nullptr) {
		
		if (curr == root) {
			root = root->left;
			delete curr;
			return;
		}
		if (value > parent->value) {
			parent->right = curr->left;
		}
		else {
			parent->left = curr->left;
		}
		delete curr;
	}
	else {
		Node<T>* p2 = curr;
		Node<T>* c2 = curr->right;
		while (c2->left != nullptr) {
			p2 = c2;
			c2 = c2->left;
		}
		if (c2->value > p2->value) {
			p2->right = c2->right;

		}
		else {
			p2->left = c2->right;
		}
		curr->value = c2->value;
		delete c2;
	}
}
template<class T>
void BST<T>::dfs(Node<T>* curr) {
	if (curr == nullptr) {
		return;
	}
	dfs(curr->right);
	cout << curr->value<<endl;
	dfs(curr->left);
	
}
template <class T>
void BST<T>::BFS(Node<T>* curr) {
	queue<Node<T>*> q;
	q.push(curr);
	while (!q.empty()) {
		Node<T> *front = q.front();
		cout << front->value << endl;
		if (front->left != nullptr) {
			q.push(front->left);
		}
		if (front->right != nullptr) {
			q.push(front->right);
		}
		q.pop();
	}

}
template<class T>
void BST<T>::print() {
	BFS(root);
}
template<class T>
BST<T> :: ~BST() {
	while (root!= nullptr) {
		erase(root->value);
	}
}


