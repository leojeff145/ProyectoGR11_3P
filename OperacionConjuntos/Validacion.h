#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <set>
#include <limits>
#include <random>
#include <cctype>
#include <regex>
#include <iomanip>
#include <sstream>
#include <cfloat>
#include <Windows.h>
#include <conio.h>
#define TAMANIO 8
#define DX {2, 1, -1, -2, -2, -1, 1, 2}
#define DY {1, 2, 2, 1, -1, -2, -2, -1}

using namespace std;

class Validacion
{
public:
	static void limpiar_consola() {
		COORD topLeft = { 0, 0 };
		HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_SCREEN_BUFFER_INFO screen;
		DWORD written;

		GetConsoleScreenBufferInfo(console, &screen);
		FillConsoleOutputCharacterA(
			console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written);
		FillConsoleOutputAttribute(
			console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
			screen.dwSize.X * screen.dwSize.Y, topLeft, &written);
		SetConsoleCursorPosition(console, topLeft);
	}

	static std::string leer_cadena(const std::string etiqueta, bool permitir_vacio = false) {
		std::string leido;

		if (permitir_vacio) {
			std::getline(std::cin, leido);
		}
		else {
			while ((std::cout << etiqueta),
				std::getline(std::cin, leido), leido.empty())
				;
		}

		return leido;
	}

	static int leer_cadena_regex(const std::string etiqueta, std::string regex) {
		std::string leido;
		std::regex cadena_regex(regex);

		do {
			leido = leer_cadena(etiqueta);

			if (!std::regex_match(leido, cadena_regex)) {				
				cout << "Formato invalido"<<endl;
				cout << "Reingresar: ";
			}
		} while (!std::regex_match(leido, cadena_regex));

		return stoi(leido);
	}

	static int leer_entero(std::string etiqueta, int minimo = INT_MIN, int maximo = INT_MAX) {
		int leido;
		bool valido;

		do {
			std::cout << etiqueta;
			std::cin >> leido;

			valido = !std::cin.fail();

			std::cin.clear();
			std::cin.ignore();
		} while (!valido || leido < minimo || leido > maximo);

		return leido;
	}

	static bool cadenas_iguales(std::string a, std::string b) {
		a = trim_cadena(cadena_minusculas(a));
		b = trim_cadena(cadena_minusculas(b));

		return a == b;
	}

	static float leer_flotante(std::string etiqueta, float minimo = DBL_MIN, float maximo = DBL_MAX) {
		float leido;
		bool valido;

		do {
			std::cout << etiqueta;
			leido=Validacion::ingresar_DatosReales();

			valido = !std::cin.fail();

			std::cin.clear();
			std::cin.ignore();			
		} while (!valido || leido < minimo || leido > maximo);

		return leido;
	}

	static bool cedula_valida(const std::string cedula) {
		if (cedula.length() != 10) {
			return false;
		}

		int sum_par = 0;
		int sum_impar = 0;
		int sum;
		int i = 1;

		std::string digits = cedula.substr(0, cedula.size() - 1);

		for (char& c : digits) {
			int digit = c - '0';
			if (i % 2 == 0) {
				sum_par += digit;
			}
			else {
				if ((digit * 2) > 9) {
					sum_impar += (digit * 2) - 9;
				}
				else {
					sum_impar += (digit * 2);
				}
			}
			i++;
		}

		sum = sum_par + sum_impar;

		int verifier = cedula.at(cedula.size() - 1) - '0';
		int higher = (10 - (sum % 10)) + sum;

		if (sum % 10 == 0) {
			return verifier == 0;
		}

		return (higher - sum) == verifier;
	}
	
	


	static std::string trim_cadena(std::string cadena) {
		auto wsfront = std::find_if_not(cadena.begin(), cadena.end(), [](int c) { return std::isspace(c); });
		auto wsback = std::find_if_not(cadena.rbegin(), cadena.rend(), [](int c) { return std::isspace(c); }).base();
		return (wsback <= wsfront ? std::string() : std::string(wsfront, wsback));
	}

	
	

	static std::string cadena_minusculas(std::string cadena) {
		std::string resultado(cadena);

		std::transform(resultado.begin(), resultado.end(), resultado.begin(), [](unsigned char c) {
			return std::tolower(c);
			});

		return resultado;
	}

	static bool existe_archivo(std::string nombre_archivo) {
		return std::ifstream(nombre_archivo.c_str()).good();
	}

	static int generar_aleatorio(int minimo = INT_MIN, int maximo = INT_MAX) {
		std::random_device rd;
		static std::mt19937 gen(rd());
		std::uniform_int_distribution<> dis(minimo, maximo);

		return dis(gen);
	}
	

	static std::string decimal_fixed(float valor, int precision = 2) {
		std::stringstream ss;
		ss << std::fixed << std::setprecision(precision) << valor;
		return ss.str();
	}

	

	static int ingresar_DatosEnteros()
	{
		char* dato = new char[10], c;
		int i = 0;		
		while ((c = _getch()) != 13) {
			if (c >= '0' && c <= '9') {
				printf("%c", c);
				dato[i++] = c;
			}
			else if (c == 8 || c == 127) {
				printf("\b \b");
				dato[i--] = 0;
			}
		}
		dato[i] = '\0';
		return atoi(dato);
	}

	static float ingresar_DatosReales()
	{
		char* dato = new char[10], c;
		int i = 0, punto = 0;		
		while ((c = _getch()) != 13) {
			if (c >= '0' && c <= '9') {
				printf("%c", c);
				dato[i++] = c;
			}
			else if (c == 8 || c == 127) {
				printf("\b \b");
				dato[i--] = 0;
			}
			else if (c == '.' && punto == 0) {
				printf("%c", c);
				dato[i++] = c;
				punto--;
			}
		}
		dato[i] = '\0';
		return atof(dato);
	}
};

