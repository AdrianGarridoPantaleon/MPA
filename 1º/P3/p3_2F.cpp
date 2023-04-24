#include <iostream>

using namespace std;

float f(int x, float y) { 
  cout << "F(" << x << "," << y << ")" << endl;
  if (x == 0) { 
    return 1;
  }
  if (x == 1) {
    return 2 * y;
  }
  if (x >= 2) {
    return 2 * y * f(x - 1, y) - 2 * (x - 1) * f(x - 2, y);
  }
  return 0;
}

int main() {
  int x;
  float y, result;

  cout << "2. FUNCION F" << endl;
  cout << "------------" << endl;
  cout << "Introduce valor x:";
  cin >> x;
  cout << "\nIntroduce valor y:";
  cin >> y;

  if ((x >= 0) && (y >= 0)) {
    cout << "\nTraza" << endl;
    result = f(x, y);
    cout << "\nEl resultado es: " << result << endl;
  } else {
    cout << "\nError" << endl;
  }
  return 0;
}