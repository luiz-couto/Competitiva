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

unsigned long long int zero = 0;
unsigned long long int one = 1;
unsigned long long int two = 2;
unsigned long long int five = 5;

void multiplyMatrix(unsigned long long int** mat1, unsigned long long int** mat2, unsigned long long int** res) {
  unsigned long long int i,j,k;
  for(i=0; i<N; i++) {
    for(j=0; j<N; j++) {
      res[i][j] = zero;
      for (k=0; k<N; k++) {
        if (mat1[i][k] > 1000000) {
          mat1[i][k] = mat1[i][k] % 1000000;
        }
        if (mat2[k][j] > 1000000) {
          mat2[k][j] = mat2[k][j] % 1000000;
        }
        res[i][j] += (mat1[i][k] * mat2[k][j]);
      }
    }
  }

  for(i=0; i<N; i++) {
    for(j=0; j<N; j++) {
      if (res[i][j] > 1000000) {
        res[i][j] = res[i][j] % 1000000;
      }
    }
  }

}

unsigned long long int** exponencial(unsigned long long int** m, unsigned long long int exp) {
  unsigned long long int** res;
  res = new unsigned long long int*[N];
  res[0] = new unsigned long long int[N];
  res[1] = new unsigned long long int[N];

  res[0][0] = one;
  res[0][1] = zero;
  res[1][0] = zero;
  res[1][1] = one;

  while (exp > zero) {
    if (exp % two == one) {
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

    
    exp = exp / two;

  }
  return res;
}


int main() {

  unsigned long long int n;
  while(cin >> n) {
    unsigned long long int k,l;
    cin >> k >> l;
    

    n = n/five;

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

    mat2[0][0] = zero;
    mat2[0][1] = l;
    mat2[1][0] = one;
    mat2[1][1] = k;

    unsigned long long int** result = exponencial(mat2, n);

    unsigned long long int** mat3;
    mat3 = new unsigned long long int*[N];
    mat3[0] = new unsigned long long int[N];
    mat3[1] = new unsigned long long int[N];

    multiplyMatrix(mat1, result, mat3);

    //debugM(mat3, N, N);
    
    printf("%.6d\n", mat3[0][0]%1000000);
  }

  return 0;
}