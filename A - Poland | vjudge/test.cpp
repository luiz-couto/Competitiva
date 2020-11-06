#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define fori(i, n) for(int i = 0; i < n; i++)
#define For(i, a, b) for(i = a; i < b; i++)
#define roF(i, a, b) for(i = a; i > b; i--)

typedef long long ll;
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const int MAX = 1e5;
int n;

void construct_segment_tree(vector<int>& segtree, 
                            vector<int>& a, int n) 
{ 
    // assign values to leaves of the segment tree 
    for (int i = 0; i < n; i++) 
        segtree[n + i] = a[i]; 
  
    /* assign values to internal nodes 
    to compute maximum in a given range */
    for (int i = n - 1; i >= 1; i--) 
        segtree[i] = max(segtree[2 * i], 
                         segtree[2 * i + 1]); 
} 
  
void update(vector<int>& segtree, int pos, int value, 
            int n) 
{ 
    // change the index to leaf node first 
    pos += n; 
  
    // update the value at the leaf node 
    // at the exact index 
    segtree[pos] = value; 
  
    while (pos > 1) { 
  
        // move up one level at a time in the tree 
        pos >>= 1; 
  
        // update the values in the nodes in 
        // the next higher level 
        segtree[pos] = max(segtree[2 * pos], 
                           segtree[2 * pos + 1]); 
    } 
} 
  
int range_query(vector<int>& segtree, int left, int
                                                    right, 
                int n) 
{ 
    /* Basically the left and right indices will move 
        towards right and left respectively and with 
        every each next higher level and compute the  
        maximum at each height. */
    // change the index to leaf node first 
    left += n; 
    right += n; 
  
    // initialize maximum to a very low value 
    int ma = INT_MIN; 
  
    while (left < right) { 
  
        // if left index in odd 
        if (left & 1) { 
            ma = max(ma, segtree[left]); 
  
            // make left index even 
            left++; 
        } 
  
        // if right index in odd 
        if (right & 1) { 
  
            // make right index even 
            right--; 
  
            ma = max(ma, segtree[right]); 
        } 
  
        // move to the next higher level 
        left /= 2; 
        right /= 2; 
    } 
    return ma; 
} 

int main(){ _
	int t; cin >> t;
	fori(T, t){
		cout << "Testcase " << T << ":" << endl;
		int m; cin >> n >> m;
		vector<int> balloons;
		fori(N, n) {
			int aux; cin >> aux;
			balloons.pb(aux);
		}
		vector<int> segtree(2 * n);
		construct_segment_tree(segtree, balloons, n);
		int q; cin >> q;
		while(q--){
			//fori(kk, n) cout << seg::seg[kk] << " "; cout << endl;

			char type; cin >> type;
			int aux1, aux2;
			if (type == 'A'){
				int k; cin >> k;
				m += k;
			} else if (type == 'B') {
				int j, k; cin >> j >> k;
				update(segtree, j, k, n);
			} else {
				int i, j; cin >> i >> j;
				cout << abs(range_query(segtree, i, j+1, n)-m) << endl;
			}
		}
		if (T != t-1) cout << endl;
	}
	
	exit(0);
}