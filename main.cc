#include <iostream>
#include "funciones.h"
using namespace std;

void nueva_pag();
void menu();

int main () {
	string entrada;
	string frase;

	nueva_pag();
	menu();
	getline(cin, entrada);

	while (entrada != "0") {
		switch (stoi(entrada)) {
			case 1:
				nueva_pag();
				menu();
				
				cout << "\n" << "Ingrese la frase a codificar" << "\n";
				cout << "> ";
				getline(cin, frase);
				cout << "\n" << traducir(frase) << "\n";

				cout << "\n" << "<< [9] Menu ; [0] Salir >>" << "\n";
				cout << "> ";
				getline(cin, entrada);
				break;
			case 9:
				nueva_pag();
				menu();
				cout << "> ";
				getline(cin, entrada);
				break;
			case 0:
				break;
			default: 
				cout << "\n" << "** La opcion ingresada no es valida **" << "\n";
				cout << "\n" << "<< [9] Menu ; [0] Salir >>" << "\n";
				cout << "> ";
				getline(cin, entrada);
				break;
		}			
	}

	return 0;
}

void nueva_pag() {
	cout << "\033[2J\033[H";
}

void menu() {
	cout << "|------------------------|" << "\n";
	cout << "|------Codigo Morse------|" << "\n";
	cout << "|------------------------|" << "\n";
	cout << "[1] Codificar a Morse" << "\n";
	cout << "[0] Salir" << "\n";
}