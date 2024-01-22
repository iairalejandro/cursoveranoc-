
#include <iostream>
#include <stdlib.h>


using namespace std;

int main() {

    char m1[10][10]{};

        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {

                m1[i][j] = 65 + rand() % 26;
                m1[i][j] = 97 + rand() % 26;


                cout << "\t" << m1[i][j];
            }
            cout << "\n" << endl;
        }

}



#include <iostream>
#include <cstdlib> // Para la función rand()
#include <ctime>   // Para la función time()

const int FILAS = 10;
const int COLUMNAS = 10;

char generarLetraAleatoria() {
    // Generar un número aleatorio entre 0 y 25 para las letras del alfabeto
    int numeroAleatorio = rand() % 26;
    
    // Si el número aleatorio es par, generar una letra mayúscula; de lo contrario, generar una letra minúscula
    char letra = (numeroAleatorio % 2 == 0) ? 'A' + numeroAleatorio : 'a' + numeroAleatorio;

    return letra;
}

int main() {
    // Inicializar la semilla para la generación de números aleatorios
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    // Declarar la matriz
    char matriz[FILAS][COLUMNAS];

    // Llenar la matriz con letras aleatorias
    for (int i = 0; i < FILAS; ++i) {
        for (int j = 0; j < COLUMNAS; ++j) {
            matriz[i][j] = generarLetraAleatoria();
        }
    }

    // Imprimir la matriz
    for (int i = 0; i < FILAS; ++i) {
        for (int j = 0; j < COLUMNAS; ++j) {
            std::cout << matriz[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
