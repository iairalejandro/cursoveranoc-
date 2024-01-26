#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

const int MIN_SIZE = 10;

// Función para imprimir el tablero
void printBoard(char** board, int fil, int cols) {
    for (int i = 0; i < fil; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

// Función para llenar el tablero con letras aleatorias
void fillRandomLetters(char** board, int fil, int cols) {
    for (int i = 0; i < fil; ++i) {
        for (int j = 0; j < cols; ++j) {
            // Generar letra aleatoria entre A-Z y a-z
            char letter = rand() % 26 + (rand() % 2 == 0 ? 'A' : 'a');
            board[i][j] = letter;
        }
    }
}

// Función para insertar una palabra en el tablero horizontalmente
void insertHorizontal(char** board, const string& word, int row, int col) {
    for (int i = 0; i < word.length(); ++i) {
        board[row][col + i] = word[i];
    }
}

// Función para insertar una palabra en el tablero verticalmente
void insertVertical(char** board, const string& word, int row, int col) {
    for (int i = 0; i < word.length(); ++i) {
        board[row + i][col] = word[i];
    }
}

int main() {
    srand(time(0)); // Inicializar la semilla del generador de números aleatorios

    // Obtener las dimensiones del tablero
    int fil, cols;
    cout << "Ingrese el numero de filas del tablero (minimo " << MIN_SIZE << "): ";
    cin >> fil;
    cout << "Ingrese el numero de columnas del tablero (minimo " << MIN_SIZE << "): ";
    cin >> cols;

    // Validar las dimensiones mínimas
    if (fil < MIN_SIZE || cols < MIN_SIZE) {
        cout << "Las dimensiones del tablero son demasiado pequenas. Deben ser al menos " << MIN_SIZE << "x" << MIN_SIZE << "." << endl;
        return 1;
    }

    // Crear el tablero dinámico
    char** board = new char*[fil];
    for (int i = 0; i < fil; ++i) {
        board[i] = new char[cols];
    }

    // Llenar el tablero con letras aleatorias
    fillRandomLetters(board, fil, cols);

    // Obtener palabras del usuario y colocarlas en el tablero
    int numWords;
    cout << "Ingrese el numero de palabras a insertar: ";
    cin >> numWords;

    for (int i = 0; i < numWords; ++i) {
        string word;
        cout << "Ingrese la palabra #" << i + 1 << ": ";
        cin >> word;

        // Elegir aleatoriamente la dirección de la palabra (horizontal o vertical)
        bool horizontal = rand() % 2 == 0;

        // Elegir aleatoriamente la posición de la palabra en el tablero
        int startFil = rand() % (fil - (horizontal ? 0 : word.length()));
        int startCol = rand() % (cols - (horizontal ? word.length() : 0));

        // Insertar la palabra en el tablero
        if (horizontal) {
            insertHorizontal(board, word, startFil, startCol);
        } else {
            insertVertical(board, word, startFil, startCol);
        }
    }

    // Imprimir el tablero resultante
    printBoard(board, fil, cols);

    // Liberar la memoria del tablero dinámico
    for (int i = 0; i < fil; ++i) {
        delete[] board[i];
    }
    delete[] board;

    return 0;
}
