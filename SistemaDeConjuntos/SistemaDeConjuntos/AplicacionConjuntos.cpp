#include "AplicacionConjuntos.h"
#include <iostream>
#include <string>
#include <graphics.h>
#include <algorithm>
#include <random>
#include <regex>

#define BG_COLOR WHITE

void AplicacionConjuntos::iniciar() {
	initwindow(1200, 600, "Operaciones Con Conjuntos");
	correrMenu();
	closegraph();
}

void AplicacionConjuntos::correrMenu() {
	int opcion = 0;

	setbkcolor(BG_COLOR);
	cleardevice();

	while (true) {
		system("cls");

		std::cout << "Operaciones de conjuntos" << std::endl << std::endl;
		std::cout << "1. Union" << std::endl;
		std::cout << "2. Interseccion" << std::endl;
		std::cout << "3. Diferencia" << std::endl;
		std::cout << "4. Diferencia simetrica" << std::endl;
		std::cout << "5. Complemento" << std::endl;
		std::cout << "6. Salir" << std::endl << std::endl;

		do {
			std::optional<int> scanned = scan_int("Seleccione una opcion: ", 1, 6);

			if (!scanned.has_value()) {
				continue;
			}

			opcion = scanned.value();

			break;
		} while (true);

		switch (opcion) {
		case 1:
			
			break;
		case 2:
			
			break;
		case 3:
			
			break;
		case 4:
			
			break;
		case 5:
			
			break;
		}

		if (opcion == 6) {
			break;
		}

		std::cout << std::endl << std::endl;
		system("pause");
	}	
}

AplicacionConjuntos::AplicacionConjuntos() {
	std::vector<std::tuple<int, int>> posicionesIzquierdo = {
		{ 760, 56 }, { 700, 80 }, { 745, 80 }, { 785, 80 }, { 665, 105 },
		{ 715, 105 }, { 765, 105 }, { 650, 130 }, { 700, 130 }, { 750, 130 },
		{ 640, 155 }, { 690, 155 }, { 740, 155 }, { 635, 180 }, { 685, 180 },
		{ 735, 180 }, { 640, 205 }, { 690, 205 }, { 740, 205 }, { 645, 230 },
		{ 695, 230 }, { 745, 230 }, { 655, 255 }, { 705, 255 }, { 745, 255 },
		{ 670, 280 }, { 720, 280 }, { 760, 280 }, { 695, 305 }, { 745, 305 }
	};

	std::vector<std::tuple<int, int>> posicionesDerecho = {
		{ 895, 80 }, { 940, 80 }, { 985, 80 }, { 910, 105 }, { 955, 105 },
		{ 1005, 105 }, { 923, 130 }, { 970, 130 }, { 1020, 130 }, { 935, 155 },
		{ 985, 155 }, { 1035, 155 }, { 935, 180 }, { 990, 180 }, { 1040, 180 },
		{ 935, 205 }, { 985, 205 }, { 1035, 205 }, { 930, 230 }, { 980, 230 },
		{ 1030, 230 }, { 925, 255 }, { 975, 255 }, { 1025, 255 }, { 910, 280 },
		{ 960, 280 }, { 1010, 280 }, { 885, 310 }, { 935, 305 }, { 981, 305 }		
	};

	std::vector<std::tuple<int, int>> posicionesCentro = {
		{ 843, 90 }, { 813, 110 }, { 863, 110 }, { 798, 130 }, { 838, 130 },
		{ 878, 130 }, { 792, 150 }, { 838, 150 }, { 888, 150 }, { 788, 170 },
		{ 838, 170 }, { 888, 170 }, { 788, 190 }, { 838, 190 }, { 888, 190 },
		{ 788, 210 }, { 838, 210 }, { 888, 210 }, { 798, 230 }, { 838, 230 },
		{ 878, 230 }, { 803, 250 }, { 838, 250 }, { 873, 250 }, { 813, 270 },
		{ 863, 270 }, { 843, 290 }
	};

	//Desordenar los vectores
	std::random_device rd;
	std::mt19937 g(rd());

	std::shuffle(posicionesIzquierdo.begin(), posicionesIzquierdo.end(), g);
	std::shuffle(posicionesDerecho.begin(), posicionesDerecho.end(), g);
	std::shuffle(posicionesCentro.begin(), posicionesCentro.end(), g);

	posicion_diagrama.insert({"izquierda",posicionesIzquierdo});
	posicion_diagrama.insert({"derecha",posicionesDerecho});
	posicion_diagrama.insert({"centro",posicionesCentro});
}

void AplicacionConjuntos::hacerUnion() {

}

void AplicacionConjuntos::hacerInterseccion() {

}

void AplicacionConjuntos::hacerDiferencia() {

}

void AplicacionConjuntos::hacerDiferenciaSimetrica() {

}

void AplicacionConjuntos::hacerComplemento() {

}

void AplicacionConjuntos::dibujarBase(Operacion operacion, DiagramaVenn vd) {

}

void AplicacionConjuntos::dibujarUnion(Operacion operacion, DiagramaVenn vd) {

}

void AplicacionConjuntos::dibujarInterseccion(Operacion operacion, DiagramaVenn vd) {

}

void AplicacionConjuntos::dibujarDiferencia(Operacion operacion, DiagramaVenn vd, bool esIzquierda) {

}

void AplicacionConjuntos::dibujarDiferenciaSimetrica(Operacion operacion, DiagramaVenn vd) {

}

void AplicacionConjuntos::dibujarComplemento(Operacion operacion, DiagramaVenn vd,bool esIzquierda) {

}

std::optional<int> AplicacionConjuntos::scan_int(std::string message, int min_value, int max_value, bool allowEmpty)
{
	std::string input;
	int value;

	while (true) {
		std::cout << message;

		while (std::cin.rdbuf()->in_avail() > 0) {
			std::cin.ignore();
		}

		std::getline(std::cin, input);

		if (input.empty()) {
			if (allowEmpty) {
				return std::nullopt;
			}
			else {
				continue;
			}
		}

		if (!std::regex_match(input, std::regex("^-?[0-9]+$"))) {
			std::cout << "El valor ingresado no es un numero" << std::endl << std::endl;
			continue;
		}

		try {
			value = std::stoi(input);

			if (value < min_value || value > max_value) {
				continue;
			}

			break;
		}
		catch (std::invalid_argument) {
			std::cout << "El valor ingresado no es un numero" << std::endl << std::endl;
		}
		catch (std::out_of_range) {
			std::cout << "El numero ingresado es demasiado grande" << std::endl << std::endl;
		}
	}

	return value;
}

Conjunto AplicacionConjuntos::scan_conjunto(std::string mensaje, std::string etiqueta)
{
	Conjunto conj(etiqueta);

	while (true) {
		std::string m(mensaje);
		m.replace(m.find("{{etiqueta}}"), 9, conj.getEtiqueta());
		m.replace(m.find("{{pos}}"), 7, std::to_string(conj._tamanio() + 1));
		auto scanned = scan_int(m, -99, 99);

		if (!scanned.has_value()) {
			break;
		}

		conj.insertar(scanned.value());
	}

	return conj;
}