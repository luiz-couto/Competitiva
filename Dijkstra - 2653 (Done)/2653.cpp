#include <bits/stdc++.h>

using namespace std;

vector<string> v;
int numJoias = 0;

bool verificaNovo(string s) {
    for(auto x:v) {
        if(s == x) {
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
        if(verificaNovo(s)) {
            v.push_back(s);
            numJoias++;
        }
    }
    std::cout << numJoias << endl;
    return 0;
}