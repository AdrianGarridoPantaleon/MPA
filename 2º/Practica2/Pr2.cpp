#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

void intercambiar(int &x, int &y)
{
    int temp;
    temp = x;
    x = y;
    y = temp;
}

void seleccion(int &n, int *&arr)
{
    int i, j, posmin;

    for (i = 1; i < n; i++)
    {
        posmin = i;
        for (j = i + 1; j <= n; j++)
        {
            if (arr[j] < arr[posmin])
            {
                cout << "Intercambio: " << arr[j] << " --> " << arr[posmin] << endl;
                posmin = j;
            }
        }
        intercambiar(arr[i], arr[posmin]);
    }
}
void seleccionInversa(int &n, int *&arr)
{
    int i, j, posmin;

    for (i = 1; i < n; i++)
    {
        posmin = i;
        for (j = i + 1; j <= n; j++)
        {
            if (arr[j] > arr[posmin])
            {
                posmin = j;
            }
        }
        intercambiar(arr[i], arr[posmin]);
    }
}

void imprimir(int n, int *&arr, string nombre)
{
    int r = n;
    clock_t tinicio, tfin;
    double tiempo;
    if (n > 10)
        r = 10;
    cout << "Posiciones del array sin ordenar: ";
    for (int i = 1; i <= r; i++)
    {
        if (i != r)
            cout << arr[i] << ", ";
        else
            cout << arr[i] << endl << endl;
    }
    tinicio = clock();
    seleccion(n, arr);
    tfin = clock();
    tiempo = (double)(tfin - tinicio) / CLOCKS_PER_SEC * 1000;

    cout << "El tiempo de ejecucion en ms del vector " << nombre << " es " << tiempo << "ms" << endl;

    cout << "Posiciones del array ordenado: ";
    for (int i = 1; i <= r; i++)
    {
        if (i != r)
            cout << arr[i] << ", ";
        else
            cout << arr[i] << endl
                 << endl;
    }
}

int main()
{
    int n, *arr;
    srand(time(NULL));

    cout << "Introduce el tamanyo del vector" << endl;
    cin >> n;

    arr = new int[n + 1];

    for (int i = 1; i <= n; i++)
    {
        arr[i] = rand() % 100;
    }
    cout << "-----------------------ARRAY NORMAL-----------------------"<< endl;
    imprimir(n, arr, "normal");
    cout << "-----------------------ARRAY MEJOR-----------------------"<< endl;
    imprimir(n, arr, "mejor"); // Vuelvo a imprimir el vector ahora que esta  ordenado, de manera que es el mejor caso

    cout << "-----------------------ARRAY PEOR-----------------------"<< endl;
    seleccionInversa(n, arr); // Ordeno el array peor de forma descendente, que es el orden contrario al que buscamos, obteniendo así, el mejor caso
    imprimir(n, arr, "peor");

    return 0;
}