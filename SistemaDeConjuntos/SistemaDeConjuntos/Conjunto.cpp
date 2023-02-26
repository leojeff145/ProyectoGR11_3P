#include "Conjunto.h"
#include <iostream>

Conjunto::Conjunto(ListaDoble<int> dato, std::string etiqueta) : _dato(dato), _etiqueta(etiqueta) {}

Conjunto::Conjunto(std::string etiqueta) : _etiqueta(etiqueta) {}

void Conjunto::insertar(int n)
{
	_dato.insertarFinal(n);
}

ListaDoble<int>& Conjunto::getDato()
{
	return _dato;
}

std::vector<int> Conjunto::getComoVector() {
	std::vector<int> vec;
	NodoDoble<int>* actual = _dato.getCabeza();
	while (actual != nullptr) {
		vec.push_back(actual->getDato());
		actual = actual->getSiguiente();
	}
	return vec;
}

std::string Conjunto::getEtiqueta()
{
	return _etiqueta;
}

int Conjunto::_tamanio()
{
	return _dato.getTamanio();
}
