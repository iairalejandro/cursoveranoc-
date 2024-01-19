
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

