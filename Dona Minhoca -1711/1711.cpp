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
  }

};

struct Cycle {
  vector<int> saloons;
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

    newCycle.saloons.push_back(cur.from);
    newCycle.totalLength = newCycle.totalLength + cur.length;

    cave[cur.from].cycleNumber = cycleNumber;

    while(cur.from != currentSaloon) {
      
      cur = cave[cur.from].parent;
      cave[cur.from].cycleNumber = cycleNumber;

      newCycle.saloons.push_back(cur.from);
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
  
  int s,t;
  cin >> s >> t;
  
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

    caveCopy[initialPos].shortestPathFromInitial = 0;
    int currentSaloon = initialPos;

    for (int i=0; i<s; i++) { 
      vector<Tunnel> connectedTo = caveCopy[currentSaloon].connectedTo;
      for (int j=0; j<connectedTo.size(); j++) {
        if (!caveCopy[connectedTo[j].to].visited) {

          int pathSize = caveCopy[currentSaloon].shortestPathFromInitial + connectedTo[j].length;

          if (pathSize < caveCopy[connectedTo[j].to].shortestPathFromInitial) {
            caveCopy[connectedTo[j].to].shortestPathFromInitial = pathSize;
            caveCopy[connectedTo[j].to].previousSaloon = currentSaloon;
          }
        }
      }

      caveCopy[currentSaloon].visited = true;

      int smallestPathToInitial = INT_MAX;
      int nextSaloon = -1;

      for (int k=1; k<=s; k++) {
        if (caveCopy[k].visited == false && caveCopy[k].shortestPathFromInitial <= smallestPathToInitial) {
          smallestPathToInitial = caveCopy[k].shortestPathFromInitial;
          nextSaloon = k;
        }
      }

      if (nextSaloon == -1) {
        break;
      }

      currentSaloon = nextSaloon;

    }

    int shortestWay = INT_MAX;
    for (Cycle cycle : cycles) {
      if (cycle.totalLength >= donaMinhocaLength) {
        for (int saloon : cycle.saloons) {
          if (caveCopy[saloon].shortestPathFromInitial != INT_MAX && !verifyIfIsInCycle(caveCopy[saloon].previousSaloon, cycle)) {
            int pathSize = cycle.totalLength + (2*(caveCopy[saloon].shortestPathFromInitial));
            if (pathSize < shortestWay) {
              shortestWay = pathSize;
            }
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



  return 0;
}