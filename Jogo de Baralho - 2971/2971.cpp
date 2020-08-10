#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> playersCards;

int escolheCartaParaPassar(int currentPlayer) {
  int currentIndex = 0;
  vector<int> cartasOrdenadas = playersCards[currentPlayer];
  if (cartasOrdenadas[currentIndex] != cartasOrdenadas[currentIndex + 1]) {
    playersCards[currentPlayer].erase(playersCards[currentPlayer].begin() + currentIndex);
    return cartasOrdenadas[currentIndex];
  } else {
    currentIndex++;
    if (cartasOrdenadas[currentIndex] != cartasOrdenadas[currentIndex + 1]) {
      if (cartasOrdenadas[currentIndex + 1] != cartasOrdenadas[currentIndex + 2]) {
        playersCards[currentPlayer].erase(playersCards[currentPlayer].begin() + currentIndex + 1);
        return cartasOrdenadas[currentIndex + 1];
      } else {
        if (cartasOrdenadas.size() == 4) {
          playersCards[currentPlayer].erase(playersCards[currentPlayer].begin() + currentIndex);
          return cartasOrdenadas[currentIndex];
        } else {
          if (cartasOrdenadas[currentIndex + 2] == cartasOrdenadas[currentIndex + 3]) {
            playersCards[currentPlayer].erase(playersCards[currentPlayer].begin() + currentIndex);
            return cartasOrdenadas[currentIndex];
          } else {
            playersCards[currentPlayer].erase(playersCards[currentPlayer].begin() + currentIndex + 3);
            return cartasOrdenadas[currentIndex + 3];
          }
        }
      }
    } else {
      currentIndex++;
      if (cartasOrdenadas[currentIndex] != cartasOrdenadas[currentIndex + 1]) {
        playersCards[currentPlayer].erase(playersCards[currentPlayer].begin() + currentIndex + 1);
        return cartasOrdenadas[currentIndex + 1];
      } else {
        if (cartasOrdenadas.size() == 4) {
          playersCards[currentPlayer].erase(playersCards[currentPlayer].begin() + currentIndex + 1);
          return cartasOrdenadas[currentIndex + 1];
        }
        playersCards[currentPlayer].erase(playersCards[currentPlayer].begin() + currentIndex + 2);
        return cartasOrdenadas[currentIndex + 2];
      }
    }
  }
}

bool verificaVitoria(int currentPlayer) {
  vector<int> cartas = playersCards[currentPlayer];
  if (cartas.size() == 3) {
    return false;
  }
  if (cartas[0] == cartas[3]) {
    return true;
  }
  return false;
}

int main() {

  int n;
  int k;

  cin >> n >> k;
  
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

    sort(playerHand.begin(), playerHand.end());
    if (k != i + 1 && playerHand[0] == playerHand[3]) {
      cout << i + 1 << endl;
      return 0;
    }
    playersCards.push_back(playerHand);

  }

  // for (int i=0; i<playersCards.size(); i++) {
    
  //   for (int j=0; j<playersCards[i].size(); j++) {
  //     cout << playersCards[i][j] << ", ";
  //   }
  //   cout << endl;
  // }

  int currentPlayer = k-1;
  
  int olderJoker = -1;
  int joker = k-1;

  while(1) {
    bool fimDaJogada = false;
    if (joker == currentPlayer) {
      if (olderJoker == joker) {
        // Passando o joker
        if (joker + 1 == n) {
          olderJoker = joker;
          joker = 0;
        } else {
          olderJoker = joker;
          joker = joker+1;
        }
        fimDaJogada = true;
        if (verificaVitoria(currentPlayer)) {
          cout << currentPlayer+1 << endl;
          break;
        }
        currentPlayer = (currentPlayer + 1 == n) ? 0 : currentPlayer + 1;
      } else {
        // Não passei o joker
        olderJoker = joker;
      }
    }

    if (!fimDaJogada) {
      int cardToPass = escolheCartaParaPassar(currentPlayer);
      int playerToPassCard = (currentPlayer + 1 == n) ? 0 : currentPlayer + 1;
      playersCards[playerToPassCard].push_back(cardToPass);
      sort(playersCards[playerToPassCard].begin(), playersCards[playerToPassCard].end());
      if (verificaVitoria(currentPlayer)) {
        cout << currentPlayer+1 << endl;
        break;
      }
      currentPlayer = (currentPlayer + 1 == n) ? 0 : currentPlayer + 1;
    }

  }

  return 0;
}