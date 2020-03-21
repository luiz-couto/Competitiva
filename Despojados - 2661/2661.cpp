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

    // for(auto p:s) {
    //     cout << p << " - ";
    // }
    
    //cout << s.size() << endl;

    int despojados = 0;

    for(int i=s.size(); i>1; i--) {
        int times = 1;
        int fac = s.size();
        int iFactorial = 1;
        for(int j=0; j<i; j++) {
            iFactorial = iFactorial*(i - j);
            times = times * fac;
            fac = fac - 1;
        }
        times = times/iFactorial;
        despojados = despojados + times;
    }

    cout << despojados << endl;

    return 0;
}