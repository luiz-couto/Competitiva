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

int main() {
  int n;

  while(cin >> n) {
    
    if (n == 1) {
      cout << "1/1" << endl;
      continue;
    }

    if (n == 2) {
      cout << "3/4" << endl;
      continue;
    }

    long long int first = 2;
    long long int second = 3;
    long long int actual;

    for (int i=3; i<=40; i++) {
      actual = first + second;

      if (i == n) {
        break;
      }

      first = second;
      second = actual;
    }

    long long int den = (pow(2,n));

    long long int d = __gcd(actual, den);
    actual = actual / d;
    den = den / d;

    cout << actual << "/" << den << endl;
  
  
  }

  return 0;

}