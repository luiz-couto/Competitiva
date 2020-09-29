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



int cinema[1010][1010];

int main() {

  while(1) {

    int r,c,k;
    cin >> r >> c >> k;

    if (r == 0) break;

    rep(i,0,r) {
      rep(j,0,c) {
        char seat;
        cin >> seat;
        if (seat == 'X') {
          cinema[i][j] = 0;
        } else {
          cinema[i][j] = 1;
        }
      }
    }

    int area = INT_MAX;
    int aux[1010];
    int dots, aux2;
    rep(i,0,r) {
      
      rep(j, 0, c) {
        aux[j] = 0;
      }

      rep(j,i,r) {

        rep(l,0,c) {
          aux[l] = aux[l] + cinema[j][l];
        }

        dots = aux2 = 0;

        rep (m,0,c) {
          dots = dots + aux[m];

          while((aux2 < m) && (dots >= k + aux[aux2])) {
            dots = dots - aux[aux2];
            aux2++;
          }

          if (dots >= k) {
            area = min(area, (abs(aux2-m) + 1) * (abs(i-j) + 1));
          }

        }

      }

    }

    cout << area << endl;
  }

  return 0;
}