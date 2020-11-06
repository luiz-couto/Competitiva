#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n';
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)


void construct_segment_tree(vector<int>& segtree, vector<int>& a, int n) {

  for (int i = 0; i < n; i++) {
    segtree[n + i] = a[i];
  }  

  for (int i = n - 1; i >= 1; i--) {
    segtree[i] = max(segtree[2 * i], segtree[2 * i + 1]); 
  }

} 
  
void update(vector<int>& segtree, int pos, int value, int n) {

  pos += n; 

  segtree[pos] = value; 

  while (pos > 1) {  
    pos >>= 1; 
    segtree[pos] = max(segtree[2 * pos],segtree[2 * pos + 1]); 
  } 
}
  
int getMax(vector<int>& segtree, int left, int right, int n) {
  left += n; 
  right += n; 
 
  int ma = INT_MIN; 

  while (left < right) { 
    
    if (left & 1) { 
      ma = max(ma, segtree[left]); 
      left++; 
    } 

    if (right & 1) { 
      right--; 
      ma = max(ma, segtree[right]); 
    } 

    left /= 2; 
    right /= 2; 
  } 
  return ma; 
} 


int main() { _

  int nc;
  cin >> nc;

  rep(nnc, 0, nc) {
    int n,m;
    cin >> n >> m;

    cout << "Testcase " << nnc << ":" << endl;

    vector<int> res;

    rep(i,0,n) {
      int b;
      cin >> b;
      res.push_back(b);
    }

    vector<int> segtree(2 * n);
    construct_segment_tree(segtree, res, n);

    int q;
    cin >> q;

    rep(i,0,q) {
      char c;
      cin >> c;

      if (c == 'A') {
        int moreBallons;
        cin >> moreBallons;
        m = m + moreBallons;
      
      } else if (c == 'B') {

        int r;
        int value;
        cin >> r >> value;
        update(segtree, r, value, n);

      } else {
        int r1,r2;
        cin >> r1 >> r2;
        cout << abs(getMax(segtree, r1, r2+1, n) - m) << "\n";
      }

    }

    if (nnc != nc - 1) {
      cout << endl;
    }

  }

  return 0;
}