#include <stdlib.h>
#include <iostream>

using namespace std;

/* Grupo: Pedro Gazquez Ruiz (alu39) - Adrián Garrido Pantaleón (alu38) - Albert
 * Lorenzo Segarra (alu51) 

int programa1(int x, int y) {
  if (x <= 1) {
    return y;
  } else {
    return programa1(x - 1, y + 2) - x + y;
  }
} */

int programa1(int x, int y) {
  int resultado = 0;
  while (x > 1) {
    resultado = resultado - x + y;
    x = x - 1;
    y = y + 2;
  }
  return resultado + y;
}

int main() {
  int x, y;

  cout << "Introduce valores de x:" << endl;
  cin >> x;
  cout << "Introduce valores de y:" << endl;
  cin >> y;
  cout << "Resultado: " << programa1(x, y) << endl;

  return 0;
}