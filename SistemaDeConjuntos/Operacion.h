#pragma once
#include "Conjunto.h"
class Operacion
{
private:
	Conjunto _a;
	Conjunto _b;

	void backtrackDiferencia(ListaDoble<int>& a, ListaDoble<int>& b, ListaDoble<int>* resultado);
public:
	Operacion(Conjunto a, Conjunto b);
	Conjunto getA();
	Conjunto getB();
	Conjunto unionConjuntos();
	Conjunto interseccionConjuntos();
	Conjunto diferenciaConjuntos();
	Conjunto diferenciaSimetricaConjuntos();
	Conjunto complementoConjuntos();
};

