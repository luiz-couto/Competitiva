#include <bits/stdc++.h>

using namespace std;

struct StrategyPoint {
  vector<int> roadTo;
  int numberOfGermans;
  int shortestPathFromInitial;
  int previousStrategyPoint;

  StrategyPoint() {
    this->roadTo = {};
    this->numberOfGermans = 0;
    this->shortestPathFromInitial = INT_MAX;
    this->previousStrategyPoint = -1;
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


  

  return 0;
}