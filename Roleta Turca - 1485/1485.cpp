#include <bits/stdc++.h>

using namespace std;

#define INF 1000000000
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";
#define debugA(x, l) { rep(i,0,l) { cout << x[i] << " "; } printf("\n"); }
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) cout << x[i][j] << " "; printf("\n");}}
#define setM( x, l, c, k ) { rep( i, 0, l ){ rep( j, 0, c ) x[i][j] = k;}}

int roulette[256];

int main() {
  int s,b;
  cin >> s >> b;

  int last;
  int first;
  rep(i,0,s) {
    if (i == 0) {
      int a,b;
      cin >> a >> b;
      roulette[i] = a + b;
      first = a;
      last = b;
    } else if (i == s-1) {
      roulette[i] = last + first;
    } else {
      int c;
      cin >> c;
      roulette[i] = last + c;
      last = c;
    }
  }

  debugA(roulette, s);

  return 0;
}