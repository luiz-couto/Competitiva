#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    getline(cin, s);

    int sum = 0;

    for(int i=0; i<s.length(); i++) {
        sum = sum + s[i];
    }

    cout << sum%3 << endl;

    return 0;
}