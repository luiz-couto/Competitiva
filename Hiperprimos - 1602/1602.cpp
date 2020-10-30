#include <bits/stdc++.h>

using namespace std;

#define INF 1000000000
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define repWithEqual(i, a, b) for(int i = int(a); i <= int(b); i++)
#define debugLine() cout << "PASSSSOUUU AQUIIII" << endl;
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";
#define debugA(x, l) { rep(i,0,l) { cout << x[i] << " "; } printf("\n"); }
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) cout << x[i][j] << " "; printf("\n");}}
#define setM( x, l, c, k ) { rep( i, 0, l ){ rep( j, 0, c ) x[i][j] = k;}}

int table[2*1000000];


void sieve(int n, bool prime[], bool primeSquare[], int aux[]) {
  repWithEqual(i, 2, n) prime[i] = true;
  repWithEqual(i, 0, (n*n+1)) primeSquare[i] = false;

  prime[1] = false;

  for (int p = 2; p*p <= n; p++) {
    if (prime[p]) {
      for (int i = p*2; i <= n; i += p) prime[i] = false;
    }
  }

  int j = 0;
  repWithEqual(p, 2, n) {
    if (prime[p]) {
      aux[j] = p;
      primeSquare[p*p] = true;
      j++;
    }
  }
}

int countDivisors(int n) {
  if (n == 1) return 1;
  
  bool prime[n + 1];
  bool primeSquare[n*n+1];
  int aux[n];

  sieve(n, prime, primeSquare, aux);

  int res = 1;
  for (int i=0; ; i++) {
    if (aux[i] * aux[i] * aux[i] > n) break;

    int counter = 1;
    while (n % aux[i] == 0) {
      n = n / aux[i];
      counter++;
    }

    res = res * counter;

  }

  if (prime[n]) res = res * 2;
  else if (primeSquare[n]) res = res * 3;
  else if (n != 1) res = res * 4;

  return res;

}


int main() {
  cout << countDivisors(900) << endl;
  return 0;
}