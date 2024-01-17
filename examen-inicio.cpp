
#include <iostream>
#include <stdlib.h>

using namespace std;


    bool esPrimo(int n) {

        if (n == 2 || n == 3){
            return true;
        }

        if (n % 2 == 0) {
            return false;
        }

        for (int i = 3; i * i < n; i++) {
            if (n % i == 0)
                return false;
        }
    }

    int main() {
        int m1[10][10]{};
            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < 10; j++) {
                    m1[i][j] = rand() % 100;
                     cout << "\t" << m1[i][j];
                }
                cout << "\n" << endl;
            }
    }
