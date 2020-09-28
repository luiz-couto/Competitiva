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


int dp[10010][100];
int pres[10010];

int merrKrimasSon(int current, int left, int right, int n) {
  if (current == n) {
    return 1;
  }

  if (dp[current][left - right] != -1) {
    return dp[current][left - right];
  }

  int ans = 0;
  if ((left + pres[current]) - right <= 5) {
    ans = merrKrimasSon(current + 1, left + pres[current], right, n);
  }

  int ans2 = 0;
  if ((right + pres[current]) - left <= 5) {
    ans2 = merrKrimasSon(current + 1, left, right + pres[current], n); 
  }

  dp[current][left - right] = max(ans, ans2);
  return dp[current][left - right];

}



int main() {

  int n;
  cin >> n;

  rep(i, 0, n) {
    cin >> pres[i];
  }

  memset(dp, -1, sizeof dp);

  cout << merrKrimasSon(0,0,0,n) << endl;

  return 0;
}