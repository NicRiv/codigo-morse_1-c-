// Definicion
#include <iostream>
#include <string>
using namespace std;

string codificar (string frase) {
	string codigo;
	codigo += "[";
	for (int i = 0; i < frase.length(); i++) {
		switch (frase[i]) {
			case ' ':
				codigo += "]  [";
				break;			
			case 'a':
				codigo += ".-";
				break;
			case 'b':
				codigo += "-...";
				break;
			case 'c':
				codigo += "-.-.";
				break;
			case 'd':
				codigo += "-..";
				break;
			case 'e':
				codigo += ".";
				break;
			case 'f':
				codigo += "..-.";
				break;
			case 'g':
				codigo += "--.";
				break;
			case 'h':
				codigo += "....";
				break;
			case 'i':
				codigo += "..";
				break;
			case 'j':
				codigo += ".---";
				break;
			case 'k':
				codigo += "-.-";
				break;
			case 'l':
				codigo += ".-..";
				break;
			case 'm':
				codigo += "--";
				break;
			case 'n':
				codigo += "-.";
				break;
			// case 'ñ':
				// codigo += "--.--";
				// break;
			case 'o':	
				codigo += "---";
				break;
			case 'p':
				codigo += ".--.";
				break;
			case 'q':
				codigo += "--.-";
				break;
			case 'r':
				codigo += ".-.";
				break;
			case 's':
				codigo += "...";
				break;
			case 't':
				codigo += "-";
				break;
			case 'u':
				codigo += "..-";
				break;
			case 'v':
				codigo += "...-";
				break;
			case 'w':
				codigo += ".--";
				break;
			case 'x':
				codigo += "-..-";
				break;
			case 'y':
				codigo += "-.--";
				break;
			case 'z':
				codigo += "--..";
				break;
			case '1':
				codigo += ".----";
				break;
			case '2':
				codigo += "..---";
				break;
			case '3':
				codigo += "...--";
				break;
			case '4':
				codigo += "....-";
				break;
			case '5':
				codigo += ".....";
				break;
			case '6':
				codigo += "-....";
				break;
			case '7':
				codigo += "--...";
				break;
			case '8':
				codigo += "---..";
				break;
			case '9':
				codigo += "----.";
				break;
			case '0':
				codigo += "-----";
				break;
			default:
				codigo += frase[i];
				break;
		}
		codigo += " ";
	}
	codigo += "]";

	return codigo;
}