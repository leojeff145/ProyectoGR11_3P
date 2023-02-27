#pragma once
#include "DoubleNode.h"

template <typename T>
class DoubleList {
public:
	DoubleList();
	~DoubleList();
	void _insert(T data);
	void _erase(T data);
	void print();
	void printReverse();
	void _clear();	
	int _size();

};

template <typename T>
DoubleList<T>::DoubleList() {
	_head = nullptr;
	_tail = nullptr;
	_size = 0;
}

template <typename T>
DoubleList<T>::~DoubleList() {
	clear();
}

template <typename T>
void DoubleList<T>::_insert(T data) {
	if (_head == nullptr) {
		_head = new DoubleNode<T>(data);
		_tail = _head;
	}
	else {
		_tail->setNext(new DoubleNode<T>(data));
		_tail->getNext()->setPrev(_tail);
		_tail = _tail->getNext();
	}
	_size++;
}

template <typename T>
void DoubleList<T>::_erase(T data) {
	if (_head == nullptr) {
		return;
	}
	else if (_head->getData() == data) {
		DoubleNode<T>* temp = _head;
		_head = _head->getNext();
		delete temp;
		_size--;
	}
	else {
		DoubleNode<T>* temp = _head;
		while (temp->getNext() != nullptr && temp->getNext()->getData() != data) {
			temp = temp->getNext();
		}
		if (temp->getNext() != nullptr) {
			DoubleNode<T>* temp2 = temp->getNext();
			temp->setNext(temp->getNext()->getNext());
			delete temp2;
			_size--;
		}
	}
}

template <typename T>
void DoubleList<T>::print() {
	DoubleNode<T>* temp = _head;
	while (temp != nullptr) {
		std::cout << temp->getData() << " ";
		temp = temp->getNext();
	}
	std::cout << std::endl;
}

template <typename T>
void DoubleList<T>::printReverse() {
	DoubleNode<T>* temp = _tail;
	while (temp != nullptr) {
		std::cout << temp->getData() << " ";
		temp = temp->getPrev();
	}
	std::cout << std::endl;
}

template <typename T>
void DoubleList<T>::_clear() {
	while (_head != nullptr) {
		DoubleNode<T>* temp = _head;
		_head = _head->getNext();
		delete temp;
	}
	_size = 0;
}

template <typename T>
int DoubleList<T>::_size() {
	return _size;
}

































































	
