#include "Node.h"

template <class T>
Node<T>::Node(T value) {
	this->value = value;
	left = right = nullptr;
}

