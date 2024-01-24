
#include <iostream>

int main()
{

    int a[3] = { 1,2,3 };
    char b[3] = { 'a','b','c' };
    bool c[3] = { true, false, true };
    float d[3] = { 3.2f, 1.4f, 0.8f };
    double e[3] = { 4.5, 6.8, 2.4 };
/*
    std::cout << "a: " << a << "-&" << &a << std::endl;
    std::cout << "b: " << b << "-&" << &b << std::endl;
    std::cout << "c: " << c << "-&" << &c << std::endl;
    std::cout << "d: " << d << "-&" << &d << std::endl;
    std::cout << "e: " << e << "-&" << &e << std::endl;
*/

    int* ptr_a{ nullptr };
    ptr_a = &(a[1]);
    (*ptr_a) = 5;


    for (int i = 0; i < 10; i++) {
        std::cout << "a: " << *ptr_a << std::endl;
        ptr_a += 1;
    }
    std::cout << std::endl;
    /*
    for (int i = 0; i < 3; i++) {
        std::cout << "b: " << b[i] << "-&" << &(b[i]) << std::endl;
    }
    std::cout << std::endl;

    for (int i = 0; i < 3; i++) {
        std::cout << "c: " << c[i] << "-&" << &(c[i]) << std::endl;
    }
    std::cout << std::endl;

    for (int i = 0; i < 3; i++) {
        std::cout << "d: " << d[i] << "-&" << &(d[i]) << std::endl;
    }
    std::cout << std::endl;

    for (int i = 0; i < 3; i++) {
        std::cout << "e: " << e[i] << "-&" << &(e[i]) << std::endl;
    }
    std::cout << std::endl;
    */
}
