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

int countNumberOfFactorsTwo(int n) {
  int count = 0;
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

  int a,b;
  cin >> a >> b;

  if (a == b) {
    cout << "?" << endl;
    return 0;
  }

  int grt = max(a, b);

  bool* isPrime = new bool[INF];
  
  sievePrime(grt, isPrime);

  int n = 0;
  repWithEqual(i,0,grt) {
    if (i >= min(a,b) && isPrime[i] == true) {
      n++;
    }
  }

  int k = grt - min(a,b);
  // debug(k);

  
  int above = n + k - 1;
  int below = n - 1;

  int x = 0;
  if (above > k) {
    int dif = above - k;
    for (int i=above; i > above - dif; i--) {
      x = x + countNumberOfFactorsTwo(i);
    }
  } 
  
  // else if (above == k) {
  //   cout << "Alice" << endl;
  //   return 0;
  // }
  
  int y = 0;
  for (int i=below; i>0; i--) {
    y = y + countNumberOfFactorsTwo(i);
  }

  if (x > y) {
    cout << "Bob" << endl;
  } else {
    cout << "Alice" << endl;
  }

 
  

  

  //int res = factorial(n + k -1) / (factorial(k) * factorial(n - 1));

  // if (res%2 == 0) {
  //   cout << "Bob" << endl;
  // } else {
  //   cout << "Alice" << endl;
  // }

  
  delete[] isPrime;


  return 0;
}