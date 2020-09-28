#include <bits/stdc++.h>

using namespace std;

#define INF 1000000000
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";
#define debugA(x, l) { rep(i,0,l) { cout << x[i] << " "; } printf("\n"); }
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) cout << x[i][j] << " "; printf("\n");}}
#define setM( x, l, c, k ) { rep( i, 0, l ){ rep( j, 0, c ) x[i][j] = k;}}


struct Seat {
  int x;
  int y;
  bool isFree;
  Seat(int x, int y, bool isFree) {
    this->x = x;
    this->y = y;
    this->isFree = isFree;
  }
};

int dp[1010][1010];
vector<Seat> seats;

int watchTheMovie(int currentSeat, int seatsLeft, int greaterX, int greaterY, int n) {

  if (currentSeat == n+1) {
    return INT_MAX;
  }

  if (dp[currentSeat][seatsLeft] != INT_MAX) {
    return dp[currentSeat][seatsLeft];
  }

  if (!seats[currentSeat].isFree) {
    dp[currentSeat][seatsLeft] = watchTheMovie(currentSeat + 1, seatsLeft, greaterX, greaterY, n);
    return dp[currentSeat][seatsLeft];
  }

  int gx = greaterX;
  int gy = greaterY;
  if (seats[currentSeat].x > greaterX) gx = seats[currentSeat].x;
  if (seats[currentSeat].y > greaterY) gy = seats[currentSeat].y;

  if (seatsLeft == 1) {
    dp[currentSeat][seatsLeft] = min(watchTheMovie(currentSeat + 1, seatsLeft, greaterX, greaterY, n), gx*gy);
    return dp[currentSeat][seatsLeft];
  }

  if (n - currentSeat <= seatsLeft) {
    dp[currentSeat][seatsLeft] = watchTheMovie(currentSeat + 1, seatsLeft - 1, gx, gy, n);
    return dp[currentSeat][seatsLeft];
  }


  dp[currentSeat][seatsLeft] = min(watchTheMovie(currentSeat + 1, seatsLeft, greaterX, greaterY, n), watchTheMovie(currentSeat + 1, seatsLeft - 1, gx, gy, n));
  return dp[currentSeat][seatsLeft];


}



int main() {

  int r,c,k;
  cin >> r >> c >> k;

  rep(i,1,r+1) {
    rep(j,1,c+1) {
      char seat;
      cin.get(seat);
      if (seat == 'X') {
        Seat s = Seat(i,j,false);
        seats.push_back(s);
      } else {
        Seat s = Seat(i,j,true);
        seats.push_back(s);
      }
    }
  }

  memset(dp, INT_MAX, sizeof dp);

  cout << watchTheMovie(0, k, 1, 1, r*c) << endl;

  return 0;
}