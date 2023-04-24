
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>

using namespace std;

void intercambiar(int &x, int &y, int &pos1, int &pos2)
{
    int temp, temp2;
    temp = x;
    x = y;
    y = temp;

    temp2 = pos1;
    pos1 = pos2;
    pos2 = temp2;
}

void seleccion(int &n, int *&arr, int *&posiciones)
{
    int i, j, posmin;

    for (i = 1; i < n; i++)
    {
        posmin = i;
        for (j = i + 1; j <= n; j++)
        {
            if (arr[j] < arr[posmin])
            {
                posmin = j;
            }
        }
        intercambiar(arr[i], arr[posmin], posiciones[i], posiciones[posmin]);
    }
}

int main()
{
    int n, *arr, j = 1, tiempo = 0, *posiciones, i;

    cout << "Introduce el numero de procesos: \n";
    cin >> n;

    arr = new int[n + 1];
    posiciones = new int[n + 1];

    cout << "Introduce el tiempo de cada proceso: \n";
    for (i = 1; i <= n; i++)
    {
        cin >> arr[i];
        posiciones[i] = i;
    }

    seleccion(n, arr, posiciones);

    for (i = 1; j <= n; i++)
    {
        tiempo += arr[i];
        if (i == j)
        {
            j++;
            i = 0;
        }
    }

    cout << "\nTiempo minimo total de permanencia en el sistema: " << tiempo << endl;

    cout << "Orden en que deben ejecutarse: ";
    for (i = 1; i <= n; i++)
    {
        if (i != n)
        {
            cout << posiciones[i] << " --> ";
        }
        else
            cout << posiciones[i];
    }
}