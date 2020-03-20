#include <bits/stdc++.h>

using namespace std;

vector<int> v;
int numJoias = 0;

bool verificaNovo(int n) {
    for(auto x:v) {
        if (n == x) {
            return false;
        }
    }
    return true;
}


int main() {
    string s;
    while(getline(cin, s)) {
        for(int i=0; i<s.length(); i++) {
            if(s[i] == '(') {
                s[i] = '1';
            }
            else if(s[i] == ')') {
                s[i] = '2';
            }
        }
        int n = stoi(s);
        if(verificaNovo(n)) {
            v.push_back(n);
            numJoias++;
        }
    }
    cout << numJoias << endl;
    return 0;
}