#include <bits/stdc++.h>

using namespace std;

int main() {
    long int n;
    set<long int> s;
    
    cin >> n;

    while (n % 2 == 0)  
    {  
        s.insert(2);  
        n = n/2;  
    }  
  
    for (int i = 3; i <= sqrt(n); i = i + 2)  
    {  
        while (n % i == 0)  
        {  
            s.insert(i);  
            n = n/i;  
        }  
    }  
  
    if (n > 2)  
        s.insert(n);  

    for(auto p:s) {
        cout << p << " - ";
    }
    cout << endl;

    return 0;
}