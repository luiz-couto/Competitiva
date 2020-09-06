#include <bits/stdc++.h>

using namespace std;

bool isPossibleToEatPopcorn(int time, int numberOfComp, int popPerSecond, vector<int> popcorns) {
  
  int maxPopcornPerComp = time*popPerSecond;
  
  int currentCompetitor = 1;
  int currentCompLeftAmount = maxPopcornPerComp;

  for (int i=0; i<popcorns.size(); i++) {
    if (currentCompLeftAmount >= popcorns[i]) {
      currentCompLeftAmount = currentCompLeftAmount - popcorns[i];
    } else {
      if (currentCompetitor == numberOfComp) {
        return false;
      } else {
        currentCompetitor = currentCompetitor + 1;
        currentCompLeftAmount = maxPopcornPerComp;
        i--;
      }
    }
  }

  return true;

}



int main() {
  bool teste = isPossibleToEatPopcorn(4,3,4,{3,8,3,10,7});
  cout << teste << endl;
  return 0;
}