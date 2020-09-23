#include <bits/stdc++.h>

using namespace std;

int castleKnapsack(vector<int> destructions, vector<int> weights, int cannonCharge, int n) {
  if (n == 0 || cannonCharge == 0) {
    return 0;
  }

   if (weights[n] > cannonCharge){
    return castleKnapsack(destructions, weights, cannonCharge, n - 1); 
   } else {
        return max( 
            destructions[n] + castleKnapsack(destructions, weights, cannonCharge - weights[n], n - 1), 
            castleKnapsack(destructions, weights, cannonCharge,  n - 1)); 
   }

}

int main() {
  int numberOfCases;
  cin >> numberOfCases;

  for (int i=0; i<numberOfCases; i++) {
    int n;
    vector<int> destructions;
    vector<int> weights;

    cin >> n;
    for (int j=0; j<n; j++) {
      int d,w;
      cin >> d >> w;
      destructions.push_back(d);
      weights.push_back(w);
    }

    int cannonCharge;
    cin >> cannonCharge;

    int castleResistence;
    cin >> castleResistence;

    int powerOfDestruction = castleKnapsack(destructions, weights, cannonCharge, n);

    cout << powerOfDestruction << endl;
    if (powerOfDestruction >= castleResistence) {
      cout << "Missao completada com sucesso" << endl;
    } else {
      cout << "Falha na missao" << endl;
    }

  }

  return 0;
}