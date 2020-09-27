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

float runTheDungeon(int mana, int currentRoom, int damage, vector<Room> rooms, float** dp, vector<float> sumIfManaEqualsZero) {
  
  if (currentRoom == rooms.size()) {
    return 0;
  }

  if (dp[currentRoom][mana] != -1) {
    return dp[currentRoom][mana];
  }

  if (mana == 0) {
  
    // dp[currentRoom][mana] = float(float(rooms[currentRoom].monsterLifePoints) / float(damage)) + runTheDungeon(mana, currentRoom + 1, damage, rooms, dp, sumIfManaEqualsZero);
    // return dp[currentRoom][mana];

    dp[currentRoom][mana] = sumIfManaEqualsZero[rooms.size()-1] - sumIfManaEqualsZero[currentRoom] + float(float(rooms[currentRoom].monsterLifePoints) / float(damage));
    return dp[currentRoom][mana];
  
  } else if (mana >= rooms.size() - currentRoom) {
    
    // Not sure if that works
    dp[currentRoom][mana] = float(float(rooms[currentRoom].monsterLifePoints) / float(damage + rooms[currentRoom].damageIncrease)) + runTheDungeon(mana - 1, currentRoom + 1, damage, rooms, dp, sumIfManaEqualsZero);
    return dp[currentRoom][mana];

  } else {

    dp[currentRoom][mana] = min(float(float(rooms[currentRoom].monsterLifePoints) / float(damage)) + runTheDungeon(mana, currentRoom + 1, damage, rooms, dp, sumIfManaEqualsZero), 
    float(float(rooms[currentRoom].monsterLifePoints) / float(damage + rooms[currentRoom].damageIncrease)) + runTheDungeon(mana - 1, currentRoom + 1, damage, rooms, dp, sumIfManaEqualsZero));
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
    vector<float> sumIfManaEqualsZero;

    for (int i=0; i<n; i++) {
      int mlp;
      int di;
      cin >> mlp >> di;
      Room r = Room(mlp, di);
      rooms.push_back(r);

      float ratio = float(mlp)/float(v);
      float before;
      if (i == 0) {
        before = 0;
      } else {
        before = sumIfManaEqualsZero[i-1];
      }
      sumIfManaEqualsZero.push_back(ratio+before);

    }

    float** dp;
    dp = new float*[n];

    for (int i = 0; i < n; i++) 
      dp[i] = new float[k + 1];
    
    for (int i = 0; i < n; i++) 
      for (int j = 0; j < k + 1; j++) 
        dp[i][j] = -1; 

    printf("%.4f\n", runTheDungeon(k, 0, v, rooms, dp, sumIfManaEqualsZero));
  }

  return 0;
}