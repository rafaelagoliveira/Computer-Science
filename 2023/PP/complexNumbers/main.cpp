/*
Crie uma classe para representar números complexos
no formato a + bi, onde i é a raiz quadrada de -1.

Implemente as operações de soma, subtração, multiplicação,
divisão, incremento e decremento (pos e pre) e as operações
de comparação que cabem aos números complexos

Incremento e decremento: 
    (a + bi) +/- 1 => (a +/- 1) + bi

Soma:
    (a + bi) + (c + di) = (a + c) + (b + d)i

Subtração:
    (a + bi) - (c + di) = (a - c) + (b - d)i

Multiplicação:
    (a + bi) * (c + di) = ac + adi + bci + bdi^2 = ac + adi + bci - bd = (ac - bd) + (ad + bc)i

Divisão:
    (a + bi) / (c + di) = [(a + bi) * (c - di)] / [(c + di) * (c - di)] = [(ac + bd) + (bc - ad)i] / (c^2 + d^2)
*/

#include <iostream>

using namespace std;

class Complex {
  private:
    float a, b;

  public:
    Complex(float a = 0, float b = 0): a(a), b(b) {}

};

int main() {
    Complex z1(2, 4), z2(3, 5);

    

    return EXIT_SUCCESS;
}