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
  int *parent, *rank;
  int n;

  Sets(int n) {
    this->n = n;
    parent = new int[n+1];
    rank = new int[n+1];

    for(int i=0; i<=n; i++) {
      rank[i] = 0;
      parent[i] = i;
    }
  }

  int find(int u) {
    if (u != parent[u]) {
      parent[u] = find(parent[u]);
    }
    return parent[u];
  }

  void merge(int x, int y) {
    x = find(x);
    y = find(y);

    if (rank[x] > rank[y]) {
      parent[y] = x;
    } else {
      parent[x] = y;
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

  return 0;
}