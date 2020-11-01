#include <bits/stdc++.h>

using namespace std;

#define INF 1000000000
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define repWithEqual(i, a, b) for(int i = int(a); i <= int(b); i++)
#define debugLine() cout << "PASSSSOUUU AQUIIII" << endl;
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";
#define debugA(x, l) { rep(i,0,l) { cout << x[i] << " "; } printf("\n"); }
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) cout << x[i][j] << " "; printf("\n");}}
#define setM( x, l, c, k ) { rep( i, 0, l ){ rep( j, 0, c ) x[i][j] = k;}}

vector<vector<vector<int>>> dp;
vector<int> toys;

int switchPresents(int n, int total, int curr, int sum, int aux) {
  if (curr == n) {
    if (2*aux == n) return abs((2*sum) - total);
    else return INF;
  }

  if (dp[curr][sum][aux] != -1) return dp[curr][sum][aux];

  dp[curr][sum][aux] = min(switchPresents(n, total, curr+1, sum + toys[curr], aux + 1), switchPresents(n, total, curr+1, sum, aux));
  return dp[curr][sum][aux];

}


int main() {

  int numberOfCases;
  cin >> numberOfCases;

  rep(i,0,numberOfCases) {
    int n;
    cin >> n;
    n = 2*n;
    
    toys.clear();

    int total = 0;

    rep(j,0,n) {
      int t;
      cin >> t;
      total = total + t;
      toys.push_back(t);
    }

    dp = vector<vector<vector<int>>>(n + 5, vector<vector<int>> (total + 5, vector<int> (n + 5, -1)));

    cout << switchPresents(n, total, 0, 0, 0) << endl;

  }

  return 0;
}