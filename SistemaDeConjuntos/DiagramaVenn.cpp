#include "DiagramaVenn.h"
#include "Operacion.h"

DiagramaVenn::DiagramaVenn(Conjunto a, Conjunto b) : _a(a), _b(b)
{
	calcular();
}

std::vector<int> DiagramaVenn::getIzquierda()
{	
	return _izquierda.getComoVector();
}

std::vector<int> DiagramaVenn::getDerecha()
{
	return _derecha.getComoVector();
}

std::vector<int> DiagramaVenn::getInterseccion()
{
	return _interseccion.getComoVector();
}

void DiagramaVenn::calcular()
{
	// A - B
	Operacion op(_a, _b);
	_izquierda = op.diferenciaConjuntos();

	// B - A
	op = Operacion(_b, _a);
	_derecha = op.diferenciaConjuntos();

	// A ^ B
	op = Operacion(_a, _b);
	_interseccion = op.interseccionConjuntos();
}