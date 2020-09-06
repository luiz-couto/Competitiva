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
  
  int n,c,t;
  cin >> n >> c >> t;

  vector<int> popcorns;
  for (int i=0; i<n; i++) {
    int popAmount;
    cin >> popAmount;
    popcorns.push_back(popAmount);
  }
  
  
  bool teste = isPossibleToEatPopcorn(10,c,t,popcorns);
  // int secToBeTested = 100000/2;

  // while(1) {



  // }

  cout << teste << endl;


  return 0;
}