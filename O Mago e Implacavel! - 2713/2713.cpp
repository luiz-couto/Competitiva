#include <bits/stdc++.h>

using namespace std;

struct Room {
  int monsterLifePoints;
  int damageIncrease;
  Room (int monsterLifePoints, int damageIncrease) {
    this->monsterLifePoints = monsterLifePoints;
    this->damageIncrease = damageIncrease;
  }
  
};

float runTheDungeon(int mana, int currentRoom, int damage, vector<Room> rooms, float** dp) {
  if (currentRoom == rooms.size()) {
    return 0;
  }

  if (dp[currentRoom][mana] != -1) {
    return dp[currentRoom][mana];
  }

  if (mana == 0) {

    dp[currentRoom][mana] = float(float(rooms[currentRoom].monsterLifePoints) / float(damage)) + runTheDungeon(mana, currentRoom + 1, damage, rooms, dp);
    return dp[currentRoom][mana];
  
  } else {
    
    dp[currentRoom][mana] = min(float(float(rooms[currentRoom].monsterLifePoints) / float(damage)) + runTheDungeon(mana, currentRoom + 1, damage, rooms, dp), 
    float(float(rooms[currentRoom].monsterLifePoints) / float(damage + rooms[currentRoom].damageIncrease)) + runTheDungeon(mana - 1, currentRoom + 1, damage, rooms, dp));
    return dp[currentRoom][mana];
  
  }


}



int main() {
  
  int n;

  while(cin >> n) {
    int k;
    int v;
    cin >> k >> v;

    vector<Room> rooms;

    for (int i=0; i<n; i++) {
      int mlp;
      int di;
      cin >> mlp >> di;
      Room r = Room(mlp, di);
      rooms.push_back(r);
    }

    float** dp;
    dp = new float*[n];

    for (int i = 0; i < n; i++) 
      dp[i] = new float[k + 1];
    
    for (int i = 0; i < n; i++) 
      for (int j = 0; j < k + 1; j++) 
        dp[i][j] = -1; 

    printf("%.4f\n", runTheDungeon(k, 0, v, rooms, dp));
  }

  return 0;
}