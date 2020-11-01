#include <bits/stdc++.h>

using namespace std;

#define INF 10000000
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define repWithEqual(i, a, b) for(int i = int(a); i <= int(b); i++)
#define debugLine() cout << "PASSSSOUUU AQUIIII" << endl;
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";
#define debugA(x, l) { rep(i,0,l) { cout << x[i] << " "; } printf("\n"); }
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) cout << x[i][j] << " "; printf("\n");}}
#define setM( x, l, c, k ) { rep( i, 0, l ){ rep( j, 0, c ) x[i][j] = k;}}


void sievePrime(int n, bool isPrime[]) {

  isPrime[0] = false;
  isPrime[1] = false;
  
  repWithEqual(i, 2, n) isPrime[i] = true;
  for (int p = 2; p * p <= n; p++) { 
    if (isPrime[p]) { 
      for (int i = p * 2; i <= n; i += p) {
        isPrime[i] = false; 
      }
    } 
  }
}

long long int countNumberOfFactorsTwo(long long int n) {
  long long int count = 0;
  while(1) {
    if (n%2 == 0) {
      count++;
    } else {
      break;
    }
    n = n/2;
  }
  return count;
}

int main() {

  long long int a,b;
  cin >> a >> b;

  if (a == b) {
    cout << "?" << endl;
    return 0;
  }

  long long int grt = max(a, b);

  bool* isPrime = new bool[INF];
  
  sievePrime(grt, isPrime);

  long long int n = 0;
  repWithEqual(i,0,grt) {
    if (i >= min(a,b) && isPrime[i] == true) {
      n++;
    }
  }

  if (n == 0) {
    cout << "Bob" << endl;
    return 0;
  }

  long long int k = grt - min(a,b);
  // debug(k);

  
  long long int above = n + k - 1;
  long long int below = n - 1;

  long long int x = 0;
  for (long long int i=above; i>0; i--) {
    x = x + countNumberOfFactorsTwo(i);
  }

  long long int z = 0;
  for (long long int i=k; i>0; i--) {
    z = z + countNumberOfFactorsTwo(i);
  }

  
  long long int y = 0;
  for (long long int i=below; i>0; i--) {
    y = y + countNumberOfFactorsTwo(i);
  }

  if (x > (y+z)) {
    cout << "Bob" << endl;
  } else {
    cout << "Alice" << endl;
  }
  
  delete[] isPrime;

  return 0;
}