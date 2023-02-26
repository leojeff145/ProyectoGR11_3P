#include "Operacion.h"

Operacion::Operacion(Conjunto a, Conjunto b)
{
	_a = a;
	_b = b;
}

Conjunto Operacion::getA()
{
	return _a;
}

Conjunto Operacion::getB()
{
	return _b;
}

Conjunto Operacion::unionConjuntos() {
	//se crea una cipia de _a para no modificar el conjunto original
	ListaDoble<int> resultado = _a.getDato();

	//se recorre _b y se agrega sus elementos si no estan
	NodoDoble<int>* actual_b = _b.getDato().getCabeza();
	while (actual_b != nullptr) {
		if (!resultado.buscar(actual_b->getDato())) {
			resultado.insertarFinal(actual_b->getDato());
		}
		actual_b = actual_b->getSiguiente();
	}

	// se crea un nuevo objeto conjunto con el resultado y se retorna
	Conjunto conjunto_resultado(resultado,"Union de" + _a.getEtiqueta() + "y" + _b.getEtiqueta());
	return conjunto_resultado;
}

Conjunto Operacion::interseccionConjuntos() {
	ListaDoble<int> resultado;

	for (NodoDoble<int>* nodoA = _a.getDato().getCabeza(); nodoA != nullptr; nodoA->getSiguiente()) {
		if (_b.getDato().buscar(nodoA->getDato())) {
			resultado.insertarFinal(nodoA->getDato());
		}
	}
	return Conjunto(resultado);
}

Conjunto Operacion::diferenciaConjuntos() {
	ListaDoble<int> resultado;
	ListaDoble<int> a = _a.getDato();
	ListaDoble<int> b = _b.getDato();

	backtrackDiferencia(a, b, &resultado);
	return Conjunto(resultado);
}

void Operacion::backtrackDiferencia(ListaDoble<int>& a, ListaDoble<int>& b, ListaDoble<int>* resultado) {
	if (a.getTamanio() == 0) {
		resultado->vaciar();
		return;
	}

	int x = a.getCabeza()->getDato();
	a.eliminarDato(x);

	backtrackDiferencia(a, b, resultado);

	if (!b.buscar(x)) {
		resultado->insertarFinal(x);
	}

	backtrackDiferencia(a, b, resultado);

	a.insertarFinal(x);		 
}

Conjunto Operacion::diferenciaSimetricaConjuntos() {
	ListaDoble<int> resultado;
	ListaDoble<int> a = _a.getDato();
	ListaDoble<int> b = _b.getDato();

	//Iterar los elementos de a
	NodoDoble<int>* actual = a.getCabeza();
	while (actual != nullptr) {
		// si el elemento no esta en b, se agrega a resultado
		if (!b.buscar(actual->getDato())) {
			resultado.insertarFinal(actual->getDato());
		}
		actual = actual->getSiguiente();
	}

	//iterar por los elemtos de b
	actual = b.getCabeza();
	while (actual != nullptr) {
		// si el elemento no esta en a, se agrega a resultado
		if (!a.buscar(actual->getDato())) {
			resultado.insertarFinal(actual->getDato());
		}
		actual = actual->getSiguiente();
	}

	return Conjunto(resultado);
}

Conjunto Operacion::complementoConjuntos() {
	ListaDoble<int>& a = _a.getDato();
	ListaDoble<int>& b = _b.getDato();
	ListaDoble<int> complemento;

	NodoDoble<int>* actual = b.getCabeza();
	while (actual != nullptr) {
		int elem = actual->getDato();
		if (a.buscar(elem) == -1) {
			complemento.insertarFinal(elem);
		}
		actual = actual->getSiguiente();
	}

	return Conjunto(complemento);
}