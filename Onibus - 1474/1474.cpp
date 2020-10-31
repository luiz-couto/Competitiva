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

#define unsigned long long int ll;

void multiplyMatrix(long long int** mat1, long long int** mat2, long long int** res) {
  long long int i,j,k;
  rep(i,0,N) {
    rep (j,0,N) {
      res[i][j] = 0;
      rep(k,0,N) {
        res[i][j] = res[i][j] + (mat1[i][k] * mat2[k][j]);
      }
    }
  }
}

long long int** exponencial(long long int** m, long long int exp) {
  long long int** res;
  res = new long long int*[N];
  res[0] = new long long int[N];
  res[1] = new long long int[N];

  res[0][0] = 1;
  res[0][1] = 0;
  res[1][0] = 0;
  res[1][1] = 1;

  while (exp > 0) {
    if (exp % 2 == 1) {
      long long int** ans;
      ans = new long long int*[N];
      ans[0] = new long long int[N];
      ans[1] = new long long int[N];
      multiplyMatrix(res, m, ans);
      res = ans;
    }

    long long int** ans2;
    ans2 = new long long int*[N];
    ans2[0] = new long long int[N];
    ans2[1] = new long long int[N];

    multiplyMatrix(m,m,ans2);
    m = ans2;

    exp = exp / 2;

  }
  return res;
}


int main() {

  long long int** res;

  res = new long long int*[N];
  res[0] = new long long int[N];
  res[1] = new long long int[N];

  long long int** mat1;

  mat1 = new long long int*[N];
  mat1[0] = new long long int[N];
  mat1[1] = new long long int[N];

  long long int** mat2;

  mat2 = new long long int*[N];
  mat2[0] = new long long int[N];
  mat2[1] = new long long int[N];


  mat1[0][0] = 8;
  mat1[0][1] = -7;
  mat1[1][0] = 1;
  mat1[1][1] = 0;

  mat2[0][0] = 8;
  mat2[0][1] = -7;
  mat2[1][0] = 1;
  mat2[1][1] = 0;

  long long int** teste = exponencial(mat1, 15);

  debugM(teste, N, N);

  return 0;
}