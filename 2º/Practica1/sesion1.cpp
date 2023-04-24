#include <iostream>

using namespace std;

int contar(int *V, int n, int x)
{
    int nVeces = 0;
    for (int i = 1; i <= n; i++)
    {
        if (V[i] == x)
        {
            nVeces = nVeces + 1;
        }
    }
    return nVeces;
}

int main()
{
    int n, x, *Vpeor, *Vmejor, *Vcualquiera;
    cout << "Introduce el valor a buscar" << endl;
    cin >> x;
    cout << "Introduce el tamanyo del vector" << endl;
    cin >> n;

    Vpeor = new int[n + 1];
    Vmejor = new int[n + 1];
    Vcualquiera = new int[n + 1];

    cout << "Vector Vpeor:" << endl;
    for (int i = 1; i <= n; i++)
    {
        Vpeor[i] = x;
        if (i != n)
            cout << Vpeor[i] << " ";
        else
            cout << Vpeor[i];
    }
    cout << endl;

    cout << "Vector Vmejor:" << endl;
    for (int i = 1; i <= n; i++)
    {
        Vmejor[i] = x + i;
        if (i != n)
            cout << Vmejor[i] << " ";
        else
            cout << Vmejor[i];
    }
    cout << endl;

    cout << "Vector Vcualquiera:" << endl;
    for (int i = 1; i <= n; i++)
    {
        if (i <= n / 2)
            Vcualquiera[i] = x;
        else
            Vcualquiera[i] = x + i;
        if (i != n)
            cout << Vcualquiera[i] << " ";
        else
            cout << Vcualquiera[i];
    }
    cout << endl
         << endl;

    cout << "CASO PEOR" << endl;
    cout << "Numero veces: " << contar(Vpeor, n, x) << endl;
    cout << "CASO MEJOR" << endl;
    cout << "Numero veces: " << contar(Vmejor, n, x) << endl;
    cout << "OTRO CASO" << endl;
    cout << "Numero veces: " << contar(Vcualquiera, n, x) << endl;
    cout << endl;
    return 0;
}