#pragma once
template <typename T>
class NodoDoble
{
private: 
	T dato;
	NodoDoble<T>* siguiente;
	NodoDoble<T>* anterior;
public:
	NodoDoble(T dato);
	~NodoDoble();
	void setDato(T dato);
	void setSiguiente(NodoDoble<T>* siguiente);
	void setAnterior(NodoDoble<T>* anterior);
	T getDato();
	NodoDoble<T>* getSiguiente();
	NodoDoble<T>* getAnterior();	
};

template <typename T>
NodoDoble<T>::NodoDoble(T dato)
{
	this->dato = dato;
	this->siguiente = nullptr;
	this->anterior = nullptr;
}

template <typename T>
NodoDoble<T>::~NodoDoble()
{
}

template <typename T>
void NodoDoble<T>::setDato(T dato)
{
	this->dato = dato;
}

template <typename T>
void NodoDoble<T>::setSiguiente(NodoDoble<T>* siguiente)
{
	this->siguiente = siguiente;
}

template <typename T>
void NodoDoble<T>::setAnterior(NodoDoble<T>* anterior)
{
	this->anterior = anterior;
}

template <typename T>
T NodoDoble<T>::getDato()
{
	return this->dato;
}

template <typename T>
NodoDoble<T>* NodoDoble<T>::getSiguiente()
{
	return this->siguiente;
}

template <typename T>
NodoDoble<T>* NodoDoble<T>::getAnterior()
{
	return this->anterior;
}

