#include "SetsApp.h"
#include "GraphSet.h"
#include <iostream>
#include <graphics.h>
#include <algorithm>
#include <regex>
#include <windows.h>




#define BG_COLOR WHITE


void SetsApp::init() {
	initwindow(1200, 800, "DIAGRAMA DE VENN");	
	runMenu();
	closegraph();
}

void SetsApp::runMenu() {
	int selection = 1;
	bool menu_running = true;

	setbkcolor(BG_COLOR);
	cleardevice();

	while (menu_running) {
		system("cls");

		std::cout << "****OPERACIONES CON CONJUNTOS****" << std::endl << std::endl;
		

		// Dibujar la flecha de selección junto a la opción seleccionada
		for (int i = 1; i <= 6; i++) {
			if (i == selection) {
				std::cout << "--> ";
			}
			else {
				std::cout << "    ";
			}
			switch (i) {
			case 1:
				std::cout << "Union";
				break;
			case 2:
				std::cout << "Interseccion";
				break;
			case 3:
				std::cout << "Diferencia";
				break;
			case 4:
				std::cout << "Diferencia simetrica";
				break;
			case 5:
				std::cout << "Complemento";
				break;
			case 6:
				std::cout << "Salir";
				break;
			}
			std::cout << std::endl;
		}

		// Esperar a que el usuario presione una tecla de flecha
		int key = _getch();
		switch (key) {
		case 72: // Flecha hacia arriba
			selection--;
			if (selection < 1) {
				selection = 6;
			}
			break;
		case 80: // Flecha hacia abajo
			selection++;
			if (selection > 6) {
				selection = 1;
			}
			break;
		case 13: // Tecla Enter
			switch (selection) {
			case 1:
				system("cls");
				makeUnion();
				system("pause");
				break;
			case 2:
				system("cls");
				makeIntersection();
				system("pause");
				break;
			case 3:
				system("cls");
				makeDifference();
				system("pause");
				break;
			case 4:
				system("cls");
				makeSymmetricDifference();
				system("pause");
				break;
			case 5:
				system("cls");
				makeComplement();
				system("pause");
				break;
			case 6:
				menu_running = false;
				break;
			}
			break;
		default:
			break;
		}
	}
}

SetsApp::SetsApp() {	

}

void SetsApp::makeUnion() {
	Set a = scanSet("(Para finalizar el ingreso dejar vacio)|| Conjunto {{label}} || elemento #{{pos}}: ", "A");
	std::cout << std::endl;
	Set b = scanSet("(Para finalizar el ingreso dejar vacio)|| Conjunto {{label}} || elemento #{{pos}}: ", "B");

	Operation op(a, b);
	VennDiagram vd(a.getData(), b.getData());
	Set c = op.doUnion();

	std::cout << std::endl;
	std::cout << "A U B = ";

	for (int i : c.getData()) {
		std::cout << i << " ";
	}

	std::cout << std::endl;
	
	GraphSet graph;
	graph.drawUnion(op, vd);
	graph.drawBigO_n();
}

void SetsApp::makeIntersection() {
	Set a = scanSet("(Para finalizar el ingreso dejar vacio)|| Conjunto {{label}} || elemento #{{pos}}: ", "A");
	std::cout << std::endl;
	Set b = scanSet("(Para finalizar el ingreso dejar vacio)|| Conjunto {{label}} || elemento #{{pos}}: ", "B");

	Operation op(a, b);
	VennDiagram vd(a.getData(), b.getData());
	Set c = op.doIntersection();

	std::cout << std::endl;
	std::cout << "A (interseccion) B = ";

	for (int i : c.getData()) {
		std::cout << i << " ";
	}

	std::cout << std::endl;
	GraphSet graph;
	graph.drawIntersection(op, vd);
	graph.drawBigO_nlogn();
}

void SetsApp::makeDifference() {
	Set a = scanSet("(Para finalizar el ingreso dejar vacio)|| Conjunto {{label}} || elemento #{{pos}}: ", "A");
	std::cout << std::endl;
	Set b = scanSet("(Para finalizar el ingreso dejar vacio)|| Conjunto {{label}} || elemento #{{pos}}: ", "B");

	std::cout << "1: A - B" << std::endl;
	std::cout << "2: B - A" << std::endl;
	int option = scan_int("Ingrese la opcion: ", 1, 2, false).value();

	Set left;
	Set right;

	if (option == 1) {
		left = a;
		right = b;
	} else {
		left = b;
		right = a;
	}

	Operation op(left, right);
	VennDiagram vd(a.getData(), b.getData());
	Set c = op.doDifference();

	std::cout << std::endl;

	if (option == 1) {
		std::cout << "A - B = ";
	} else {
		std::cout << "B - A = ";
	}

	for (int i : c.getData()) {
		std::cout << i << " ";
	}

	std::cout << std::endl;
	GraphSet graph;
	graph.drawDifference(op, vd, option == 1);
	graph.drawBigO_2n();
}

void SetsApp::makeSymmetricDifference() {
	Set a = scanSet("(Para finalizar el ingreso dejar vacio)|| Conjunto {{label}} || elemento #{{pos}}: ", "A");
	std::cout << std::endl;
	Set b = scanSet("(Para finalizar el ingreso dejar vacio)|| Conjunto {{label}} || elemento #{{pos}}: ", "B");

	Operation op(a, b);
	VennDiagram vd(a.getData(), b.getData());
	Set c = op.doSymmetricDifference();

	std::cout << std::endl;
	std::cout << "A (diferencia simetrica) B = ";

	for (int i : c.getData()) {
		std::cout << i << " ";
	}

	std::cout << std::endl;
	GraphSet graph;
	graph.drawSymmetricDifference(op, vd);
	graph.drawBigO_n();
}

void SetsApp::makeComplement() {
	Set a = scanSet("(Para finalizar el ingreso dejar vacio)|| Conjunto {{label}} || elemento #{{pos}}: ", "A");
	std::cout << std::endl;
	Set b = scanSet("(Para finalizar el ingreso dejar vacio)|| Conjunto {{label}} || elemento #{{pos}}: ", "B");

	std::cout << "1: A (Complemeto)" << std::endl;
	std::cout << "2: B (Compleneto)" << std::endl;
	int option = scan_int("Ingrese la opcion: ", 1, 2, false).value();

	Set left;
	Set right;

	if (option == 1) {
		left = a;
		right = b;
	} else {
		left = b;
		right = a;
	}

	Operation op(left, right);
	VennDiagram vd(a.getData(), b.getData());
	Set c = op.doComplement();

	std::cout << std::endl;

	if (option == 1) {
		std::cout << "A (complemento) B = ";
	} else {
		std::cout << "B (complemento) A = ";
	}

	for (int i : c.getData()) {
		std::cout << i << " ";
	}

	std::cout << std::endl;
	GraphSet graph;
	graph.drawComplement(op, vd, option == 2);
	graph.drawBigO_n();
}

std::optional<int> SetsApp::scan_int(std::string message, int min_value, int max_value, bool allowEmpty)
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
			} else {
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

Set SetsApp::scanSet(std::string message, std::string label)
{
	Set set(label);

	while (true) {
		std::string m(message);
		m.replace(m.find("{{label}}"), 9, set.getLabel());
		m.replace(m.find("{{pos}}"), 7, std::to_string(set.size() + 1));
		auto scanned = scan_int(m, -99, 99);

		if (!scanned.has_value()) {
			break;
		}

		set.insert(scanned.value());
	}

	return set;
}
