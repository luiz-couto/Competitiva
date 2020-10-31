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

void sievePrime(int n, bool isPrime[]) {
  if(n > 1000000) n = n/10;
  
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

int* findPrimePair(int n) 
{ 
  static int res[2];

  bool* isPrime = new bool[INF];
  sievePrime(n, isPrime);

  rep(i,2,n) {
    int x = n / i; 

    if (isPrime[i] && isPrime[x] && x != i && x * i == n) {
      res[0] = i;
      res[1] = x;
      return res;
    }
  }

  delete[] isPrime;
  return res;
}

int gcdExtended(int a, int b, int *x, int *y)  
{  

  if (a == 0) {
    *x = 0, *y = 1;  
    return b;  
  }  

  int x1, y1; 
  int gcd = gcdExtended(b%a, a, &x1, &y1);  

  *x = y1 - (b/a) * x1;  
  *y = x1;  

  return gcd;
}

int modInverse(int a, int m)  
{  
  int x, y;  
  int g = gcdExtended(a, m, &x, &y);  
  if (g != 1) return -1;  
  else {
    int res = (x%m + m) % m;  
    return res;
  }
}

long long int getMessage(long long int c, long long int d,long long int n){
  
  if (d < 0LL){
    c = 1LL / c;
    d = -d;
  }
  
  if (d == 0LL) return 1LL;
  long long int y=1LL;
  
  while (d > 1LL){
    if (d%2 == 0LL) {
      c = (c * c)%n;
      d = d / 2LL;
    }
    else {
      y = (c * y)%n;
      c = (c * c)%n;
      d = (d-1LL)/2LL;
    }
  }
  
  return (c*y)%n;
}

int main() {
  

  int n,e,c;
  cin >> n >> e >> c;

  int *p;

  p = findPrimePair(n);

  int phi = (p[0] - 1)*(p[1] - 1);
  //debug(phi);

  int D = modInverse(e, phi);
  //debug(D);

  cout << getMessage(c, D, n) << endl;
  
  return 0;
}