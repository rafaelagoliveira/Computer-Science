#include "Roulette.h"
#include <iostream>

using namespace std;

int main() {
    Roulette<> roulette(5, 3);

    cout << roulette.turnsRoulette() << endl;

    return 0;
}