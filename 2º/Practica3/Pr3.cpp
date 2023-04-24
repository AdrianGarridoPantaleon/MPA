#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int t = 0;

int combinaciones(const int &n, const int &k)
{
    t++;
    cout<< t << "-. combinaciones_traza("<< n << "," << k<< ")" << endl;
    if (k == 0 || k == n)
    {
        return 1;
    }
    else
    {
        return combinaciones(n-1,k-1) + combinaciones(n-1,k);
    }
}

int main()
{
    int n, k;

    cout << "Introduce el valor de n" << endl;
    cin >> n;
    cout << "Introduce el valor de k" << endl;
    cin >> k;

    cout<< "Resultado: " << endl << combinaciones(n, k) << endl;

    return 0;
}