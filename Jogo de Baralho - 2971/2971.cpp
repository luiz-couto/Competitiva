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
  // vector<int> teste = { 2, 1, 1, 3 };
  // vector<int>::iterator b = teste.begin();
  // vector<int>::iterator e = teste.end() - 1;
  // sort(b, e);
  // for (int i=0; i<teste.size(); i++ ) {
  //   cout << teste[i] << ", ";
  // }
  // cout << endl;

  int n;
  int k;

  cin >> n >> k;

  vector<vector<int>> playersCards;
  
  for (int i=0; i<n; i++) {
    string s;
    cin >> s;
    
    vector<int> playerHand;
    
    for (int j=0; j<s.length(); j++) {
      if (s[j] == 'A') {
        playerHand.push_back(1);
      } else if (s[j] == 'D') {
        playerHand.push_back(10);
      } else if (s[j] == 'Q') {
        playerHand.push_back(11);
      } else if (s[j] == 'J') {
        playerHand.push_back(12);
      } else if (s[j] == 'K') {
        playerHand.push_back(13);
      } else {
        string str(1, s[j]);
        playerHand.push_back(stoi(str));
      }
    }
    playersCards.push_back(playerHand);
  }

  for (int i=0; i<playersCards.size(); i++) {
    for (int j=0; j<playersCards[i].size(); j++) {
      cout << playersCards[i][j] << ", ";
    }
    cout << endl;
  }
  

  return 0;
}