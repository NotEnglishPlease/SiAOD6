#include "List.h"
#include <iostream>

using namespace std;

template<typename T>
List<T>::List()
{
	size = 0;
	head = nullptr;
}

template<typename T>
size_t List<T>::getSize()
{
	return this->size;
}

template<typename T>
T& List<T>::operator[](size_t index)
{
	size_t counter = 0;
	Node<T>* current = this->head;
	while (current != nullptr) {
		if (counter == index)
		{
			return current->data;
		}
		current = current->ptrNext;
		counter++;
	}
}

template<typename T>
void List<T>::pushBack(T data)
{
	if (head == nullptr)
	{
		head = new Node<T>(data);
	}
	else
	{
		Node<T>* current = this->head;

		while (current->ptrNext != nullptr)
		{
			current = current->ptrNext;
		}
		current->ptrNext = new Node<T>(data);
	}
	this->size++;
}