#pragma once
#include "Conjunto.h"
#include <vector>
class DiagramaVenn
{
private:
	Conjunto _a;
	Conjunto _b;
	Conjunto _izquierda;
	Conjunto _derecha;
	Conjunto _interseccion;

	void calcular();
public: 
	DiagramaVenn(Conjunto a, Conjunto b);

	std::vector<int> getIzquierda();
	std::vector<int> getDerecha();
	std::vector<int> getInterseccion();
};

