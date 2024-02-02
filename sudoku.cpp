#include <iostream>
#include<stdlib.h>

class NumerosAleatorio {
public:
	int pos_i;
	int pos_j;
	char num;
public:
	NumerosAleatorio() {
		pos_i = -1, pos_j = -1;
		num = ' 0 ';
	}

};



class Tablero {
public:
	int f;
	int c;
	char** miMatriz;
	NumerosAleatorio numRand;

public:
	Tablero() {
		f = 0;
		c = 0;
		miMatriz = nullptr;
	}

	Tablero(int in_f, int in_c) {
		f = in_f; c = in_c;
		miMatriz = new char* [f];
		for (int i = 0; i < f; i++) {
			miMatriz[i] = new char[c];
		}
	}

	void llenarMatriz(char in_caracter) {
		for (int i = 0; i < f; i++) {
			for (int j = 0; j < c; j++) {
				miMatriz[i][j] = in_caracter;
			}
		}
	}

	void printMatriz() {
		std::cout << std::endl;
		for (int i = 0; i < f; i++) {
			for (int j = 0; j < c; j++) {
				std::cout << "   |   " << miMatriz[i][j];
				
			}
			std::cout << "   |  " << std::endl;
			std::cout << std::endl;

		}
		return;
	}

	void llenarNum(int f, int c) {
		const int numNumeros = f * c / 6;
		for (int i = 0; i < numNumeros; ++i) {
			int num_i = rand() % f;
			int num_j = rand() % c;
			if (miMatriz[num_i][num_j] == '_') {
				int num = rand() % 9 + '1';
				miMatriz[num_i][num_j] = num;
			}
		}
	}



};


int main()
{
	Tablero miTablero(9, 9);
	miTablero.llenarMatriz('_');
	miTablero.llenarNum(9,9);
	miTablero.printMatriz();
	
	bool isRun = true;
	int valor;
	int coord_x;
	int coord_y;

	while (isRun) {
		std::cout << "Ingrese el valor: ";
		std::cin >> valor;
		if (valor < 1 || valor > 9) {
			isRun = false;
			std::cout << "No es una opcion valida" << std::endl;
			return 0;
		}
		std::cout << "Ingrese las coordenada(x): ";
		std::cin >> coord_x;
		std::cout << "Ingrese las coordenada(y): ";
		std::cin >> coord_y;
		if((coord_x < 1 || coord_x > 9) || (coord_y < 1 || coord_y > 9)) {
			isRun = false;
			std::cout << "No es una opcion valida" << std::endl;
		}

	}
   

}
