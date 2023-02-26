#pragma once
#include "Operacion.h"
#include "DiagramaVenn.h"
#include <string>
#include <vector>
#include <optional>
#include <map>
#include <tuple>

class AplicacionConjuntos
{
private:
	void hacerUnion();
	void hacerInterseccion();	
	void hacerDiferencia();
	void hacerDiferenciaSimetrica();
	void hacerComplemento();

	void dibujarBase(Operacion operacion, DiagramaVenn dv);
	void dibujarUnion(Operacion operacion, DiagramaVenn dv);
	void dibujarInterseccion(Operacion operacion, DiagramaVenn dv);
	void dibujarDiferencia(Operacion operacion, DiagramaVenn dv,bool esIzquierdo = true);
	void dibujarDiferenciaSimetrica(Operacion operacion, DiagramaVenn dv);
	void dibujarComplemento(Operacion operacion, DiagramaVenn dv, bool esIzquierdo = true);
	std::optional<int> scan_int(std::string mensaje,int valorMin, int valMaximo,bool permitirVac = true);
	Conjunto scan_conjunto(std::string mensaje, std::string etiqueta);
	

	std::map<std::string, std::vector<std::tuple<int, int>>> posicion_diagrama;

public:
	AplicacionConjuntos();
	void iniciar();
	void correrMenu();
};