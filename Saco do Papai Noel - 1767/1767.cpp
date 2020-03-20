#include <bits/stdc++.h>

using namespace std;

int max(int a, int b) { return (a > b)? a : b; }

int getToys(int maxSum, vector<int> pesos, vector<int> brinquedos) {
    int T[brinquedos.size()+1][maxSum + 1];

    for (int i=0; i<=brinquedos.size(); i++) {
        for (int w=0; w<=maxSum; w++) {
            if(i==0 || w==0){
                T[i][w] = 0;
            }
            else if (pesos[i-1] <= w) {
                T[i][w] = max(brinquedos[i-1] + T[i-1][w - pesos[i - 1]], T[i-1][w]);
            }
            else
            {
                T[i][w] = T[i-1][w];
            }
            
        }
    }
    return T[brinquedos.size()][maxSum];
}

int main() {
    vector<int> val;
    val.push_back(6);
    val.push_back(21);
    val.push_back(72);
    val.push_back(143);
    

    vector<int> wt;
    wt.push_back(17);
    wt.push_back(23);
    wt.push_back(24);
    wt.push_back(2);


    cout << getToys(50, wt, val) << endl;


    return 0;
}