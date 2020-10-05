#include <bits/stdc++.h>

using namespace std;

#define INF 1000000000
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define debugLine() cout << "PASSSSOUUU AQUIIII" << endl;
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";
#define debugA(x, l) { rep(i,0,l) { cout << x[i] << " "; } printf("\n"); }
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) cout << x[i][j] << " "; printf("\n");}}
#define setM( x, l, c, k ) { rep( i, 0, l ){ rep( j, 0, c ) x[i][j] = k;}}

int roulette[256];
int balls[256];
int dp[256][256];

int playTheTurkishRoulette(int s, int b) {
  int aux;
  int resp = -INF;

  rep(i,0,s) {
    dp[0][i] = balls[0]*(roulette[i] + roulette[(i+1)%s]);
    rep(j,1,s) {
      aux = (i+j)%s;
      dp[0][aux] = max(balls[0]*(roulette[aux] + roulette[(aux+1)%s]), dp[0][(aux+s-1)%s]);
    }

    rep(k,1,b) {
      rep(l,0,s) dp[k][l] = -INF;
      rep(l, k*2, s-1) {
        aux = (i+l)%s;
        dp[k][aux] = max(balls[k]*(roulette[aux] + roulette[(aux+1)%s]) + dp[k-1][(aux+s-2)%s], dp[k][(aux+s-1)%s]);
      }
    }

    resp = max(resp, dp[b-1][(i+s-2)%s]);
  }

  return resp;

}

int main() {

  while(1) {
    int s,b;
    cin >> s >> b;

    if (s == 0) break;

    int positionMap[256];
    int last;
    int first;
    rep(i,0,s) {
      cin >> roulette[i];
    }
    // debugA(roulette, s);
    rep(i,0,b) {
      cin >> balls[i];
      balls[i] = -balls[i];
    }

    // memset(dp, -1, sizeof dp);

    cout << (playTheTurkishRoulette(s, b)) << endl;
  }

  return 0;
}