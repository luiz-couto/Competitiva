#include <bits/stdc++.h>

using namespace std;

vector<vector<int> > g;
vector<int> visited;

void addEdge(int v1, int v2) {
    g[v1].push_back(v2);
    g[v2].push_back(v1);
}

void runBFS(int v) {
    queue<int> q;
    q.push(v);
    
    visited[v] = 1;

    while(!q.empty()) {
        int u = q.front();
        q.pop();

        cout << u << ",";

        for (auto i = g[u].begin(); i != g[u].end(); i++) {
            if(visited[*i] == 0) {
                q.push(*i);
                visited[*i] = 1;
            }
        }

    }

}

int main() {

    int vertices, edges; 
    cin >> vertices >> edges; 
  
    visited.assign(vertices, 0); 
    g.assign(vertices, vector<int>()); 
  
    int a, b; 
    for (int i = 0; i < edges; i++) { 
        cin >> a >> b; 
        addEdge(a, b); 
    } 
  
    for (int i = 0; i < vertices; i++) { 
        if (visited[i] == 0) { 
            runBFS(i);
            cout << endl;
        }
    } 
  
    return 0;
}