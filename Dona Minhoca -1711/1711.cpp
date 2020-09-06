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
  }
};

struct Saloon {
  vector<Tunnel> connectedTo;
  Tunnel parent;
  int status;
  int cycleNumber;
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
  return 0;
}