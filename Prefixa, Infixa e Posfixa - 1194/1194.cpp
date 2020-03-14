#include <bits/stdc++.h>

using namespace std;

int findRoot(char v[], int r, int size) {
    for (int i=0; i<size; i++) {
        if(v[i] == r)
            return i;
    }
    return -1;
}

void posOrdem(char inOrder[],char preOrder[], int size) {
    int root = findRoot(inOrder, preOrder[0], size);
    if(root != 0) {
        posOrdem(inOrder, preOrder+1, root);
    }
    if(root != size-1) {
        posOrdem(inOrder + root + 1, preOrder + root + 1, size-root-1);
    }

    cout << preOrder[0];
}

int main() {

    int numNodes;
    cin >> numNodes;

    // char preOrder[] = { '1','2','3' }; 
    // char inOrder[] = { '2','1','3' }; 
    // int size = sizeof(inOrder) / sizeof(inOrder[0]);  
    // posOrdem(inOrder, preOrder, size);
    // cout << endl;
    return 0; 
}