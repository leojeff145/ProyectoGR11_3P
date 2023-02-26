#pragma once
#include "ListaDoble.h"
#include <string>
#include <vector>


class Conjunto
{
private:
	ListaDoble<int> _dato;
	std::string _etiqueta;
public:	
	Conjunto() = default;
	Conjunto(ListaDoble<int> dato,std::string etiqueta = "");
	Conjunto(std::string etiqueta);
	void insertar(int n);
	ListaDoble<int>& getDato();
	std::vector<int> getComoVector();
	std::string getEtiqueta();
	int _tamanio();
};

