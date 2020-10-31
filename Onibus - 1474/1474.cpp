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

#define N 2

void multiplyMatrix(int mat1[][N], int mat2[][N], int res[][N]) {
  int i,j,k;
  rep(i,0,N) {
    rep (j,0,N) {
      res[i][j] = 0;
      rep(k,0,N) {
        res[i][j] = res[i][j] + (mat1[i][k] * mat2[k][j]);
      }
    }
  }
}


int main() {

  int res[N][N];

  int mat1[N][N] = {
    { 1 , 2 }
  };

  int mat2[N][N] = {
    { 3, 4 },
    { 5, 6 }
  };

  multiplyMatrix(mat1, mat2, res);

  debugM(res, N, N);

  return 0;
}