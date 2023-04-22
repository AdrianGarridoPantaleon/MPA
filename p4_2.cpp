#include <stdlib.h>

#include <iostream>
#include <stack>

using namespace std;

/* Grupo: Pedro Gazquez Ruiz (alu39) - Adrián Garrido Pantaleón (alu38) - Albert
  Lorenzo Segarra (alu51)*/

#include <stdlib.h>

#include <iostream>
#include <stack>

using namespace std;

int programa2(int x, int y) {
  int z, y0;
  stack<int> pila;
  y0 = y;
  while (y0 > 0) {
    pila.push(y0);
    y0 /= 2;
  }
  z = 1;
  while (y0 != y) {
    y0 = pila.top();
    pila.pop();
    z *= z;
    if (y0 % 2 == 1) {
      z *= x;
    }
  }
  return z;
}

int main() {
  int x, y;

  cout << "Introduce valores de x:" << endl;
  cin >> x;
  cout << "Introduce valores de y:" << endl;
  cin >> y;
  if (y >= 0) {
    cout << "Resultado: " << programa2(x, y) << endl;
  } else {
    cout << "Resultado: Error" << endl;
  }

  return 0;
}
