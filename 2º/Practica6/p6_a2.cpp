
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>

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
    ifstream fDatos;
    char linea[200], *tok;
    int n, *arr, j = 1, tiempo = 0, *posiciones, i;

    fDatos.open("a2_entrada3.txt");

    fDatos.getline(linea, 200);
    tok = strtok(linea, " \t\r\n");
    n = atoi(tok);

    arr = new int[n + 1];
    posiciones = new int[n + 1];

    fDatos.getline(linea, 200);
    tok = strtok(linea, " \t\r\n");
    i = 1;
    arr[i] = atoi(tok);
    posiciones[i] = i;
    for (i = 2; i <= n; i++)
    {
        tok = strtok(NULL, " \t\r\n");
        arr[i] = atoi(tok);
        posiciones[i] = i;
    }

    cout << "n = " << n << "\n";
    cout << "vector -> [ " << arr[1];
    for (i = 2; i <= n; i++)
        cout << " , " << arr[i];
    cout << " ]\n\n";
    fDatos.close();

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