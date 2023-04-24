#include <iostream>
#include <stdlib.h>
#include <stack>

using namespace std;

stack<int> pila;
stack<int> pilaFinal;

void binario(int num)
{
    int temp = num, final = num, iter = 0;
    int resto;
    int arr[100];

    while (num != 0)
    {
        num = num / 2;
        if ((num * 2) != temp)
            resto = 1;
        else
            resto = 0;

        arr[iter] = resto;
        iter++;
        cout << temp << "/2 --> cociente " << num << " y resto " << resto << endl;
        pila.push(resto);
        temp = num;
    }
    cout << "Los restos obtenidos en las divisiones son ";

    for (int i = 0; i < iter; i++)
    {
        if (i == (iter - 1))
            cout << " y " << arr[i];
        else if (i == (iter - 2))
            cout << arr[i];
        else
            cout << arr[i] << ", ";
    }
    if (final == 0)
        cout << ". Si los cogemos en orden contrario a su obtencion, el numero " << final << " en binario es 0";
    else
    {

        while (!pila.empty())
        {
            num = pila.top();
            if (pila.size() == 1)
                cout << num << ".";
            else
                cout << num;

            pila.pop();
        }
    }
}

int main()
{
    int n;

    cout << "Introduzca el numero que quiere en binario: " << endl;
    cin >> n;
    binario(n);
}