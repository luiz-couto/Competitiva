#include <bits/stdc++.h>

using namespace std;

int max(int a, int b) { return (a > b)? a : b; }

int main() {
    vector<int> brinquedos;
    vector<int> pesos;

    int T[brinquedos.size()+1][50 + 1];

    for (int i=0; i<=brinquedos.size(); i++) {
        for (int w=0; w<=50; w++) {
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

    cout << T[brinquedos.size()][50] << " brinquedos" << endl;

    int n = brinquedos.size();
    int M = 50;
    
    int numPacotesUsados = 0;
    int pesoTotal = 0;

    while (n != 0) {
		if (T[n][M] != T[n - 1][M]) {
			//System.out.println("\tPackage " + n + " with W = " + pesos[n - 1] + " and Value = " + brinquedos[n - 1]);
			//cout << "Pacote " << n << " com peso = " << pesos[n - 1] << " e " << brinquedos[n - 1] << " brinquedos" << endl;
            numPacotesUsados++;
            pesoTotal = pesoTotal + pesos[n-1];
			M = M - pesos[n-1];
		}
		
		n--;
	}

    cout << "Peso: " << pesoTotal << " kg" << endl;
    cout << "sobra(m) " << brinquedos.size() - numPacotesUsados << " pacote(s)" << endl;  

    return 0;
}