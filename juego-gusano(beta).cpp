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

//.......................................................................................nueva version



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

    void moverGusano(char direccion, int f, int c) {
        // Obtener la posición actual del gusano
        int nueva_pos_i = pos_i[0];
        int nueva_pos_j = pos_j[0];

        // Actualizar la posición según la dirección
        switch (direccion) {
            case 'w':
            case 'W':
                nueva_pos_i--;
                break;
            case 'a':
            case 'A':
                nueva_pos_j--;
                break;
            case 's':
            case 'S':
                nueva_pos_i++;
                break;
            case 'd':
            case 'D':
                nueva_pos_j++;
                break;
            default:
                // Si la dirección no es válida, no hacer nada
                cout << "NO ES UNA TECLA VALIDA, INTENTELO NUEVAMENTE..." << endl;
                return;
        }

        // Actualizar la posición del gusano si está dentro de los límites del tablero
        if (nueva_pos_i >= 0 && nueva_pos_i < f && nueva_pos_j >= 0 && nueva_pos_j < c) {
            // Actualizar la posición del gusano
            pos_i[0] = nueva_pos_i;
            pos_j[0] = nueva_pos_j;
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

    void moverGusano(char direccion) {
        miGusano.moverGusano(direccion, f, c);
        // Actualizar la matriz del tablero con la nueva posición del gusano
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

    bool isRun = true;
    char tecla;
    while (isRun) {
        std::cout << "Ingrese una tecla (W, A, S, D) y 'Q' para salir: ";
        std::cin >> tecla;
        if (tecla == 'q' || tecla == 'Q') {
            isRun = false;
        } else {
            miTablero.moverGusano(tecla);
            miTablero.printMatriz();
        }
    }

    return 0;

}
