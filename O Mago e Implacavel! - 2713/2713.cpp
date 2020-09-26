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

float runTheDungeon(int mana, int currentRoom, int damage, vector<Room> rooms, float timeUntilNow) {
  if (currentRoom == rooms.size()) {
    return timeUntilNow;
  }

  if (dungeon[{currentRoom, damage}] != 0) {
    return dungeon[{currentRoom, damage}];
  }

  float timeToPassThatPhase = timeUntilNow + (rooms[currentRoom].monsterLifePoints / damage);
  float timeToPassThatPhaseUsingMana = timeUntilNow + (rooms[currentRoom].monsterLifePoints / (damage + rooms[currentRoom].damageIncrease));

  if (mana == 0) {
    
    dungeon[{currentRoom, damage}] = runTheDungeon(mana, currentRoom + 1, damage, rooms, timeToPassThatPhase);
    // cout <<  dungeon[{currentRoom, damage}] << endl;
    return dungeon[{currentRoom, damage}];
  
  } else {
    
    dungeon[{currentRoom, damage}] = min(runTheDungeon(mana, currentRoom + 1, damage, rooms, timeToPassThatPhase), 
    runTheDungeon(mana - 1, currentRoom + 1, (damage + rooms[currentRoom].damageIncrease), rooms, timeToPassThatPhaseUsingMana));
    cout <<  dungeon[{currentRoom, damage}] << endl;
    return dungeon[{currentRoom, damage}];
  
  }


}



int main() {
  
  int n;
  int k;
  int v;


  cin >> n >> k >> v;

  vector<Room> rooms;

  for (int i=0; i<n; i++) {
    int mlp;
    int di;
    cin >> mlp >> di;
    Room r = Room(mlp, di);
    rooms.push_back(r);
  }

  cout << runTheDungeon(k, 0, v, rooms, 0) << endl;


  return 0;
}