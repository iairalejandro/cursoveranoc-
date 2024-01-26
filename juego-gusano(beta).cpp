#include <iostream>
#include <stdlib.h>

using namespace std;

class cFruta {
public:
	int pos_i;
	int pos_j;
	char car_fruta;
public:
	cFruta() {
		pos_i = -1, pos_j = -1;
		car_fruta = '&';
	}

	void crearFruta(int num_f, int num_c) {
		pos_i = std::rand() % num_f;
		pos_j = std::rand() % num_c;
	}

};

class cGusano {
public:
	int* pos_i;
	int* pos_j;
	int tam;
	char simbolo;
public:
	cGusano() {
		pos_i = nullptr;
		pos_j = nullptr;
		tam = 0;
		simbolo = '@';
	}

	void crearGusano(int num_f, int num_c) {
		if (tam == 0) {
			pos_i = new int[1];
			pos_j = new int[1];
			pos_i[0] = std::rand() % num_f;
			pos_j[0] = std::rand() % num_c;
			tam = 1;
		}
	}

	bool isRun = true; char tecla = 'q';
	while (isRun) {
		std::cout << "Ingrese una tecla(W,A,S,D) y 'Q' para salir: ";
		std::cin >> tecla;
		switch (tecla) {
			case 'w';
			case 'W': std::cout << "Apreto W";
				break;
			case 'a';
			case 'A': std::cout << "Apreto A";
				break;
			case 's';
			case 'S': std::cout << "Apreto S";
				break;
			case 'd';
			case 'D': std::cout << "Apreto D";
				break;
			case 'q';
			case 'Q': std::cout << "Apreto Q";
				break;
			default: std::cout << "Ingrese una tecla valida...";



		}
	}
};

class cTablero {
public:
	int f;
	int c;
	char** miMatriz;
	cFruta miFruta;
	cGusano miGusano;

public:
	cTablero() {
		f = 0;
		c = 0;
		miMatriz = nullptr;

	}

	cTablero(int in_f, int in_c) {
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
		for (int i = 0; i < f; i++) {
			for (int j = 0; j < c; j++) {
				std::cout << miMatriz[i][j] << " ";
			}
			std::cout << std::endl;
		}
		return;
	}

	void generarFruta() {
		miFruta.crearFruta(f,c);
		miMatriz[miFruta.pos_i][miFruta.pos_j] = miFruta.car_fruta;
	}

	void generarGusano() {
		miGusano.crearGusano(f, c);
		miMatriz[miGusano.pos_i[0]][miGusano.pos_j[0]] = miGusano.simbolo;
	}

};



int main()
{
	cTablero miTablero(10, 10);
	miTablero.llenarMatriz('_');
	miTablero.printMatriz();
	std::cout << std::endl;
	miTablero.generarFruta();
	miTablero.printMatriz();
	std::cout << std::endl;
	miTablero.generarGusano();
	miTablero.printMatriz();

	return 0;

}
