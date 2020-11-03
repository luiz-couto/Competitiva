#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define repWithEqual(i, a, b) for(int i = int(a); i <= int(b); i++)
#define debugLine() cout << "PASSSSOUUU AQUIIII" << endl;
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";
#define debugA(x, l) { rep(i,0,l) { cout << x[i] << " "; } printf("\n"); }
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) cout << x[i][j] << " "; printf("\n");}}
#define setM( x, l, c, k ) { rep( i, 0, l ){ rep( j, 0, c ) x[i][j] = k;}}


const int NMAX = 200010;

int res[NMAX];
int sum[NMAX];

int main() {

  int nc = 0;
  int n;

  while(1) {
    cin >> n;
    if (n == 0) {
      break;
    }

    if (nc != 0) cout << "\n";

    nc++;
    cout << "Case " << nc << ":" << "\n";

    int total = 0;
    rep(i,0,n) {
      int ohm;
      cin >> ohm;

      total = total + ohm;

      res[i] = ohm;
      sum[i] = total;
    }

    char ch;

    while(1) {
      
      cin >> ch;

      if (ch == 'E') {
        cin >> ch;
        cin >> ch;
        break;
      }

      if (ch == 'M') {
        int r1,r2;
        cin >> r1 >> r2;

        r1--;
        r2--;

        if (r1 == 0) {
          cout << sum[r2] << "\n";
          continue;
        }

        if (r1 == r2) {
          cout << sum[r1] << "\n";
          continue;
        }

        cout << sum[r2] - sum[r1 - 1] << "\n";
      
      }

      if (ch == 'S') {
        int r;
        int value;

        cin >> r >> value;
        r--;

        rep(j,r,n) {
          sum[j] = sum[j] - res[r] + value;
        }

        res[r] = value;
      }
    }
  }
  return 0;
}