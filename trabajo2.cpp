
#include <iostream>
#include <stdlib.h>

using namespace std;


char generarLetraAleatoria() {
 
    int numeroAleatorio = rand() % 26;
    char letra = (numeroAleatorio % 2 == 0) ? 'A' + numeroAleatorio : 'a' + numeroAleatorio;
    return letra;
}

int main() {

    char matriz[10][10];

    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            matriz[i][j] = generarLetraAleatoria();
        }
    }

    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            cout << "\t" << matriz[i][j];
        }
        cout << "\n" << endl;
    }



    string miVal;
    cout << "Ingrese una palabra: ";
    cin >> miVal;

    if (miVal.length() >= 2 || miVal.length() >= 10) {
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 10; ++j) {
                cout << "\t" << miVal;
            }
            cout << "\n" << endl;
        }

    }
    else {
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 10; ++j) {
                cout << "\txd" << matriz[i][j];
            }
            cout << "\n" << endl;
        }
    }




    return 0;
}
