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
  isPrime[0] = isPrime[1] = false; 
    for (int i = 2; i <= n; i++) 
        isPrime[i] = true; 
  
    for (int p = 2; p * p <= n; p++) { 
        // If isPrime[p] is not changed, then it is 
        // a prime 
        if (isPrime[p] == true) { 
            // Update all multiples of p 
            for (int i = p * 2; i <= n; i += p) 
                isPrime[i] = false; 
        } 
    }
}

int* findPrimePair(int n) 
{ 
  static int res[2];

  bool* isPrime = new bool[INT_MAX];
  sievePrime(n, isPrime); 

  for (int i = 2; i < n; i++) { 
    int x = n / i; 

    if (isPrime[i] && isPrime[x] and x != i and x * i == n) { 
      cout << i << " " << x << endl;
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
  // Base Case  
  if (a == 0)  
  {  
    *x = 0, *y = 1;  
    return b;  
  }  

  int x1, y1; // To store results of recursive call  
  int gcd = gcdExtended(b%a, a, &x1, &y1);  

  // Update x and y using results of recursive  
  // call  
  *x = y1 - (b/a) * x1;  
  *y = x1;  

  return gcd;  
}

int modInverse(int a, int m)  
{  
  int x, y;  
  int g = gcdExtended(a, m, &x, &y);  
  if (g != 1)  
    return -1;  
  else
  {  
    // m is added to handle negative x  
    int res = (x%m + m) % m;  
    return res;
  }
}

long long int expt(long long int x, long long int n,long long int M){
    if (n < 0LL){
      x = 1LL / x;
      n = -n;
    }
    if (n == 0LL) return 1LL;
    long long int y=1LL;
    while (n > 1LL){
        if (n%2==0LL){
            x = (x * x)%M;
            n = n / 2LL;
        }
        else{
            y = (x * y)%M;
            x = (x * x)%M;
            n = (n-1LL)/2LL;
        }
    }
    return (x*y)%M;
}

int main() {
  

  int n,e,c;
  cin >> n >> e >> c;

  int *p;
  p = findPrimePair(n);

  int phi = (p[0] - 1)*(p[1] - 1);
  debug(phi);

  int D = modInverse(e, phi);
  debug(D);

  cout << expt(c, D, n) << endl;
  
  return 0;
}