#include <bits/stdc++.h>

using namespace std;

#define INF 100000000
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)

const int MAXN = 105;

int g[MAXN][MAXN];
int v[MAXN];
int w[MAXN];
bool visited[MAXN];

int main() {

  int numberOfCases;
  cin >> numberOfCases;

  rep(nc, 0, numberOfCases) {
    int n;
    int m;
    cin >> n >> m;

    rep(j, 0, n + 1) {
      rep(k, 0, n + 1) {
        g[j][k] = 0;
      }
    }

    int smaller = INF;
    rep (j, 0, m) {
      int u, v, c;
      cin >> u >> v >> c;

      u--;
      v--;

      g[u][v] = g[v][u] = c;
      smaller = min(smaller, c);
    }

    if (n - 1 == m) {
      cout << smaller << endl;
      continue;
    }

    // this is Stoer Wagner Algorithm
    int res = INF;
    rep(i, 0, n) v[i] = i;

    while(n > 1) {
      
      int prev = v[0];
      
      visited[v[0]] = true;
      rep (i, 1, n) {
        visited[v[i]] = false;
        w[i] = g[v[0]][v[i]];
      }

      rep(i, 1, n) {
        int aux = -1;
        rep(j, 1, n) {
          if (!visited[v[j]] && (aux<0 || w[j] > w[aux])) aux = j;
        }
        visited[v[aux]] = true;
      
        if (i == n-1) {
          res = min(res, w[aux]);

          rep(j,0,n) {
            g[v[j]][prev] = g[prev][v[j]] += g[v[aux]][v[j]];
          }

          v[aux] = v[--n];
          break;

        }
      
        rep(j, 1, n) {
          if (!visited[v[j]]) {
            w[j] = w[j] + g[v[aux]][v[j]];
          }
        }

        prev = v[aux];
      
      }

    }

    cout << res << endl;

  }

  return 0;
}