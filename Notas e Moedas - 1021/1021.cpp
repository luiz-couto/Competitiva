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

    printf("NOTAS:\n");
    for (int i=0; i<6; i++) {
        printf("%i nota(s) de R$ %i.00\n", RES[i], VEC[i]/100);
    }

    printf("MOEDAS:\n");
    for (int i=6; i<12; i++) {
        printf("%i moedas(s) de R$ %s\n", RES[i], bla[i].c_str());
    }

    return 0;
}
