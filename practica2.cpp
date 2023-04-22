#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

int insercion(int n, int *v)
{
    int x, j;
    for (int i = 2; i <= n; i++)
    {
        x = v[i];
        j = i - 1;
        while ((j > 0) && (v[j] > x))
        {
            v[j + 1] = v[j];

            j -= 1;
        }
        v[j + 1] = x;
    }
    return 1;
}

void inversoVector(int n, int *v)
{
    for (int i = 1; i <= n / 2; i++)
    {
        int a = v[i];
        v[i] = v[n - (i - 1)];
        v[n - (i - 1)] = a;
    }
}

void rellenarVector(int n, int *v)
{
    for (int i = 1; i <= n; i++)
    {
        v[i] = rand();
    }
}

void imprimirVector(int *v, int inicio, int final)
{
    for (int i = inicio; i <= final; i++)
    {
        if (i < final)
        {
            cout << v[i] << " ";
        }
        else
        {
            cout << v[i];
        }
    }
    cout << endl;
}

int main()
{
    int *vector, s, dimensionVector, vInicial, vFinal, muestraTiempo;

    cout << "Semilla para generar aleatorios:";
    cin >> s;
    srand(s);

    cout << "Introduce tamanio del vector:";
    cin >> dimensionVector;

    cout << "Posiciones INICIAL y FINAL del vector para mostrar";
    cout << endl;

    cout << "INICIAL:";
    cin >> vInicial;

    cout << "FINAL:";
    cin >> vFinal;

    cout << "Mostrar tiempo de ejecucion (1:Si, 0:No):";
    cin >> muestraTiempo;
    cout << endl;

    vector = new int[dimensionVector + 1];

    rellenarVector(dimensionVector, vector);

    if (muestraTiempo == 0)
    {

        cout << "ALGORITMO DE INSERCION";
        cout << endl;
        cout << endl;

        cout << "CASO CUALQUIERA";
        cout << endl;
        cout << "---------------";
        cout << endl;
        cout << "Vector a ordenar:";
        imprimirVector(vector, vInicial, vFinal);
        cout << endl;
        cout << "Vector ordenado:";
        insercion(dimensionVector, vector);
        imprimirVector(vector, vInicial, vFinal);
        cout << endl;

        cout << "CASO MEJOR";
        cout << endl;
        cout << "---------------";
        cout << endl;
        cout << "Vector a ordenar:";
        imprimirVector(vector, vInicial, vFinal);
        cout << endl;
        cout << "Vector ordenado:";
        imprimirVector(vector, vInicial, vFinal);
        cout << endl;

        cout << "CASO PEOR";
        cout << endl;
        cout << "---------------";
        cout << endl;
        cout << "Vector a ordenar:";
        inversoVector(dimensionVector, vector);
        imprimirVector(vector, vInicial, vFinal);
        cout << endl;
        cout << "Vector ordenado:";
        insercion(dimensionVector, vector);
        imprimirVector(vector, vInicial, vFinal);

        cout << endl;

        cout << "FIN DEL PROGRAMA";
        cout << endl;
    }
    else
    {
        clock_t tinicio, tfinal;
        double tiempo;
        int resultado;

        cout << "ALGORITMO DE INSERCION";
        cout << endl;
        cout << endl;

        cout << "CASO CUALQUIERA";
        cout << endl;
        cout << "---------------";
        cout << endl;
        cout << "Vector a ordenar:";
        imprimirVector(vector, vInicial, vFinal);
        cout << "Vector ordenado:";
        tinicio = clock();
        resultado = insercion(dimensionVector, vector);
        tfinal = clock();
        tiempo = (double)(tfinal - tinicio) / CLOCKS_PER_SEC * 1000;
        imprimirVector(vector, vInicial, vFinal);

        cout << "Tiempo <ms>:" << tiempo;
        cout << endl;
        cout << endl;
        cout << "CASO MEJOR";
        cout << endl;
        cout << "---------------";
        cout << endl;
        cout << "Vector a ordenar:";
        imprimirVector(vector, vInicial, vFinal);

        cout << "Vector ordenado:";
        imprimirVector(vector, vInicial, vFinal);

        tinicio = clock();
        resultado = insercion(dimensionVector, vector);
        tfinal = clock();
        tiempo = (double)(tfinal - tinicio) / CLOCKS_PER_SEC * 1000;
        cout << "Tiempo <ms>:" << tiempo;
        cout << endl;
        cout << endl;
        cout << "CASO PEOR";
        cout << endl;
        cout << "---------------";
        cout << endl;
        cout << "Vector a ordenar:";
        inversoVector(dimensionVector, vector);
        imprimirVector(vector, vInicial, vFinal);

        tinicio = clock();
        resultado = insercion(dimensionVector, vector);
        tfinal = clock();
        tiempo = (double)(tfinal - tinicio) / CLOCKS_PER_SEC * 1000;
        cout << "Vector ordenado:";
        imprimirVector(vector, vInicial, vFinal);

        cout << "Tiempo <ms>:" << tiempo;
        cout << endl;
        cout << endl;
        cout << "FIN DEL PROGRAMA";
        cout << endl;
        cout << endl;
    }
    cout << endl;
    return 0;
}
