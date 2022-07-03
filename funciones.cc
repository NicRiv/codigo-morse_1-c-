// Definicion
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

// Declaracion funciones
string sub_cadena (string cadena, int m, int M);
int buscar (string cadena, string palabra);
vector<char> ordenar_caracteres (vector<char> caracteres);

// Declaracion codificar 
vector<char> extraer (string frase);
vector<string> codificar (vector<char> caracteres_frase);

// -------------------------------------------------------------

// Funcion traducir
string traducir (string frase) {
	string codigo;

	// ++++++++++++++++++++++++++++++++++++++++++++++

	// Extraer caracteres
	vector<char> caracteres_frase = extraer(frase);

	// Ordenarlos
	vector<char> caracteres_ordenados = ordenar_caracteres(caracteres_frase);

	// Imprimir datos
	for (auto ele : caracteres_ordenados) {
		cout << "[" << ele << "]" << " " ;
	}
	cout << "\n";

	//  +++++++++++++++++++++++++++++++++++++++++++++

	vector<string> caracteres_codificados = codificar(caracteres_ordenados);

	// imprimir datos
	for (auto le : caracteres_codificados) {
		cout << "[" << le << "] ";
	}

	//  ++++++++++++++++++++++++++++++++++++++++++++++

	cout << "\n";
	// TRADUCIR
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

// -------------------------------------------------------
// Remplazo de substr()
string sub_cadena (string cadena, int m, int M) {
	// Definicion
	string subcadena;

	for (int i = m; i < M; i++) {
		subcadena += cadena[i];
	}

	return subcadena;
}

// remplazo de find()
int buscar (string cadena, string palabra) {
	int count_p = 0;
	int pos_p;

	for (int i = 0; i < cadena.length(); i++) {
		if (count_p > palabra.length()-1)
			break;
		else { 
			if (cadena[i] == palabra[count_p]) {
				if (count_p == 0) pos_p = i;
				count_p++;
			}
			else {
				count_p = 0;
				pos_p = -1;
				continue;
			}
		}
	}

	return pos_p;
}

// ordena alfabeticamente
vector<char> ordenar_caracteres (vector<char> caracteres) {
	vector<char> caracteres_ordenados;

	vector<char> alfanum = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','0','1','2','3','4','5','6','7','8','9'};

	for (auto alfa : alfanum) {
		for (auto caracter : caracteres) {
			if (alfa == caracter) {
				caracteres_ordenados.push_back(alfa);
			}
		}
	}

	return caracteres_ordenados;
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