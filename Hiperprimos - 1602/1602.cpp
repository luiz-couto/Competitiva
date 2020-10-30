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

bool isPrimeTable[2*1000000];

int countDivisors(int n) {
  bool table[n+1];
  memset(table, true, sizeof(table));

  for (int i=2; i*i<n; i++) {
    if (table[i]) {
      for (int j = i*2; j<n; j += i) table[j] = false;
    }
  }

  int res = 1;
  repWithEqual(i, 2, n) {
    if (table[i]) {
      int counter = 0;
      if (n % i == 0) {
        while (n % i == 0) {
          n = n/i;
          counter++;
        }
        res = res * (counter + 1);
      }
    }
  }

  return res;

}

bool isPrime(int n) {
  if (n <= 1) return false;
  else if (n <= 3) return true;
  else if ((n % 5 == 0 && n != 5) || (n % 7 == 0 && n != 7) || (n % 13 == 0 && n != 13) || (n % 17 == 0 && n != 17) || (n % 19 == 0 && n != 19)) return false;

  if (n % 2 == 0 || n % 3 == 0) return false;

  for (int i = 5; i * i <= n; i = i + 6) {
    if (n % i == 0 || n % (i+2) == 0) return false;
  }

  return true;
}


int main() {
  cout << countDivisors(1000000) << endl;
  return 0;
}