#include <bits/stdc++.h>

using namespace std;

vector<int> firstPile;
vector<int> secondPile;
vector<int> thirdPile;

bool isPossible = false;

map<string, bool> alreadyView;

void verifyAllInGivenPositions(int f, int s, int t, int n) {
  if (!isPossible) {

    string str;
    str.push_back(f + '0');
    str.push_back(s + '0');
    str.push_back(t + '0');

    bool aux = alreadyView[str];
    alreadyView[str] = true;

    if (f == n && s == n && t == n) {
      isPossible = true;
    }

    if (aux != true) {
      if (f != n && s != n && t != n && (firstPile[f] + secondPile[s] + thirdPile[t])%3 == 0 && !isPossible) {
        verifyAllInGivenPositions(f+1, s+1, t+1, n);
      }

      if (f != n && s != n && (firstPile[f] + secondPile[s])%3 == 0 && !isPossible) {
        verifyAllInGivenPositions(f+1, s+1, t, n);
      }

      if (f != n && t != n && (firstPile[f] + thirdPile[t])%3 == 0 && !isPossible) {
        verifyAllInGivenPositions(f+1, s, t+1, n);
      }

      if (s != n && t != n && (secondPile[s] + thirdPile[t])%3 == 0 && !isPossible) {
        verifyAllInGivenPositions(f, s+1, t+1, n);
      }

      if (f != n && (firstPile[f])%3 == 0 && !isPossible) {
        verifyAllInGivenPositions(f+1, s, t, n);
      }

      if (s != n && (secondPile[s])%3 == 0 && !isPossible) {
        verifyAllInGivenPositions(f, s+1, t, n);
      }

      if (t != n && (thirdPile[t])%3 == 0 && !isPossible) {
        verifyAllInGivenPositions(f, s, t+1, n);
      }
    }


  }
  
}


int main() {
  
  while (1) {
    int n;
    cin >> n;

    if (n == 0) {
      break;
    }

    for (int i=0; i<n; i++) {
      int f;
      cin >> f;
      firstPile.push_back(f);

      int s;
      cin >> s;
      secondPile.push_back(s);

      int t;
      cin >> t;
      thirdPile.push_back(t);
    }

    verifyAllInGivenPositions(0,0,0,n);

    cout << isPossible << endl;

    firstPile = {};
    secondPile = {};
    thirdPile = {};
    isPossible = false;
    alreadyView.clear();
    
  }

  return 0;
}