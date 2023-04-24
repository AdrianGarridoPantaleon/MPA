
#include <stdlib.h>
#include <iostream>

using namespace std;

#define pMax 12

void introducirV(double *v, int n)
{
    for (int i = 1; i <= n; i++)
    {
        cout << "OBJETO " << i << endl;
        cin >> v[i];
    }
}

void imprimirV(double *v, int n)
{
    cout << "VECTOR: ";
    for (int i = 1; i <= n; i++)
    {
        if (i == n)
            cout << v[i] << endl;
        else
            cout << v[i] << ", ";
    }
}
void imprimirVInt(int *v, int n)
{
    cout << "VECTOR: ";
    for (int i = 1; i <= n; i++)
    {
        if (i == n)
            cout << v[i] << endl;
        else
            cout << v[i] << ", ";
    }
}

double calcularSuma(int *xOpt, double *p, int k)
{
    double peso = 0;
    for (int i = 1; i <= k; i++)
    {
        if (xOpt[i] == 1)
            peso += p[i];
        else
            peso += 0;
    }
    return peso;
}

void mochila(int n, double *p, double *v, int *x, int *xOpt, double &vOpt)
{
    int i, j, k = 1;
    double peso, valor;

    if (k <= n)
    {
        while (k > 0)
        {
            if ((x[k] + 1) == 0 || (x[k] + 1) == 1)
            {
                x[k] = x[k] + 1;

                peso = calcularSuma(x, p, k);
                if (peso <= pMax)
                {
                    if (k == n)
                    {
                        valor = calcularSuma(x, v, k);
                        if (valor > vOpt)
                        {
                            cout << "X: ";
                            for (int i = 1; i <= n; i++)
                            {
                                cout << x[i] << " ";
                            }
                            cout << endl;
                            for (j = 1; j <= k; j++)
                                xOpt[j] = x[j];

                            vOpt = valor;
                        }
                    }
                    else
                    {
                        k++;
                    }
                }
            }
            else
            {
                x[k] = -1;
                k--;
            }
        }
    }
}

int main()
{
    int n, *xOpt, *x;
    double *pesos, *valores, vOpt = -999, peso, valor;

    cout << "Introduce el numero de objetos a llevar: ";
    cin >> n;

    pesos = new double[n + 1];
    valores = new double[n + 1];
    xOpt = new int[n + 1];
    x = new int[n + 1];

    for (int i = 1; i <= n; i++)
    {
        x[i] = -1;
        xOpt[i] = 0;
    }

    cout << "\nIntroduce los pesos de los objetos: " << endl;
    introducirV(pesos, n);

    cout << "\nIntroduce los valores de los objetos: " << endl;
    introducirV(valores, n);

    mochila(n, pesos, valores, x, xOpt, vOpt);

    cout << "\nLos objetos que hay que meter son:" << endl;
    for (int i = 1; i <= n; i++)
    {
        if (xOpt[i] == 1)
        {
            cout << i << ": " << pesos[i] << " KG y " << valores[i] << " VALOR" << endl;
            peso += pesos[i];
            valor += valores[i];
        }
    }

    cout << "\nEl peso que puedes llevar en la mochila es: " << peso << endl;
    cout << "El valor maximo que puedes llevar en la mochila es: " << valor << endl;

    cout << "\nLos objetos que no puedes llevar son el:";
    for (int i = 1; i <= n; i++)
    {
        if (xOpt[i] == 0)
            cout << " " << i;
    }
}