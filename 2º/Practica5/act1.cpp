
#include <iostream>
#include <stdlib.h>
#include <stack>

using namespace std;

#define inf 99999

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
                posmin = j;
            }
        }
        intercambiar(arr[i], arr[posmin]);
    }
}

void combinar(int *&V1, int *&V2, int *&V, int n1, int n2)
{
    int i1, i2, i;
    i1 = i2 = 1;
    V1[n1 + 1] = inf;
    V2[n2 + 1] = inf;

    for (i = 1; i <= n1 + n2; i++)
    {
        if (V1[i1] < V2[i2])
        {
            V[i] = V1[i1];
            i1 = i1 + 1;
        }
        else
        {
            V[i] = V2[i2];
            i2 = i2 + 1;
        }
    }
}

void mergeSort(int n, int *&V)
{
    auto const nInf = n / 2, nSup = n - nInf;
    auto *V1 = new int[nInf + 1], *V2 = new int[nSup + 1];

    if (n < 3)
    {
        seleccion(n, V);
    }
    else
    {
        for (int i = 1; i <= nInf; i++)
        {
            V1[i] = V[i];
        }

        for (int i = 1; i <= nSup; i++)
        {
            V2[i] = V[nInf + i];
        }

        mergeSort(nInf, V1);
        mergeSort(nSup, V2);
        combinar(V1, V2, V, nInf, nSup);
    }
}

int main()
{
    int n, *V, r;

    cout << "Introduce el tamanyo del vector" << endl;
    cin >> n;
    V = new int[n + 1];

    for (int i = 1; i <= n; i++)
    {
        cout << "Introduzca el numero de la posicion " << i << ": " << endl
             << endl;
        cin >> r;
        V[i] = r;
    }

    cout << "\nVECTOR IMPRESO INICIAL: " << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << V[i] << ", ";
    }

    mergeSort(n, V);

    cout << "\nVECTOR IMPRESO FINAL: " << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << V[i] << ", ";
    }
}