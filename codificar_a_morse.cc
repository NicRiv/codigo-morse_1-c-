// Definicion
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "funciones.h"

using namespace std;

// Declaracion codificar 
vector<char> extraer (string frase);
vector<string> codificar (vector<char> caracteres_frase);

// ------------------------------------------------------
// Funcion traducir
string traducir (string frase) {
	string codigo;

	// ++++++++++++++++++++++++++++++++++++++++++++++

	// Extraer caracteres
	vector<char> caracteres_frase = extraer(frase);

	// Ordenarlos
	vector<char> caracteres_ordenados = ordenar_caracteres(caracteres_frase);

	// Imprimir datos
	cout << "Caracrteres en la Frase: ";
	for (auto ele : caracteres_ordenados) {
		cout << "[" << ele << "]" << " " ;
	}
	cout << "\n";

	//  +++++++++++++++++++++++++++++++++++++++++++++

	vector<string> caracteres_codificados = codificar(caracteres_ordenados);

	// imprimir datos
	cout << "Caracrteres Codificados: ";
	for (auto le : caracteres_codificados) {
		cout << "[" << le << "] ";
	}

	//  ++++++++++++++++++++++++++++++++++++++++++++++

	cout << "\n";
	// TRADUCIR
	cout << "Frase codificada: ";
	codigo += "[";
	for (int i = 0 ; i < frase.length(); i++) {
		for (int j = 0; j < caracteres_ordenados.size(); j++) {
			if (frase[i] == caracteres_ordenados.at(j)) {
				codigo += caracteres_codificados.at(j);
			}
		}
		if (frase[i] == ' ') codigo += "]  [";
	}
	codigo += "]";

	return codigo;
}

//  -------------------------------------------------------
vector<char> extraer (string frase) {
	// *************************************************
	// extraer caracteres de la frase
	vector<char> caracteres_frase;
	int agregar_caracter;

	for (int i = 0; i < frase.length(); i++) {
		// Inicializa
		agregar_caracter = 0;
		for (int j = 0; j < caracteres_frase.size(); j++) {
			if (tolower(frase[i]) != caracteres_frase[j]) agregar_caracter++;
		}

		// Si el caracter no esta, lo agrega
		if (agregar_caracter == caracteres_frase.size()) {
			caracteres_frase.push_back(tolower(frase[i]));
		}
	}

	return caracteres_frase;
	// *************************************************
}

vector<string> codificar (vector<char> caracteres_frase) {
	// =================================================
	// Abre fichero
	ifstream db;
	db.open("DB.txt");

	// Si falla abrir archivo
	if (db.fail()) {
		cerr << "Error al abrir base de datos" << endl;
		exit(1);
	}

	string linea;
	vector<string> caracteres_codificados;

	while (getline(db, linea)) {
		for (auto caracter : caracteres_frase) {
			if (caracter == linea[0]) {
				caracteres_codificados.push_back(sub_cadena(linea, 2, linea.length()));				
			}
		}
	}

	db.close();

	return caracteres_codificados;
	// =================================================
}