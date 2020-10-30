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

int isPrimeTable[2*1000000];
int numberOfDivisorsTable[2*1000000];
int hiper[2*1000000];

int countDivisors(int n) {
  int aux = (int)pow(n,1/2.0);
  int res = 0;

  for(int j=2;j<aux;j++){
    if(n % j == 0) res++;
  }

  res++;
  res *= 2;
  res++;

  return res;

}

int isPrime(int n) {
  if (n <= 1) return 0;
  else if (n <= 3) return 1;
  else if ((n % 5 == 0 && n != 5) || (n % 7 == 0 && n != 7) || (n % 13 == 0 && n != 13) || (n % 17 == 0 && n != 17) || (n % 19 == 0 && n != 19)) return 0;

  if (n % 2 == 0 || n % 3 == 0) return 0;

  for (int i = 5; i * i <= n; i = i + 6) {
    if (n % i == 0 || n % (i+2) == 0) return 0;
  }

  return 1;
}


int main() {

  memset(isPrimeTable, -1, sizeof(isPrimeTable));
  memset(numberOfDivisorsTable, -1, sizeof(numberOfDivisorsTable));
  memset(hiper, -1, sizeof(hiper));

  int n;
  while(cin >> n) {
    int numberOfHiper = 0;

    repWithEqual(i, 2, n) {
      
      if (hiper[i] != -1) {
        if (hiper[i] == 1) {
          numberOfHiper++;
        }
        continue;
      }

      if (isPrime(i) == 1) {
        isPrimeTable[i] = 1;
        hiper[i] = 1;
        numberOfHiper++;
        continue;
      }
      isPrimeTable[i] = 0;

      int a = (int)sqrt(i);
      if(a != sqrt(i)) {
        hiper[i] = 0;
        continue;
      }

      int nd;
      if (numberOfDivisorsTable[i] != -1) {
        nd = numberOfDivisorsTable[i];
      } else {
        nd = countDivisors(i);
        numberOfDivisorsTable[i] = nd;
      }

     
      if (isPrimeTable[nd] != -1) {
        if (isPrimeTable[nd] == 1) {
          hiper[i] = 1;
          numberOfHiper++;
        }
      } else {
        int checkPrime = isPrime(nd);
        isPrimeTable[nd] = checkPrime;
        if (checkPrime == 1) {
          hiper[i] = 1;
          numberOfHiper++;
        } else {
          hiper[i] = 0;
        }
      }
    }

    cout << numberOfHiper << endl;

  }
  return 0;
}