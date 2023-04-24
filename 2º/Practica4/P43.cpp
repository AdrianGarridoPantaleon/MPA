
#include <iostream>
#include <stdlib.h>
#include <stack>

using namespace std;

stack<int> pila;

int p43Recursivo(int x, int y)
{
    if (x <= 4)
        return x + y;
    else
    {
        x = x - 4;
        y = y / 3;
        return p43Recursivo(x, y) + x * y;
    }
}

int p43Iterativo(int x, int y)
{
    int x1 = x, y1 = y, s;

    while (x1 > 4)
    {
        pila.push(y1);
        x1 = x1 - 4;
        y1 = y1 / 3;
    }
    s = x1 + y1;
    while (!pila.empty())
    {
        s = s + (x1) * (y1);
        y1 = pila.top();
        x1 = x1 + 4;
        pila.pop();
    }
    return s;
}

int main()
{
    int x, y;

    cout << "Introduce un numero: " << endl;
    cin >> x;
    cout << "Introduce otro numero: " << endl;
    cin >> y;

    cout << "Numero devuelto: " << p43Recursivo(x, y) << endl;
    cout << "Numero devuelto: " << p43Iterativo(x, y) << endl;
    return 0;
}