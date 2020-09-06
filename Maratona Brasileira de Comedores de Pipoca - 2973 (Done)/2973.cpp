#include <bits/stdc++.h>

using namespace std;

bool isPossibleToEatPopcorn(long long int time, long long int numberOfComp, long long int popPerSecond, vector<long long int> popcorns) {
  
  long long int maxPopcornPerComp = time*popPerSecond;
  
  long long int currentCompetitor = 1;
  long long int currentCompLeftAmount = maxPopcornPerComp;

  for (long long int i=0; i<popcorns.size(); i++) {
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
  
  long long int n,c,t;
  cin >> n >> c >> t;

  vector<long long int> popcorns;
  for (long long int i=0; i<n; i++) {
    long long int popAmount;
    cin >> popAmount;
    popcorns.push_back(popAmount);
  }
  
  
  // bool teste = isPossibleToEatPopcorn(10,c,t,popcorns);
  long long int first = 1;
  long long int last = 500000000;

  long long int secToBeTested = (first+last)/2;

  while(1) {

    bool teste = isPossibleToEatPopcorn(secToBeTested,c,t,popcorns);
    if (teste) {
      last = secToBeTested;
    } else {
      first = secToBeTested;
    }

    if (last - first == 1) {
      break;
    }

    secToBeTested = (first+last)/2;

  }
  
  if (isPossibleToEatPopcorn(last,c,t,popcorns)) {
    cout << last << endl;
  } else {
    cout << first << endl;
  }


  return 0;
}