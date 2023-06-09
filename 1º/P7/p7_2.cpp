#include <stdlib.h>

#include <iostream>

/*  Grupo: Pedro Gazquez Ruiz (alu39) - Adrián Garrido Pantaleón (alu38) - Albert
    Lorenzo Segarra (alu51) */

float maximo(float a, float b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

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

void rellenar_vector(int n, int *V) {
    for (int i = 1; i <= n; i++) {
        std::cout << "Peso del objeto " << i << ":" << std::endl;
        std::cin >> V[i];
    }
}

void rellenar_vector_float(int n, float *V) {
    for (int i = 1; i <= n; i++) {
        std::cout << "Valor del objeto " << i << ":" << std::endl;
        std::cin >> V[i];
    }
}

float mochila(int M, int n, int *P, float *V) {
    float **T = new float *[n + 1];
    int m, *X;
    X = new int[n + 1];
    m = M;

    if (T == NULL) {
        std::cout << "Error al reservar memoria" << std::endl;
        return -1;
    }

    for (int i = 0; i <= n; i++) {
        T[i] = new float[M + 1];
        if (T[i] == NULL) {
            std::cout << "Error al reservar memoria" << std::endl;
            return 0;
        }
    }

    for (int i = 0; i <= M; i++) {
        T[0][i] = 0;
    }

    for (int i = 0; i <= n; i++) {
        T[i][0] = 0;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= M; j++) {
            if (P[i] > j) {
                T[i][j] = T[i - 1][j];
            } else {
                T[i][j] = maximo(T[i - 1][j], V[i] + T[i - 1][j - P[i]]);
            }
        }
    }

    float resultado = T[n][M];

    for (int i = n; i > 0 && resultado > 0; i--) {
        if (resultado != T[i - 1][m]) {
            X[i] = 1;
            resultado -= V[(i - 1) + 1];
            m -= P[(i - 1) + 1];
        } else {
            X[i] = 0;
        }
    }

    std::cout << "Objetos en la mochila:";
    for (int i = 1; i <= n; i++) {
        if (X[i] > 0) {
            std::cout << " " << i;
        }
    }
    std::cout << std::endl;

    return T[n][M];
}

int main() {
    int peso_maximo, num_total_objetos, *pesos_objetos;
    float *valor_objetos, resultado;

    std::cout << "Peso maximo de la mochila:";
    std::cin >> peso_maximo;

    std::cout << "\nTotal de objetos:\n";
    std::cin >> num_total_objetos;

    pesos_objetos = new int[num_total_objetos + 1];
    valor_objetos = new float[num_total_objetos + 1];

    rellenar_vector(num_total_objetos, pesos_objetos);
    rellenar_vector_float(num_total_objetos, valor_objetos);

    resultado = mochila(peso_maximo, num_total_objetos, pesos_objetos, valor_objetos);

    std::cout << "Valor maximo que puede llevar: " << resultado;

    std::cout << std::endl;
    return 0;
}