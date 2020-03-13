#include <bits/stdc++.h>

int VEC[12] = {10000, 5000, 2000, 1000, 500, 200, 100, 50, 25, 10, 5 ,1};
int RES[12]; 

using namespace std;

string bla[12] = {"0","0","0","0","0","0","1.00", "0.50", "0.25", "0.10", "0.05", "0.01"};

int main() {

    int ic, im;
    scanf("%d.%d", &ic, &im);

    int y = (ic*100) + im;

    for (int i=0; i<12; i++) {
        int quo;
        int res;

        quo = y/VEC[i];
        RES[i] = quo;

        if(quo != 0) {
            y = y - (quo * VEC[i]);
        }
    }

    cout << "NOTAS:" << endl; 

    cout << RES[0] << " nota(s) de R$ 100.00" << endl;

    cout << RES[1] << " nota(s) de R$ 50.00" << endl;

    cout << RES[2] << " nota(s) de R$ 20.00" << endl;

    cout << RES[3] << " nota(s) de R$ 10.00" << endl;

    cout << RES[4] << " nota(s) de R$ 5.00" << endl;

    cout << RES[5] << " nota(s) de R$ 2.00" << endl;

    cout << "MOEDAS:" << endl;

    cout << RES[6] << " moeda(s) de R$ 1.00" << endl;

    cout << RES[7] << " moeda(s) de R$ 0.50" << endl;

    cout << RES[8] << " moeda(s) de R$ 0.25" << endl;

    cout << RES[9] << " moeda(s) de R$ 0.10" << endl;

    cout << RES[10] << " moeda(s) de R$ 0.05" << endl;

    cout << RES[11] << " moeda(s) de R$ 0.01" << endl;

    return 0;
}
