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

  worldMap[initialPos].shortestPathFromInitial = 0;
  int currentIsland = initialPos;

  for (int i=0; i<n; i++) {
    vector<pair<int, int>> cableTo = worldMap[currentIsland].cableTo;
    for (int j=0; j<cableTo.size(); j++) {
      if (!worldMap[cableTo[j].first].visited) {
        
        int pathSize = worldMap[currentIsland].shortestPathFromInitial + cableTo[j].second;
        if (pathSize < worldMap[cableTo[j].first].shortestPathFromInitial) {
          worldMap[cableTo[j].first].shortestPathFromInitial = pathSize;
        }

        worldMap[cableTo[j].first].previousIsland = currentIsland;

      }
    }

    worldMap[currentIsland].visited = true;


    int smallestPathToInitial = INT_MAX;
    int nextIsland = -1;

    for (int k=1; k<=n; k++) {
      if (worldMap[k].visited == false && worldMap[k].shortestPathFromInitial <= smallestPathToInitial) {
        smallestPathToInitial = worldMap[k].shortestPathFromInitial;
        nextIsland = k;
      }
    }

    if (nextIsland == -1) {
      break;
    }

    currentIsland = nextIsland;

  }

  for (int i=1; i<=n; i++) {
    cout << worldMap[i].shortestPathFromInitial << endl;
  }

  
  return 0;
}