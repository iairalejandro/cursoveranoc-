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

	void insertarNum(int num_f, int num_c) {
		pos_i = std::rand() % num_f;
		pos_j = std::rand() % num_c;
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

		for (int i = 0; i < f; ++i) {
			for (int j = 0; j < c; ++j) {
				int num = rand() % 9 + '1';
				miMatriz[i][j] = num;
			}
		}
	}

	void generarNum() {
		numRand.insertarNum(f, c);
		miMatriz[numRand.pos_i][numRand.pos_j] = numRand.num;
	}

};



int main()
{
	Tablero miTablero(9, 9);
	miTablero.llenarMatriz('_');
	miTablero.llenarNum(9,9);
	miTablero.generarNum();
	miTablero.printMatriz();
   

}
