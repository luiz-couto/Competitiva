#include <bits/stdc++.h>

using namespace std;

#define INF 10000000
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define repWithEqual(i, a, b) for(int i = int(a); i <= int(b); i++)
#define debugLine() cout << "PASSSSOUUU AQUIIII" << endl;
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";
#define debugA(x, l) { rep(i,0,l) { cout << x[i] << " "; } printf("\n"); }
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) cout << x[i][j] << " "; printf("\n");}}
#define setM( x, l, c, k ) { rep( i, 0, l ){ rep( j, 0, c ) x[i][j] = k;}}

const int NMAX = 1000000;

int res[NMAX];

int getMid(int s, int e) {
  return s + (e -s)/2;
}

int getMax(int *st, int left, int right, int n) 
{  
  left += n; 
  right += n; 

  int ma = INT_MIN; 

  while (left < right) { 

    if (left & 1) { 
      ma = max(ma, st[left]); 
      left++; 
    } 

    if (right & 1) { 
      right--;
      ma = max(ma, st[right]); 
    } 

    left /= 2; 
    right /= 2; 
  } 
  return ma;
} 

int getSumUtil(int *st, int ss, int se, int qs, int qe, int si) {
  if (qs <= ss && qe >= se)  return st[si];
  if (se < qs || ss > qe)  return 0;

  int mid = getMid(ss, se);
  return max(getSumUtil(st, ss, mid, qs, qe, 2*si+1), getSumUtil(st, mid+1, se, qs, qe, 2*si+2));
}

void updateValueUtil(int *st, int ss, int se, int i, int diff, int si) {
  if (i < ss || i > se) return;

  st[si] = st[si] + diff; 
  if (se != ss) {
    int mid = getMid(ss, se);
    updateValueUtil(st, ss, mid, i, diff, 2*si + 1);
    updateValueUtil(st, mid+1, se, i, diff, 2*si + 2);
  }
}

void updateValue(int arr[], int *st, int n, int i, int new_val) {

  int diff = new_val - arr[i];
  arr[i] = new_val;

  updateValueUtil(st, 0, n-1, i, diff, 0);  
}

int getSum(int *st, int n, int qs, int qe) {
  return getSumUtil(st, 0, n-1, qs, qe, 0);
}

int constructSTUtil(int arr[], int ss, int se, int *st, int si) {
  if (ss == se) {
    st[si] = arr[ss];
    return arr[ss];
  }

  int mid = getMid(ss, se);
  st[si] = constructSTUtil(arr, ss, mid, st, si*2+1) + constructSTUtil(arr, mid+1, se, st, si*2+2);
  return st[si];
}

int *constructST(int arr[], int n) {
  int x = (int)(ceil(log2(n)));
  int max_size = 2*(int)pow(2, x) - 1;
  int *st = new int[max_size];

  constructSTUtil(arr, 0, n-1, st, 0);

  return st;
}




int main() {

  int nc;
  cin >> nc;

  rep(nnc, 0, nc) {
    int n,m;
    cin >> n >> m;

    cout << "Testcase " << nnc << ":" << endl;

    rep(i,0,n) {
      int b;
      cin >> b;
      res[i] = b;
    }

    int size = sizeof(res)/sizeof(res[0]);
    int *st = constructST(res, size);

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

        updateValue(res, st, size, r, value);

      } else {
        int r1,r2;
        cin >> r1 >> r2;

        cout << abs(m - (getSum(st, size, r1, r2))) << "\n";
      }

    }

    if (nnc != nc - 1) {
      cout << endl;
    }

  }

  return 0;
}