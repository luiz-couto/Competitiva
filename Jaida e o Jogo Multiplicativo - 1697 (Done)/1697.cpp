#include <bits/stdc++.h>

using namespace std;

#define INF 17000000
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define repWithEqual(i, a, b) for(int i = int(a); i <= int(b); i++)
#define debugLine() cout << "PASSSSOUUU AQUIIII" << endl;
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";
#define debugA(x, l) { rep(i,0,l) { cout << x[i] << " "; } printf("\n"); }
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) cout << x[i][j] << " "; printf("\n");}}
#define setM( x, l, c, k ) { rep( i, 0, l ){ rep( j, 0, c ) x[i][j] = k;}}

#define NMAX 1000010
#define UTIL 16000000

int aux[NMAX];
int primeCounter;
unordered_map<int,int>numbersTable;

bitset<INF> isPrime;

void preCalc() {
  isPrime.set();
  
  aux[0] = 1;
  aux[1] = 2;
  primeCounter = 2;

  for (long long int i = 4; i<UTIL; i += 2) {
    isPrime.reset(i);
  }

  for (long long int i = 3; primeCounter < NMAX && i <= UTIL; i += 2) {
    if (isPrime[i]) {
      aux[primeCounter++] = i;
      for (long long int j = i*i; j<= UTIL; j+=i) {
        isPrime.reset(j);
      }
    }
  }

}

int main() {

  //debug(primeCounter);

  int numberOfInputs;
  cin >> numberOfInputs;

  primeCounter = 0;

  preCalc();

  rep(i,0,numberOfInputs) {
    
    int n;
    cin >> n;

    numbersTable.clear();

    rep (j,0,n) {
      int num;
      cin >> num;
      numbersTable[num] = 1;
    }

    rep(j, 0, primeCounter) {
      if (!numbersTable[aux[j]]) {
        cout << (aux[j] - 1) << endl;
        break;
      }
    }

  }

  return 0;
}