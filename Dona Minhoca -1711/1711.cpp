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
  Saloon() {
    this->connectedTo = {};
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
  
  cout << cycles[0].totalLength << endl;

  return 0;
}