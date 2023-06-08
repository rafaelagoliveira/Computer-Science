#include "GeometricForms.h"
#include <stdio.h>

unsigned getUserChoice() {
    unsigned value = 0;

    printf("\n\tInforme a sua escolha: ");
    scanf("%u", &value);

    return value;
}

unsigned getRecursionLevel() {
    unsigned value = 0;

    printf("\n\tInforme o nivel de recursao: ");
    scanf("%u", &value);

    return value;
}

unsigned getGeometricForm() {
    unsigned userChoice = 0;

    do {
        printf(
            "\n\n\tRECURSIVIDADE\n\t0 - sair\n\t1 - Circulos\n\t2 - Quadrados\n");
        switch (userChoice = getUserChoice()) {
        case 1:
            return userChoice;
            break;
        case 2:
            return userChoice;
            break;
        case 0:
            printf("\n\tFinalizado!\n");
            break;
        default:
            printf("\n\tEscolha invalida!");
            break;
        }
    } while (userChoice != 0);

    return userChoice;
}

int main() {
    unsigned geometricFormChoice = 0, recurionLevelChoice = 0;  

    do {
        geometricFormChoice = getGeometricForm();

        if (geometricFormChoice != 0) {
            recurionLevelChoice = getRecursionLevel();

            if (geometricFormChoice == 1)
                showRecursiveCircles(recurionLevelChoice);
            else if (geometricFormChoice == 2)
                showRecursiveSquares(recurionLevelChoice);
        }

    } while (geometricFormChoice != 0);

    return 0;
}