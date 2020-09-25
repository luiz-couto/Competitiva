#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> heights;

  for(int i=0; i<n; i++) {
    int h;
    cin >> h;
    heights.push_back(h);
  }

  vector<int> leftWing(n, -1);
  vector<int> rightWing(n, -1);

  leftWing[0] = 1;
  for (int i=1; i<leftWing.size(); i++) {
    leftWing[i] = min(leftWing[i-1] + 1, heights[i]);
  }

  rightWing[n-1] = 1;
  for (int i=n-2; i>=0; i--) {
    rightWing[i] = min(rightWing[i+1] + 1, heights[i]);
  }

  int ans = 0;
  for (int i=0; i<n; i++) {
    int minim = min(leftWing[i], rightWing[i]);
    if (minim > ans) {
      ans = minim;
    }
  }

  cout << ans << endl;

  return 0;
}