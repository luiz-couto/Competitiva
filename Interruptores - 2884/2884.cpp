#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<bool> teatro;
    vector<vector<int> > swit;

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

    for(auto i:swit){
        for(auto j:i) {
            cout << j << " - ";
        }
        cout << endl;
    }
    
    
    
    return 0;
}