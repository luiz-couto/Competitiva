#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    string crib;

    getline(cin,s);
    getline(cin, crib);

    int begin = 0;
    int contador = 0;

    for(int i=0; i<(s.length() - crib.length() + 1); i++) {
        bool achei = false;
        for(int j=0; j<crib.length(); j++) {
            //cout << crib[j] << "   -   " << s[begin+j] << endl;
            if(crib[j] == s[begin+j]) {
                begin++;
                achei = true;
                break;
            }
        }
        if(!achei) {
            contador++;
            begin++;
        }
    }

    cout << contador << endl;

    return 0;
}