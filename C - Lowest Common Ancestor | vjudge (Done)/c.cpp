#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define repWithEqual(i, a, b) for(int i = int(a); i <= int(b); i++)
#define debugLine() cout << "PASSSSOUUU AQUIIII" << endl;
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";
#define debugA(x, l) { rep(i,0,l) { cout << x[i] << " "; } printf("\n"); }
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) cout << x[i][j] << " "; printf("\n");}}
#define setM( x, l, c, k ) { rep( i, 0, l ){ rep( j, 0, c ) x[i][j] = k;}}


struct node {
  int index;
  node* parent;

  node(int index, node* parent) {
    this->index = index;
    this->parent = parent;
  }

  node(int index) {
    this->index = index;
  }

};

int main() {

  int nc;
  cin >> nc;

  rep(nnc, 0, nc) {
    int n;
    cin >> n;
    cout << "Case " << nnc + 1 << ":" << endl;

    vector<node *> tree;
    node* gb = new node(-1);
    tree.push_back(gb);

    repWithEqual(i, 1, n) {
      node* nod = new node(i);
      tree.push_back(nod);
    }

    repWithEqual(i, 1, n) {

      int m;
      cin >> m;

      node* parent = tree[i];

      rep(j, 0, m) {
        int nod;
        cin >> nod;

        node* curr = tree[nod];
        curr->parent = parent;

      }

    }

    int q;
    cin >> q;

    rep (i, 0, q) {

      int n1;
      int n2;

      cin >> n1 >> n2;

      if (n1 == 1 || n2 == 1) {
        cout << "1" << endl;
        continue;
      }

      if (n1 == n2) {
        cout << n1 << endl;
        continue;
      }

      node* first = tree[n1];
      node* second = tree[n2];

      vector<int> parentsOfFirst;

      node* current = first;
      while (1) {
        node* p = current->parent;
        
        parentsOfFirst.push_back(p->index);
        
        if (p->index == 1) {
          break;
        }

        current = p;
      }

      vector<int> parentsOfSecond;

      current = second;
      while (1) {
        node* p = current->parent;
        
        parentsOfSecond.push_back(p->index);
        
        if (p->index == 1) {
          break;
        }

        current = p;
      }

      // debugA(parentsOfFirst, parentsOfFirst.size());
      // debugA(parentsOfSecond, parentsOfSecond.size());

      vector<int>::iterator it;

      it = find(parentsOfFirst.begin(), parentsOfFirst.end(), n2);
      if (it != parentsOfFirst.end()) {
        cout << n2 << endl;
        continue;
      }

      it = find(parentsOfSecond.begin(), parentsOfSecond.end(), n1);
      if (it != parentsOfSecond.end()) {
        cout << n1 << endl;
        continue;
      }

      rep(j, 0, parentsOfFirst.size()) {
        it = find(parentsOfSecond.begin(), parentsOfSecond.end(), parentsOfFirst[j]);
        if (it != parentsOfSecond.end()) {
          cout << *it << endl;
          break;
        }
      }

    }


  }



  return 0;
}