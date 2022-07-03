// Definicion
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

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