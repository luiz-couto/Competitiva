#include <bits/stdc++.h>

using namespace std;

vector<vector<int> > g;
vector<int> visited;

char alp[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

char convertIntToChar(int i) {
    return alp[i];
}

int convertStringToInt(char str) {
    for (int i=0; i<26; i++) {
        if(str == alp[i]) {
            return i;
        }
    }
}

void addEdge(int v1, int v2) {
    g[v1].push_back(v2);
    g[v2].push_back(v1);
}

void runBFS(int v) {
    queue<int> q;
    q.push(v);

    vector<char> vec;
    
    visited[v] = 1;

    while(!q.empty()) {
        int u = q.front();
        q.pop();

        vec.push_back(convertIntToChar(u));

        for (auto i = g[u].begin(); i != g[u].end(); i++) {
            if(visited[*i] == 0) {
                q.push(*i);
                visited[*i] = 1;
            }
        }

    }

    sort(vec.begin(), vec.end());

    for(char c:vec) {
        cout << c << ",";
    }

}

int main() {
    ios::sync_with_stdio(0);
    int n;
    cin >> n;

    for (int i=0; i<n; i++){
        cout << "Case #" << i+1 << ":" << endl; 
        int vertices, edges;
        int numComp = 0;

        cin >> vertices >> edges; 
    
        visited.assign(vertices, 0); 
        g.assign(vertices, vector<int>()); 
    
        char a, b; 
        for (int i=0; i<edges; i++) { 
            cin >> a >> b;
            int ai = convertStringToInt(a);
            int bi = convertStringToInt(b); 
            addEdge(ai, bi); 
        } 
    
        for (int i=0; i<vertices; i++) { 
            if (visited[i] == 0) {
                runBFS(i);
                numComp++;
                cout << endl;
            }
        }

        cout << numComp << " connected components" << endl << endl;
    }
  
    return 0;
}