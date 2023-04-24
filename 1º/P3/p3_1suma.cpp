#include <iostream>

using namespace std;

int sumaDigitos(int num, int indice) {
  if (num < 0) {
    cout << indice << ")sumadigitos(" << num << ")" << endl;
    return -1;
  }
  if (num < 10) {
    cout << indice << ")sumadigitos(" << num << ")" << endl;
    return num;
  }
  if (num >= 10) {
    cout << indice << ")sumadigitos(" << num << ")" << endl;
    indice++;
    return (num % 10) + sumaDigitos(num / 10, indice);
  }
  return 0;
}

int main() {
  int n;

  cout << "1. SUMA DIGITOS" << endl;
  cout << "---------------" << endl;
  cout << "Introduce numero:";
  cin >> n;
  cout << "\nTraza" << endl;
  cout << "\nEl resultado es: " << sumaDigitos(n, 1) << endl;

  return 0;
}