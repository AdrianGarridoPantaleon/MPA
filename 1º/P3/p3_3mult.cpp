#include <iostream>

using namespace std;

int multiplicacion(int x, int y, int indice) {
  if (x == 1) {
    cout << indice << ")multiplicacion(" << x << "," << y << ")" << endl;
    return y;
  } else {
    cout << indice << ")multiplicacion(" << x << "," << y << ")" << endl;
    indice++;
    if (x % 2 != 0) {
      return y + multiplicacion(x / 2, y * 2, indice);
    } else {
      return multiplicacion(x / 2, y * 2, indice);
    }
  }
}

int main() {
  int x, y;

  cout << "3. MULTIPLICACION" << endl;
  cout << "-----------------" << endl;
  cout << "Introduce primer numero:";
  cin >> x;
  cout << "\nIntroduce segundo numero:";
  cin >> y;
  cout << "\nTraza" << endl;
  cout << "\nEl resultado es: " << multiplicacion(x, y, 1) << endl;
  return 0;
}