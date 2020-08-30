#include <bits/stdc++.h>

using namespace std;

struct Edge {
  int from;
  int to;
  int cost;
  Edge(int from, int to, int cost) {
    this->from = from;
    this->to = to;
    this->cost = cost;
  }
};

struct Sets {
  int *connected, *rank;
  int n;

  Sets(int n) {
    this->n = n;
    connected = new int[n+1];
    rank = new int[n+1];

    for(int i=0; i<=n; i++) {
      rank[i] = 0;
      connected[i] = i;
    }
  }

  int find(int u) {
    if (u != connected[u]) {
      connected[u] = find(connected[u]);
    }
    return connected[u];
  }

  void merge(int x, int y) {
    x = find(x);
    y = find(y);

    if (rank[x] > rank[y]) {
      connected[y] = x;
    } else {
      connected[x] = y;
    }

    if (rank[x] == rank[y]) {
      rank[y] = rank[y] + 1;
    }
  }

};

bool customSort(Edge a, Edge b) {
  return a.cost < b.cost;
}

int main() {

  vector<Edge> projectMap;

  int n;
  cin >> n;

  int numberOfVertices = 0;

  for (int i=0; i<n; i++) {
    int from,to,cost;
    cin >> from >> to >> cost;

    if (from > numberOfVertices) {
      numberOfVertices = from;
    }

    if (to > numberOfVertices) {
      numberOfVertices = to;
    }

    Edge ed = Edge(from, to, cost);
    projectMap.push_back(ed);
  }

  sort(projectMap.begin(), projectMap.end(), customSort);
  Sets projectSets(numberOfVertices);

  int resultMin = 0;
  for (int i=0; i<projectMap.size(); i++) {
    int firstSet = projectSets.find(projectMap[i].from);
    int secondSet = projectSets.find(projectMap[i].to);

    if (firstSet != secondSet) {
      resultMin = resultMin + projectMap[i].cost;
      projectSets.merge(firstSet, secondSet);
    }
  }

  
  for (int i=0; i<projectMap.size(); i++) {
    projectMap[i].cost = 0 - projectMap[i].cost;
  }

  sort(projectMap.begin(), projectMap.end(), customSort);
  Sets secondProjectSets(numberOfVertices);

  int resultMax = 0;
  for (int i=0; i<projectMap.size(); i++) {
    int firstSet = secondProjectSets.find(projectMap[i].from);
    int secondSet = secondProjectSets.find(projectMap[i].to);

    if (firstSet != secondSet) {
      resultMax = resultMax + projectMap[i].cost;
      secondProjectSets.merge(firstSet, secondSet);
    }
  }

  resultMax = -(resultMax);

  cout << resultMax << endl;
  cout << resultMin << endl;

  return 0;
}