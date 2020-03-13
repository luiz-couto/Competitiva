#include <bits/stdc++.h>

using namespace std;

vector<vector<int> > g;
vector<int> visited;

string alp[26] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};

std::string convertIntToChar(int i) {
    return alp[i];
}

int convertStringToInt(string str) {
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
    
    visited[v] = 1;

    while(!q.empty()) {
        int u = q.front();
        q.pop();

        cout << convertIntToChar(u) << ",";

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
    int numComp = 0;

    cin >> vertices >> edges; 
  
    visited.assign(vertices, 0); 
    g.assign(vertices, vector<int>()); 
  
    string a, b; 
    for (int i = 0; i < edges; i++) { 
        cin >> a >> b;
        int ai = convertStringToInt(a);
        int bi = convertStringToInt(b); 
        addEdge(ai, bi); 
    } 
  
    for (int i = 0; i < vertices; i++) { 
        if (visited[i] == 0) {
            runBFS(i);
            numComp++;
            cout << endl;
        }
    }

    cout << numComp << " connected components" << endl;
  
    return 0;
}