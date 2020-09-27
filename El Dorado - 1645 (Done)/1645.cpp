#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) cout << x[i][j] << " "; printf("\n");}}

long long int seq[101];
long long int aux[101][101];


int main() {

  while (1) {
    long long int n,k;
    cin >> n >> k;

    if (n == 0) {
      break;
    }

    // debugM(aux, 101, 101);
  
    for (long long int i=1; i<=n; i++) {
      long long int num;
      cin >> num;
      seq[i] = num;
      aux[1][i] = 1;
    }

    for (long long int i=2; i<=n; i++) {
      for (long long int j=1; j<=n; j++) {
        for (long long int l=1; l<j; l++) {
          if (seq[l] < seq[j]) {
            aux[i][j] = aux[i][j] + aux[i-1][l];
          }
        }
      }
    }

    long long int sum = 0;
    for (long long int i=1; i<=n; i++) {
      sum = sum + aux[k][i];
    }

    cout << sum << endl;

    for (int i=0; i<101; i++) {
      seq[i] = 0;
      for (int j=0; j<101; j++) {
        aux[i][j] = 0;
      }
    }

  }



  return 0;
}