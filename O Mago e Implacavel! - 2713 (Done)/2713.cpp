#include <bits/stdc++.h>

using namespace std;

int monstersLife[1010];
int increasedDamaged[1010];
double dp[1010][101];
int aux[1010][101];

int comp;

double runTheDungeon(int mana, int currentRoom, int damage, int n) {
  
  if (currentRoom == n) {
    return 0;
  }

  if (aux[currentRoom][mana] == comp) {
    return dp[currentRoom][mana];
  }

  aux[currentRoom][mana] = comp;
  dp[currentRoom][mana] = 1e32;
  if (mana != 0) {
  
    dp[currentRoom][mana] = double(monstersLife[currentRoom]) / (damage + increasedDamaged[currentRoom]) + runTheDungeon(mana - 1, currentRoom + 1, damage, n);

    // dp[currentRoom][mana] = sumIfManaEqualsZero[n-1] - sumIfManaEqualsZero[currentRoom] + double(double(monstersLife[currentRoom]) / double(damage));
    // return dp[currentRoom][mana];
  
  }

  dp[currentRoom][mana] = min(double(monstersLife[currentRoom]) / damage + runTheDungeon(mana, currentRoom + 1, damage, n), dp[currentRoom][mana]);
  return dp[currentRoom][mana];
  
  


}


int main() {
  
  int n;

  while(cin >> n) {
    comp++;
    int k;
    int v;
    cin >> k >> v;


    for (int i=0; i<n; i++) {
      int mlp;
      int di;
      cin >> mlp >> di;
      
      monstersLife[i] = mlp;
      increasedDamaged[i] = di;

    }

   

    printf("%.4lf\n", runTheDungeon(k, 0, v, n));
  }

  return 0;
}