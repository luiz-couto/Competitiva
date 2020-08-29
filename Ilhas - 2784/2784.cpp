#include <bits/stdc++.h>

using namespace std;

struct Island {
  vector<pair<int, int>> cableTo;
  int shortestPathFromInitial;
  int previousIsland;
  int visited;

  Island() {
    this->cableTo = {};
    this->shortestPathFromInitial = INT_MAX;
    this->previousIsland = -1;
    this->visited = false;
  }

};


int main() {
  
  int n,m;
  cin >> n >> m;

  vector<Island> worldMap;

  for (int i=0; i<n+1; i++) {
    Island is = Island();
    worldMap.push_back(is);
  }

  for(int i=0; i<m; i++) {
    int from,to,ping;
    cin >> from >> to >> ping;
    worldMap[from].cableTo.push_back(make_pair(to, ping));
    worldMap[to].cableTo.push_back(make_pair(from, ping));
  }

  int initialPos;
  cin >> initialPos;

  
  return 0;
}