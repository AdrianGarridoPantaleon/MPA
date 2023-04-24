
#include <iostream>
#include <stdlib.h>
#include <stack>

using namespace std;

double p42(double x, int n)
{
    double r;
    if (n == 0)
    {
        r = 1;
    }
    else
    {
        if (n % 2 != 0)
        {
            r = x * p42(x, n - 1);
        }
        else
        {
            r = p42(x, n / 2);
            r = r * r;
        }
    }
    return r;
}

double p42iter(double x, int n)
{
    double p1;
    double p2;
    double s = 1;
    p1 = x;
    p2 = n;
 
    while (p2 > 0)
    {
        s = p1 * s;
        p2--;
    }
    return s;
}

int main()
{
    double x = 0;
    int n = 0;
    cout << "introduzca el primer valor: ";
    cin >> x;

    cout << "introduzca el segundo valor: ";
    cin >> n;

    if (n < 0)
    {
        cout << "Error" << endl;
        return -1;
    }

    cout << p42(x, n) << endl;
    cout << p42iter(x, n) << endl;
    return 0;
}