#include <bits/stdc++.h>

using namespace std;

int main() {

    vector<int> v;
    v.push_back(2);
    v.push_back(1);

    vector<int>::iterator begin = v.begin()+1;
    vector<int>::iterator end = v.end()-1;

    //vector<int>::iterator middle = begin + (((end - v.begin()) - (begin - v.begin())) / 2);

    cout << *begin << endl;
    cout << *end << endl;

    v.erase(end--);

    cout << v.size() << endl;
    //cout << *middle << endl;
    
    //cout << ((end - v.begin()) - (begin - v.begin())) + 1 << endl;

    


    return 0;
}