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

void runTheDungeon(int mana, int currentRoom, int damage, vector<Room> rooms, float timeUntilNow) {
  if (currentRoom != rooms.size()-1) {

    float aux = dungeon[{currentRoom, damage}];


    if (aux != 0) {

      if (timeUntilNow < dungeon[{currentRoom, damage}]) {
        dungeon[{currentRoom, damage}] = timeUntilNow;
      }

    } else {
      dungeon[{currentRoom, damage}] = timeUntilNow;
      float timeToPassThatPhase = timeUntilNow + (float(rooms[currentRoom].monsterLifePoints) / float(damage));
      float timeToPassThatPhaseUsingMana = timeUntilNow + (float(rooms[currentRoom].monsterLifePoints) / float(damage + rooms[currentRoom].damageIncrease));
      if (mana == 0) {
        runTheDungeon(mana, currentRoom + 1, damage, rooms, timeToPassThatPhase);
      } else {
        runTheDungeon(mana, currentRoom + 1, damage, rooms, timeToPassThatPhase);
        runTheDungeon(mana - 1, currentRoom + 1, (damage + rooms[currentRoom].damageIncrease), rooms, timeToPassThatPhaseUsingMana);
      }
    }
  } else if (currentRoom == rooms.size() - 1) {
    if (mana == 0){
      dungeon[{currentRoom, damage}] = timeUntilNow + (float(rooms[currentRoom].monsterLifePoints) / float(damage));
    } else {
      dungeon[{currentRoom, damage}] = timeUntilNow + (float(rooms[currentRoom].monsterLifePoints) / float(damage + rooms[currentRoom].damageIncrease));
    }

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

  runTheDungeon(k, 0, v, rooms, 0);
  for (auto i : dungeon) {
    if (i.first.first == n-1)
      cout << i.second << endl;
  }

  return 0;
}