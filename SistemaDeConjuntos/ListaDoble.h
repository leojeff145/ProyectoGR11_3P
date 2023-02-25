#pragma once
#include "NodoDoble.h"

template <typename T>
class ListaDoble
{
private:
	NodoDoble<T>* cabeza;
	NodoDoble<T>* cola;
	int tamanio;
public:
	ListaDoble();
	~ListaDoble();
	bool estaVacia();
	int getTamanio();
	NodoDoble<T>* getCabeza();
	NodoDoble<T>* getCola();
	void insertarInicio(T dato);
	void insertarFinal(T dato);
	void insertarPosicion(T dato, int posicion);
	void eliminarInicio();
	void eliminarFinal();
	void eliminarPosicion(int posicion);
	void mostrar();
	void ordenarAscendente();
};

template <typename T>
ListaDoble<T>::ListaDoble()
{
	this->cabeza = nullptr;
	this->cola = nullptr;
	this->tamanio = 0;
}

template <typename T>
ListaDoble<T>::~ListaDoble()
{
}

template <typename T>
bool ListaDoble<T>::estaVacia()
{
	return this->cabeza == nullptr;
}

template <typename T>
int ListaDoble<T>::getTamanio()
{
	return this->tamanio;
}

template <typename T>
NodoDoble<T>* ListaDoble<T>::getCabeza()
{
	return this->cabeza;
}

template <typename T>
NodoDoble<T>* ListaDoble<T>::getCola()
{
	return this->cola;
}

template <typename T>
void ListaDoble<T>::insertarInicio(T dato)
{
	NodoDoble<T>* nuevo = new NodoDoble<T>(dato);
	if (estaVacia())
	{
		this->cola = nuevo;
	}
	else
	{
		this->cabeza->setAnterior(nuevo);
		nuevo->setSiguiente(this->cabeza);
	}
	this->cabeza = nuevo;
	this->tamanio++;
}

template <typename T>
void ListaDoble<T>::insertarFinal(T dato)
{
	NodoDoble<T>* nuevo = new NodoDoble<T>(dato);
	if (estaVacia())
	{
		this->cabeza = nuevo;
	}
	else
	{
		this->cola->setSiguiente(nuevo);
		nuevo->setAnterior(this->cola);
	}
	this->cola = nuevo;
	this->tamanio++;
}

template <typename T>
void ListaDoble<T>::insertarPosicion(T dato, int posicion)
{
	if (posicion < 0 || posicion > this->tamanio)
	{
		throw "Posicion no valida";
	}
	else if (posicion == 0)
	{
		insertarInicio(dato);
	}
	else if (posicion == this->tamanio)
	{
		insertarFinal(dato);
	}
	else
	{
		NodoDoble<T>* nuevo = new NodoDoble<T>(dato);
		NodoDoble<T>* aux = this->cabeza;
		for (int i = 0; i < posicion; i++)
		{
			aux = aux->getSiguiente();
		}
		nuevo->setSiguiente(aux);
		nuevo->setAnterior(aux->getAnterior());
		aux->getAnterior()->setSiguiente(nuevo);
		aux->setAnterior(nuevo);
		this->tamanio++;
	}
}

template <typename T>
void ListaDoble<T>::eliminarInicio()
{
	if (estaVacia())
	{
		throw "Lista vacia";
	}
	else if (this->cabeza == this->cola)
	{
		this->cabeza = nullptr;
		this->cola = nullptr;
	}
	else
	{
		this->cabeza = this->cabeza->getSiguiente();
		this->cabeza->setAnterior(nullptr);
	}
	this->tamanio--;
}

template <typename T>
void ListaDoble<T>::eliminarFinal()
{
	if (estaVacia())
	{
		throw "Lista vacia";
	}
	else if (this->cabeza == this->cola)
	{
		this->cabeza = nullptr;
		this->cola = nullptr;
	}
	else
	{
		this->cola = this->cola->getAnterior();
		this->cola->setSiguiente(nullptr);
	}
	this->tamanio--;
}

template <typename T>
void ListaDoble<T>::eliminarPosicion(int posicion)
{
	if (estaVacia())
	{
		throw "Lista vacia";
	}
	else if (posicion < 0 || posicion >= this->tamanio)
	{
		throw "Posicion no valida";
	}
	else if (posicion == 0)
	{
		eliminarInicio();
	}
	else if (posicion == this->tamanio - 1)
	{
		eliminarFinal();
	}
	else
	{
		NodoDoble<T>* aux = this->cabeza;
		for (int i = 0; i < posicion; i++)
		{
			aux = aux->getSiguiente();
		}
		aux->getAnterior()->setSiguiente(aux->getSiguiente());
		aux->getSiguiente()->setAnterior(aux->getAnterior());
		this->tamanio--;
	}
}

template <typename T>
void ListaDoble<T>::mostrar()
{
	NodoDoble<T>* aux = this->cabeza;
	while (aux != nullptr)
	{
		cout << aux->getDato() << " ";
		aux = aux->getSiguiente();
	}
	cout << endl;
}

template <typename T>
void ListaDoble<T>::ordenarAscendente()
{
	NodoDoble<T>* aux = this->cabeza;
	while (aux != nullptr)
	{
		NodoDoble<T>* aux2 = aux->getSiguiente();
		while (aux2 != nullptr)
		{
			if (aux->getDato() > aux2->getDato())
			{
				T auxDato = aux->getDato();
				aux->setDato(aux2->getDato());
				aux2->setDato(auxDato);
			}
			aux2 = aux2->getSiguiente();
		}
		aux = aux->getSiguiente();
	}
}


