#include <bits/stdc++.h>

using namespace std;

map<pair<int, int>, float> dungeon;

struct Room {
  int monsterLifePoints;
  int damageIncrease;
  Room (int monsterLifePoints, int damageIncrease) {
    this->monsterLifePoints = monsterLifePoints;
    this->damageIncrease = damageIncrease;
  }
  
};

float runTheDungeon(int mana, int currentRoom, int damage, vector<Room> rooms) {
  if (currentRoom == rooms.size()) {
    return 0;
  }

  if (dungeon[{currentRoom, mana}] != 0) {
    return dungeon[{currentRoom, mana}];
  }

  if (mana == 0) {

    dungeon[{currentRoom, mana}] = float(float(rooms[currentRoom].monsterLifePoints) / float(damage)) + runTheDungeon(mana, currentRoom + 1, damage, rooms);
    return dungeon[{currentRoom, mana}];
  
  } else {
    
    dungeon[{currentRoom, mana}] = min(float(float(rooms[currentRoom].monsterLifePoints) / float(damage)) + runTheDungeon(mana, currentRoom + 1, damage, rooms), 
    float(float(rooms[currentRoom].monsterLifePoints) / float(damage + rooms[currentRoom].damageIncrease)) + runTheDungeon(mana - 1, currentRoom + 1, damage, rooms));
    return dungeon[{currentRoom, mana}];
  
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

    printf("%.4f\n", runTheDungeon(k, 0, v, rooms));
    // for (auto i : dungeon) {
    //   if (i.first.first == n-1)
    //     cout << i.second << endl;
    // }
    dungeon.clear();
  }

  return 0;
}