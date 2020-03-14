#include <bits/stdc++.h>

using namespace std;

int main() {

    stack<int> s;
    queue<int> q;
    priority_queue<int> p;

    bool isStack = true;
    bool isQueue = true;
    bool isPriority = true;
    
    int n;

    cin >> n;

    for(int i=0; i<n; i++) {
        int command, number;
        cin >> command >> number;

        if (command == 1) {
            s.push(number);
            q.push(number);
            p.push(number);
        }

        if(command == 2) {
            int retStack = s.top();
            s.pop();
            if(retStack != number) {
                isStack = false;
            }

            int retQueue = q.front();
            q.pop();
            if(retQueue != number) {
                isQueue = false;
            }

            int retPriority = p.top();
            p.pop();
            if (retPriority != number) {
                isPriority = false;
            }

        }

    }

    if (isStack && !isQueue && !isPriority)
        cout << "stack" << endl;

    if (isStack && isQueue && !isPriority)
        cout << "not sure" << endl;
    
    if (isStack && isQueue && isPriority)
        cout << "not sure" << endl;

    if (isStack && !isQueue && isPriority)
        cout << "not sure" << endl;
    
    if (!isStack && isQueue && !isPriority)
        cout << "queue" << endl;
    
    if (!isStack && isQueue && isPriority)
        cout << "not sure" << endl;

    if (!isStack && !isQueue && !isPriority)
        cout << "impossible" << endl;
    
    if (!isStack && !isQueue && isPriority)
        cout << "priority queue" << endl;

    return 0;
}