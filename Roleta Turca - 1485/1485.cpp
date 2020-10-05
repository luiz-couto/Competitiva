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

int playTheTurkishRoulette(int currentBall, int position, int s, int b, int positionMap[], int firstBallPos) {
  // debug(currentBall);
  // Garantir que a primeira bola seja colocada em alguma posição


  if (position != 0 && dp[currentBall][firstBallPos] != -1 ) {
    return dp[currentBall][firstBallPos];
  }

  if (currentBall == 0 && position == s-1) {
    positionMap[position] = true;
    dp[currentBall][firstBallPos] = (roulette[position]*balls[currentBall]) + playTheTurkishRoulette(currentBall + 1, 0, s, b, positionMap, position);
    return dp[currentBall][firstBallPos];
  }
  
  // Caso tenha uma bola nessa posição, não precisa nem continuar
  if (positionMap[position]) {
    dp[currentBall][firstBallPos] = INF;
    return  dp[currentBall][firstBallPos];
  }

  // Avaliando posições não extremas
  if (position != 0 && position != s-1 && (positionMap[position-1] || positionMap[position+1])) {
    dp[currentBall][firstBallPos] = playTheTurkishRoulette(currentBall, position + 1, s, b, positionMap, firstBallPos);
    return dp[currentBall][firstBallPos];
  }

  // Avaliando primeira posição
  if (position == 0 && (positionMap[position+1] || positionMap[s-1])) {
    dp[currentBall][firstBallPos] = playTheTurkishRoulette(currentBall, position + 1, s, b, positionMap, firstBallPos);
    return dp[currentBall][firstBallPos];
  }

  // Avaliando última posição
  if (position == s-1 && (positionMap[position-1] || positionMap[0])) {
    dp[currentBall][firstBallPos] = playTheTurkishRoulette(currentBall, 0, s, b, positionMap, firstBallPos);
    return dp[currentBall][firstBallPos];
  }

  int nextPosition = position+1;
  if (position == s-1) nextPosition = 0;

  int res1, res2;
  
  positionMap[position] = true;

  if (currentBall == b-1) {
    res2 = (roulette[position]*balls[currentBall]);  
  } else {
    if (currentBall == 0) {
      res2 = (roulette[position]*balls[currentBall]) + playTheTurkishRoulette(currentBall + 1, nextPosition, s, b, positionMap, position);
    } else {
      res2 = (roulette[position]*balls[currentBall]) + playTheTurkishRoulette(currentBall + 1, nextPosition, s, b, positionMap, firstBallPos);
    }
  }

  positionMap[position] = false;

  res1 = playTheTurkishRoulette(currentBall, nextPosition, s, b, positionMap, firstBallPos);

  dp[currentBall][firstBallPos] = min(res1, res2);
  return dp[currentBall][firstBallPos];

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
      if (i == 0) {
        int a,b;
        cin >> a >> b;
        roulette[i] = a + b;
        first = a;
        last = b;
      } else if (i == s-1) {
        roulette[i] = last + first;
      } else {
        int c;
        cin >> c;
        roulette[i] = last + c;
        last = c;
      }
      positionMap[i] = false;
    }
    // debugA(roulette, s);
    rep(i,0,b) {
      cin >> balls[i];
    }

    memset(dp, -1, sizeof dp);

    cout << 0 - (playTheTurkishRoulette(0, 0, s, b, positionMap, 0)) << endl;
  }

  return 0;
}