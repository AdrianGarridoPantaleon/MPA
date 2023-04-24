#include <stdlib.h>

#include <iostream>

/*  Grupo: Pedro Gazquez Ruiz (alu39) - Adrián Garrido Pantaleón (alu38) - Albert
    Lorenzo Segarra (alu51) */

void imprimirVector(int n, int *vec) {
    for (int i = 1; i <= n; i++) {
        if (i != n) {
            std::cout << vec[i] << " ";
        } else {
            std::cout << vec[i];
        }
    }
    std::cout << std::endl;
}

void rellenarVectores(int n, int *P, int *T) {
    for (int i = 1; i <= n; i++) {
        std::cout << "Introduce tiempo del proceso " << i << ":";
        std::cin >> T[i];
        std::cout << std::endl;
        P[i] = i;
    }
}

void swap(int *P1, int *P2, int *T1, int *T2) {
    int tmp1, tmp2;
    tmp1 = *P1;
    tmp2 = *T1;
    *P1 = *P2;
    *P2 = tmp1;
    *T1 = *T2;
    *T2 = tmp2;
}

void ordenarAscendente(int n, int *T, int *P) {
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (T[i] > T[j]) {
                swap(&T[j], &T[i], &P[j], &P[i]);
            }
        }
    }
}

int algoritmoVoraz(int n, int *P, int *T) {
    int minimo = 0;
    ordenarAscendente(n, T, P);
    for (int i = 1; i <= n; i++) {
        minimo += (n - i + 1) * T[i];
    }
    if (minimo > 0) {
        return minimo;
    } else {
        return 0;
    }
}

int main() {
    int dimensionVector, *procesos, *tiempos;

    std::cout << "Introduce num.total de procesos:";
    std::cin >> dimensionVector;
    std::cout << "\n";

    procesos = new int[dimensionVector + 1];
    tiempos = new int[dimensionVector + 1];

    rellenarVectores(dimensionVector, procesos, tiempos);
    std::cout << "Tiempo minimo: " << algoritmoVoraz(dimensionVector, procesos, tiempos) << std::endl;
    std::cout << "Orden: ";
    imprimirVector(dimensionVector, procesos);
}