#include <bits/stdc++.h>

using namespace std;

int main() {
    
    string mStr,frase;

    getline(cin, mStr);
    int m = stoi(mStr);

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

    //cout << vCounter[index['a']].second << endl;

    int resultado = 0;
    int greater = 0;

    int pointer = 0;
    int contador = 0;
    for(int i=0; i<frase.length(); i++) {

        if(vCounter[index[frase[i]]].second == 0) {
            contador = contador + 1;
            if (contador == m + 1) {
                while(1) {
                    vCounter[frase[pointer]].second = vCounter[frase[pointer]].second - 1;
                    if(vCounter[frase[pointer]].second == 0) {
                        break;
                    } else {
                        pointer++;
                    }
                }
                contador = contador - 1;
            }
        }
        vCounter[index[frase[i]]].second = vCounter[index[frase[i]]].second + 1;



        
    }

    return 0;
}