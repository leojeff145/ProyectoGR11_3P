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
	Lista_Doble();
	~Lista_Doble();
	bool estaVacia();
	int getTamanio();
	void insertarInicio(T dato);
	void insertarFinal(T dato);
	void insertarPosicion(T dato, int posicion);
	void eliminarInicio();
	void eliminarFinal();
	void eliminarPosicion(int posicion);
	void mostrar();
};
