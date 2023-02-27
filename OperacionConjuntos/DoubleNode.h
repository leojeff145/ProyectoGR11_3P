#pragma once

template <typename T>
class DoubleNode {	
	public:
	DoubleNode(T data, DoubleNode<T>* next = nullptr, DoubleNode<T>* prev = nullptr);
	T getData();
	DoubleNode<T>* getNext();
	DoubleNode<T>* getPrev();
	void setNext(DoubleNode<T>* next);
	void setPrev(DoubleNode<T>* prev);

	private:
		T _data;
		DoubleNode<T>* _next;
		DoubleNode<T>* _prev;
};

template <typename T>
DoubleNode<T>::DoubleNode(T data, DoubleNode<T>* next, DoubleNode<T>* prev) {
	_data = data;
	_next = next;
	_prev = prev;
}

template <typename T>
T DoubleNode<T>::getData() {
	return _data;
}

template <typename T>
DoubleNode<T>* DoubleNode<T>::getNext() {
	return _next;
}

template <typename T>
DoubleNode<T>* DoubleNode<T>::getPrev() {
	return _prev;
}

template <typename T>
void DoubleNode<T>::setNext(DoubleNode<T>* next) {
	_next = next;
}

template <typename T>
void DoubleNode<T>::setPrev(DoubleNode<T>* prev) {
	_prev = prev;
}


