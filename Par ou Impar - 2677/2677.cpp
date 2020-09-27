#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) cout << x[i][j] << " "; printf("\n");}}
#define setM( x, l, c, k ) { rep( i, 0, l ){ rep( j, 0, c ) x[i][j] = k;}}

int dp[1101][1101];
int seq[1010];

void runAll(int n) {

  for (int i=0; i<n; ++i) {
    for (int j=0; i+j<n; ++j) {
      if (i == 0) {
        dp[j][i + j] = 0;
      }

      if (i%2 == 0) {
        dp[j][i + j] = min(dp[j+1][i+j], dp[j][(i+j)-1]);
      } else {
        dp[j][i + j] = max(dp[j+1][i+j] + int(!(seq[j]%2)), dp[j][(i+j)-1] + int(!(seq[i+j]%2)));
      }

    }
  }

  cout << dp[0][n-1] << endl;

}

int main() {

  while (1) {
    int n;
    cin >> n;
    if (n == 0) break;

    // rep(i, 0, 2*n) seq[i] = 0;
    // setM(dp, 501, 501, 0);

    for (int i=0; i<2*n; i++) {
      int num;
      cin >> num;
      if (num%2 == 0) seq[i] = 0;
      else seq[i] = 1;
    }

    runAll(2*n);

  }

  return 0;
}