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

void multiplyMatrix(int** mat1, int** mat2, int** res) {
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

int** exponencial(int** m, long long int exp) {
  if (exp == 0) {
    int** res;
    res = new int*[N];

    res[0] = new int[N];
    res[1] = new int[N];

    res[0][0] = 1;
    res[0][1] = 0;
    res[1][0] = 0;
    res[1][1] = 1;
    return res;
  } else {

    int** res = exponencial(m, exp/2);
    
    int** ans;
    
    ans = new int*[N];
    ans[0] = new int[N];
    ans[1] = new int[N];

    multiplyMatrix(res, res, ans);

    if (exp%2 == 1) {
      multiplyMatrix(res, m, ans);
    }

    return ans;

  }

}


int main() {

  int** res;

  res = new int*[N];
  res[0] = new int[N];
  res[1] = new int[N];

  int** mat1;

  mat1 = new int*[N];
  mat1[0] = new int[N];
  mat1[1] = new int[N];

  int** mat2;

  mat2 = new int*[N];
  mat2[0] = new int[N];
  mat2[1] = new int[N];


  mat1[0][0] = 8;
  mat1[0][1] = -7;
  mat1[1][0] = 1;
  mat1[1][1] = 0;

  mat2[0][0] = 8;
  mat2[0][1] = -7;
  mat2[1][0] = 1;
  mat2[1][1] = 0;

  int** teste = exponencial(mat1, 10);

  debugM(teste, N, N);

  return 0;
}