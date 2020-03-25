#include <bits/stdc++.h>

using namespace std;

vector<bool> teatro;
vector<vector<int> > swit;

bool verificaTudoApagado() {
    // for(auto u:teatro){
    //     cout << u << " ";
    // }
    // cout << endl;
    for(auto l:teatro) {
        if(l == true){
            return false;
        }
    }
    return true;
}



int main() {
    
    int numSwit, numLam;

    cin >> numSwit >> numLam;

    for (int i = 0; i < numLam; i++)
    {
        teatro.push_back(false);
    }

    int acesas;
    cin >> acesas;

    for (int i = 0; i < acesas; i++)
    {
        int l;
        cin >> l;
        teatro[l-1] = true;
    }

    for (int i = 0; i < numSwit; i++)
    {
        int c;
        cin >> c;
        vector<int> v;
        for (int j = 0; j < c; j++)
        {
            int p;
            cin >> p;
            v.push_back(p-1);
        }

        swit.push_back(v);
        
    }

    // for(auto i:swit){
    //     for(auto j:i) {
    //         cout << j << " - ";
    //     }
    //     cout << endl;
    // }

    int contador = 0;
    int help = 0;
    while(help < 10) {
        for (int i = 0; i < swit.size(); i++)
        {
            contador++;
            for(auto l:swit[i]) {
                teatro[l] = !teatro[l];
            }
            if(verificaTudoApagado()) {
                help = 1;
                break;
            }
        }
        if(help == 1){
            break;
        }
        
        
    }

    cout << contador << endl;
    
    
    
    return 0;
}