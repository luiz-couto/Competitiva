#include <bits/stdc++.h>

using namespace std;

int main() {
    
    while(1) {
    string mStr,frase;

    getline(cin, mStr);
    int m = stoi(mStr);
    if(m == 0){
        break;
    }

    getline(cin, frase);

    vector<pair<char, int> > vCounter;
    map<char, int> index;

    set<char> s;

    for(int i=0; i<frase.length(); i++) {
        s.insert(frase[i]);
    }

    int k=0;
    for(auto c:s) {
        vCounter.push_back(pair<char, int>(c,0));
        index.insert(pair<char, int>(c,k));
        k++;
    }

    int resultado = 0;
    int greater = 0;

    int pointer = 0;
    int contador = 0;

    for(int i=0; i<frase.length(); i++) {
        if(vCounter[index[frase[i]]].second == 0) {
            contador = contador + 1;
            if (contador == m + 1) {
                while(1) { 
                    vCounter[index[frase[pointer]]].second = vCounter[index[frase[pointer]]].second - 1;
                    resultado = resultado - 1;
                    if(vCounter[index[frase[pointer]]].second == 0) {
                        pointer++;
                        break;
                    } else {
                        pointer++;
                    }
                }
                contador = contador - 1;
            }
        }
        vCounter[index[frase[i]]].second = vCounter[index[frase[i]]].second + 1;
        resultado = resultado + 1;

        if(resultado > greater) {
            greater = resultado;
        }

    }

    cout << greater << endl;
    }

    return 0;
}