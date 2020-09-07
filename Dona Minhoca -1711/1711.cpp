#include <bits/stdc++.h>

using namespace std;

struct Tunnel {
  int from;
  int to;
  int length;
  Tunnel(int from, int to, int length) {
    this->from = from;
    this->to = to;
    this->length = length;
  };
  Tunnel() {
    this->from = -1;
    this->to = -1;
    this->length = -1;
  }
};

struct Saloon {
  
  vector<Tunnel> connectedTo;
  
  // For DFS
  Tunnel parent;
  int status;
  int cycleNumber;

  // For Dijkstra
  int shortestPathFromInitial;
  int previousSaloon;
  int visited;

  Saloon() {
    this->connectedTo = {};
    this->shortestPathFromInitial = INT_MAX;
    this->previousSaloon = -1;
    this->visited = false;
    this->cycleNumber = -1;
  }

};

struct Cycle {
  set<int> saloons;
  int totalLength;
  Cycle() {
    this->saloons = {};
    this->totalLength = 0;
  }
};

vector<Saloon> cave;
vector<Cycle> cycles;

void findAllCycles(int currentSaloon, Tunnel parentOfCurrent, int& cycleNumber) {
  
  if (cave[currentSaloon].status == 2) {
    return;
  }

  if (cave[currentSaloon].status == 1) {
    
    Cycle newCycle = Cycle();
    cycleNumber++;
    Tunnel cur = parentOfCurrent;

    newCycle.saloons.insert(cur.from);
    newCycle.totalLength = newCycle.totalLength + cur.length;

    cave[cur.from].cycleNumber = cycleNumber;

    while(cur.from != currentSaloon) {
      
      cur = cave[cur.from].parent;
      cave[cur.from].cycleNumber = cycleNumber;

      newCycle.saloons.insert(cur.from);
      newCycle.totalLength = newCycle.totalLength + cur.length;

    }

    cycles.push_back(newCycle);
    return;

  }

  cave[currentSaloon].parent = parentOfCurrent;
  cave[currentSaloon].status = 1;

  for(Tunnel i : cave[currentSaloon].connectedTo) {
    if (i.to == cave[currentSaloon].parent.from) {
      continue;
    }
    findAllCycles(i.to, i, cycleNumber);
  }

  cave[currentSaloon].status = 2;

}

bool verifyIfIsInCycle (int saloon, Cycle cycle) {
  for (int s : cycle.saloons) {
    if (saloon == s) {
      return true;
    }
  }
  return false;
}


int main() {
  
  int s;

  while (cin >> s) {

  int t;
  cin >> t;

  cave = {};
  cycles = {};

  Saloon zero;
  cave.push_back(zero);

  for (int i=0; i<s; i++) {
    Saloon current;
    cave.push_back(current);
  }

  for (int i=0; i<t; i++) {
    int to,from,length;
    cin >> to >> from >> length;

    Tunnel one = Tunnel(from, to, length);
    cave[from].connectedTo.push_back(one);

    Tunnel two = Tunnel(to, from, length);
    cave[to].connectedTo.push_back(two);

  }

  Tunnel init = Tunnel();
  int cycleNumber = 0;
  findAllCycles(1, init, cycleNumber);
  
  int q;
  cin >> q;

  for (int l=0; l<q; l++) {
    vector<Saloon> caveCopy = cave;
    
    int initialPos, donaMinhocaLength;
    cin >> initialPos >> donaMinhocaLength;

    int dist[s+1];
    int visitados[s+1];

    priority_queue < pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

    for (int i=0; i<=s; i++) {
      dist[i] = INT_MAX;
      visitados[i] = false;
    }

    dist[initialPos] = 0;

    pq.push(make_pair(dist[initialPos], initialPos));

    while(!pq.empty()) {
      pair<int, int> p = pq.top();
      int u = p.second;
      pq.pop();

      if (visitados[u] == false) {
        visitados[u] = true;
        vector<Tunnel> connectedTo = caveCopy[u].connectedTo;
        for (int i=0; i<connectedTo.size(); i++) {
          int v = connectedTo[i].to;
          int length = connectedTo[i].length;

          if (dist[v] > (dist[u] + length)) {
            dist[v] = dist[u] + length;
            pq.push(make_pair(dist[v], v));
            caveCopy[v].previousSaloon = u;
          }

        }

      }

    }

    int shortestWay = INT_MAX;
    for (Cycle cycle : cycles) {
      if (cycle.totalLength >= donaMinhocaLength && cycle.totalLength < shortestWay) {
        for (int saloon : cycle.saloons) {
          int pathSize = cycle.totalLength + (2*(dist[saloon]));
          int currentCycle = cave[*(cycle.saloons.begin())].cycleNumber;
          if (pathSize < shortestWay && dist[saloon] != INT_MAX && (caveCopy[saloon].previousSaloon == -1 || caveCopy[caveCopy[saloon].previousSaloon].cycleNumber != currentCycle)) {
            shortestWay = pathSize;
          }
        }
      }
    }

    if (shortestWay != INT_MAX) {
      cout << shortestWay << endl;
    } else {
      cout << "-1" << endl;
    }

  }

  }

  return 0;
}