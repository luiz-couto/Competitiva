#include <bits/stdc++.h>

using namespace std;

vector<bool> checkForWallCollisions(int px, int py, int senseRadius, int m, int n) {
  vector<bool> collisions(4, false);
  // Left Wall
  if (px - senseRadius <= 0) {
    collisions[0] = true;
  }

  // Top Wall
  if (py + senseRadius >= m) {
    collisions[1] = true;
  }

  // Right Wall
  if (px + senseRadius >= n) {
    collisions[2] = true;
  }

  // Bottom Wall
  if (py - senseRadius <= 0) {
    collisions[3] = true;
  }

  return collisions;
}

bool checkForSensorsCollision(int px, int py, int pRadius, int qx, int qy, int qRadius) {
  float distance = sqrt(pow((qx-px),2) + pow((qy-py),2));
  if (distance <= pRadius + qRadius) {
    return true;
  }
  return false;
}

int main() {
  // vector<bool> collisions = checkForWallCollisions(2,2,10,5,15);
  // cout << collisions[0] << " " << collisions[1] << " " << collisions[2] << " " << collisions[3] << endl;

  cout << checkForSensorsCollision(2,1,3,5,4,2) << endl;
  return 0;
}