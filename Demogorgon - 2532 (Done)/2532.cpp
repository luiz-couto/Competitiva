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


int dp[1010][2020];
int spell[1010];
int mana[1010];

int killTheMonster(int currentSpell, int val, int n, int p) {
  if (currentSpell == n) {
    if (val >= p) return 0;
    else return INF;
  }

  if (dp[currentSpell][val] != -1) return dp[currentSpell][val];

  int pos1 = killTheMonster(currentSpell+1, val, n, p);
  int pos2 = killTheMonster(currentSpell+1, val + spell[currentSpell], n, p) + mana[currentSpell];

  int ans = min(pos1, pos2);
  dp[currentSpell][val] = ans;
  return dp[currentSpell][val];


}

int main() {
  int n;

  while(cin >> n) {
    int p;
    cin >> p;

    rep(i,0,n) {
      cin >> spell[i];
      cin >> mana[i];
    }

    memset(dp, -1, sizeof dp);
    int ans = killTheMonster(0,0,n,p);
    
    if (ans != INF) cout << ans << endl;
    else cout << -1 << endl;
  }

  return 0;
}