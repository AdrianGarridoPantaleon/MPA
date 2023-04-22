#include <stdlib.h>
#include <iostream>
#include <stack>

using namespace std;

/* Grupo: Pedro Gazquez Ruiz (alu39) - Adrián Garrido Pantaleón (alu38) - Albert
  Lorenzo Segarra (alu51)

int recursivo(int a, int b) {
  if (a < 3) {
    return a + b;
  } else {
    return recursivo(a / 3, b - 2) + a;
  }
} */

int programa3(int a, int b) {
  int a0, b0, reslt;
  stack<int> pila;
  a0 = a;
  b0 = b;
  reslt = 0;
  while (3 <= a0) {
    pila.push(a0);
    a0 /= 3;
    b0 -= 2;
  }
  reslt = a0 + b0;
  while (a0 < a) {
    a0 = pila.top();
    pila.pop();
    reslt += a0;
  }
  return reslt;
}

int main() {
  int x, y;

  cout << "Introduce valores de x:" << endl;
  cin >> x;
  cout << "Introduce valores de y:" << endl;
  cin >> y;
  cout << "Resultado: " << programa3(x, y) << endl;
  return 0;
}