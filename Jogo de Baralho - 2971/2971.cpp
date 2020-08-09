#include <bits/stdc++.h>

using namespace std;

int escolheCartaParaPassar(vector<int> cartasOrdenadas) {
  int currentIndex = 0;
  if (cartasOrdenadas[currentIndex] != cartasOrdenadas[currentIndex + 1]) {
    return cartasOrdenadas[currentIndex];
  } else {
    currentIndex++;
    if (cartasOrdenadas[currentIndex] != cartasOrdenadas[currentIndex + 1]) {
      if (cartasOrdenadas[currentIndex + 1] != cartasOrdenadas[currentIndex + 2]) {
        return cartasOrdenadas[currentIndex + 1];
      } else {
        if (cartasOrdenadas.size() == 4) {
          return cartasOrdenadas[currentIndex];
        } else {
          if (cartasOrdenadas[currentIndex + 2] == cartasOrdenadas[currentIndex + 3]) {
            return cartasOrdenadas[currentIndex];
          } else {
            return cartasOrdenadas[currentIndex + 3];
          }
        }
      }
    } else {
      currentIndex++;
      if (cartasOrdenadas[currentIndex] != cartasOrdenadas[currentIndex + 1]) {
        return cartasOrdenadas[currentIndex + 1];
      } else {
        return cartasOrdenadas[currentIndex + 2];
      }
    }
  }
}

int main() {
  vector<int> teste = { 1, 1, 2, 3 };
  cout << escolheCartaParaPassar(teste) << endl;
  return 0;
}