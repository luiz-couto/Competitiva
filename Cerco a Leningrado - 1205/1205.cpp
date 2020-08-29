#include <bits/stdc++.h>

using namespace std;




int main() {

  int n,m,k;
  float p;

  cin >> n >> m >> k >> p;

  vector<int> initialVec;
  vector<pair<int, vector<int>>> soldiersMap(n+1, make_pair(0, initialVec));

  for (int i=1; i<=m; i++) {
    int from, to;
    cin >> from >> to;
    soldiersMap[from].second.push_back(to);
    soldiersMap[to].second.push_back(from);
  }

  int a;
  cin >> a;

  for (int i=0; i<a; i++) {
    int soldierPos;
    cin >> soldierPos;
    soldiersMap[soldierPos].first = soldiersMap[soldierPos].first + 1;
  }

  int initialPos, finalPos;
  cin >> initialPos >> finalPos;


  return 0;
}