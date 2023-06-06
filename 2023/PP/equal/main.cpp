#include <iostream>

#include "Equals.h"

int main() {
    Equals checker;
    int a = 20, b = 30;
    bool result = checker.checkEqual(a, b);

    std::cout << a << " eh igual a " << b << " ?";
    result ? std::cout << " Sim" << std::endl : std::cout << " Nao" << std::endl;


    return 0;
}