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

#define MILLION 1000000;

void multiplyMatrix(unsigned long long int** mat1, unsigned long long int** mat2, unsigned long long int** res) {
  unsigned long long int i,j,k;
  rep(i,0,N) {
    rep (j,0,N) {
      res[i][j] = 0;
      rep(k,0,N) {
        res[i][j] = res[i][j] + (mat1[i][k] * mat2[k][j]);
      }
    }
  }

}

unsigned long long int** exponencial(unsigned long long int** m, unsigned long long int exp) {
  unsigned long long int** res;
  res = new unsigned long long int*[N];
  res[0] = new unsigned long long int[N];
  res[1] = new unsigned long long int[N];

  res[0][0] = 1;
  res[0][1] = 0;
  res[1][0] = 0;
  res[1][1] = 1;

  while (exp > 0) {
    if (exp % 2 == 1) {
      unsigned long long int** ans;
      ans = new unsigned long long int*[N];
      ans[0] = new unsigned long long int[N];
      ans[1] = new unsigned long long int[N];
      multiplyMatrix(res, m, ans);
      res = ans;
    }

    unsigned long long int** ans2;
    ans2 = new unsigned long long int*[N];
    ans2[0] = new unsigned long long int[N];
    ans2[1] = new unsigned long long int[N];

    multiplyMatrix(m,m,ans2);
    m = ans2;

    exp = exp / 2;

  }
  return res;
}


int main() {

  unsigned long long int n,k,l;
  cin >> n >> k >> l;

  n = n/5;

  unsigned long long int** mat1;
  mat1 = new unsigned long long int*[N];
  mat1[0] = new unsigned long long int[N];
  mat1[1] = new unsigned long long int[N];

  mat1[0][0] = 1;
  mat1[0][1] = k;

  unsigned long long int** mat2;
  mat2 = new unsigned long long int*[N];
  mat2[0] = new unsigned long long int[N];
  mat2[1] = new unsigned long long int[N];

  mat2[0][0] = 0;
  mat2[0][1] = l;
  mat2[1][0] = 1;
  mat2[1][1] = k;

  unsigned long long int** result = exponencial(mat2, n);

  unsigned long long int** mat3;
  mat3 = new unsigned long long int*[N];
  mat3[0] = new unsigned long long int[N];
  mat3[1] = new unsigned long long int[N];

  multiplyMatrix(mat1, result, mat3);

  debugM(mat3, N, N);

  return 0;
}