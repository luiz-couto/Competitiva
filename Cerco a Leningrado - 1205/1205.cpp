#include <bits/stdc++.h>

using namespace std;

struct StrategyPoint {
  vector<int> roadTo;
  int numberOfGermans;
  int shortestPathFromInitial;
  int previousStrategyPoint;
  int visited;

  StrategyPoint() {
    this->roadTo = {};
    this->numberOfGermans = 0;
    this->shortestPathFromInitial = INT_MAX;
    this->previousStrategyPoint = -1;
    this->visited = false;
  }

};

int main() {

  int n,m,k;
  float p;

  cin >> n >> m >> k >> p;

  vector<StrategyPoint> cityMap;
  
  for (int i=0; i<n+1; i++) {
    StrategyPoint sp = StrategyPoint();
    cityMap.push_back(sp);
  }

  for (int i=1; i<=m; i++) {
    int from, to;
    cin >> from >> to;

    cityMap[from].roadTo.push_back(to);
    cityMap[to].roadTo.push_back(from);
  }

  int a;
  cin >> a;

  for (int i=0; i<a; i++) {
    int soldierPos;
    cin >> soldierPos;
    cityMap[soldierPos].numberOfGermans = cityMap[soldierPos].numberOfGermans + 1;
  }

  int initialPos, finalPos;
  cin >> initialPos >> finalPos;

  cityMap[initialPos].shortestPathFromInitial = 0;

  int currentStrategyPoint = initialPos;

  for (int i=0; i<n; i++) {
    vector<int> roadTo = cityMap[currentStrategyPoint].roadTo;
    for (int j=0; j<roadTo.size(); j++) {
      if (!cityMap[roadTo[j]].visited) {
        
        int pathSize = cityMap[currentStrategyPoint].shortestPathFromInitial + cityMap[roadTo[j]].numberOfGermans;

        if (pathSize < cityMap[roadTo[j]].shortestPathFromInitial) {
          cityMap[roadTo[j]].shortestPathFromInitial = pathSize;
        }

        cityMap[roadTo[j]].previousStrategyPoint = currentStrategyPoint;

      }
    }

    cityMap[currentStrategyPoint].visited = true;

    int smallestPathToInitial = INT_MAX;
    int nextStrategyPoint = -1;

    for (int k=1; k<=n; k++) {
      if ( cityMap[k].visited == false && cityMap[k].shortestPathFromInitial <= smallestPathToInitial) {
        smallestPathToInitial = cityMap[k].shortestPathFromInitial;
        nextStrategyPoint = k;
      }
    }

    if (nextStrategyPoint == -1) {
      break;
    }

    currentStrategyPoint = nextStrategyPoint;

  }

  cout << (cityMap[finalPos].shortestPathFromInitial + cityMap[initialPos].numberOfGermans) << endl;
  

  return 0;
}