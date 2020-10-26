#include <bits/stdc++.h>

using namespace std;

#define INF 1000000000
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define debugLine() cout << "PASSSSOUUU AQUIIII" << endl;
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";
#define debugA(x, l) { rep(i,0,l) { cout << x[i] << " "; } printf("\n"); }
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) cout << x[i][j] << " "; printf("\n");}}
#define setM( x, l, c, k ) { rep( i, 0, l ){ rep( j, 0, c ) x[i][j] = k;}}

bool isPrime(int n) {
  if (n <= 1) return false;
  else if (n <= 3) return true;

  if (n % 2 == 0 || n % 3 == 0) return false;

  for (int i = 5; i * i <= n; i = i + 6) {
    if (n % i == 0 || n % (i+2) == 0) return false;
  }

  return true;
}

int main() {
  string s;

  while(cin >> s) {
    stringstream strObj(s);
    int n = 0;
    strObj >> n;

    bool mainIsPrime = isPrime(n);

    if (!mainIsPrime) {
      cout << "Nada" << endl;
      continue;
    }

    bool foundNotPrime = false;
    
    for (int i = 0; i<s.length(); i++) {
      
      int num = s[i] - '0';
      
      if (!isPrime(num)) {
        cout << "Primo" << endl;
        foundNotPrime = true;
        break;
      }
    
    }

    if (!foundNotPrime) {
      cout << "Super" << endl;
    }

  }

  return 0;
}