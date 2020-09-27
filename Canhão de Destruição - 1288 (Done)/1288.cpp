#include <bits/stdc++.h>

using namespace std;

int dp[100][110];
int aux[100][110];

int cmp;

int castleKnapsack(int destructions[100], int weights[100], int cannonCharge, int n, int currentProjectile) {

  if (currentProjectile == n) {
    return 0;
  }

  if (aux[currentProjectile][cannonCharge] == cmp) {
    return dp[currentProjectile][cannonCharge];
  }

  aux[currentProjectile][cannonCharge] = cmp;

  if (weights[currentProjectile] > cannonCharge) {
    dp[currentProjectile][cannonCharge] = castleKnapsack(destructions, weights, cannonCharge, n, currentProjectile + 1);
    return dp[currentProjectile][cannonCharge];
  }

  dp[currentProjectile][cannonCharge] = max(destructions[currentProjectile] + castleKnapsack(destructions, weights, cannonCharge - weights[currentProjectile], n, currentProjectile + 1), 
  castleKnapsack(destructions, weights, cannonCharge, n, currentProjectile + 1));

  return dp[currentProjectile][cannonCharge];

}

int main() {
  int numberOfCases;
  cin >> numberOfCases;

  for (int i=0; i<numberOfCases; i++) {
    cmp++;
    int n;
    
    cin >> n;
    
    int destructionPower[100];
    int weights[100];
  
    for (int j=0; j<n; j++) {
      int d,w;
      cin >> d >> w;
      destructionPower[j] = d;
      weights[j] = w;
    }

    int cannonCharge;
    cin >> cannonCharge;

    int castleResistence;
    cin >> castleResistence;

    int powerOfDestruction = castleKnapsack(destructionPower, weights, cannonCharge, n, 0);

    // cout << powerOfDestruction << endl;
    if (powerOfDestruction >= castleResistence) {
      cout << "Missao completada com sucesso" << endl;
    } else {
      cout << "Falha na missao" << endl;
    }

  }

  return 0;
}