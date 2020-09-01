#include <bits/stdc++.h>

using namespace std;

bool findAux = false;

struct Point {
  int x;
  int y;
  int radius;
  vector<int> connectedTo;
  Point(int x, int y, int radius) {
    this->x = x;
    this->y = y;
    this->radius = radius;
    this->connectedTo = {};
  }
};

vector<bool> checkForWallCollisions(int px, int py, int senseRadius, int m, int n) {
  vector<bool> collisions(4, false);
  // Left Wall
  if (px - senseRadius <= 0) {
    collisions[0] = true;
  }

  // Top Wall
  if (py + senseRadius >= n) {
    collisions[1] = true;
  }

  // Right Wall
  if (px + senseRadius >= m) {
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

void DFS(int v, vector<bool> visited, int pointToFind, vector<Point> roomMap) {
  visited[v] = true;
  if (v == pointToFind) {
    findAux = true;
  }
  if (!findAux) {
    for(int i=0; i<roomMap[v].connectedTo.size(); i++) {
      if (!visited[roomMap[v].connectedTo[i]] && !findAux) {
        DFS(roomMap[v].connectedTo[i], visited, pointToFind, roomMap);
      }
    }
  }
}

bool twoWallsConnect(int firstWall, int secondWall, int k, vector<Point> roomMap) {
  findAux = false;
  vector<bool> visited(k+4, false);
  DFS(firstWall, visited, secondWall, roomMap);
  if (findAux == true) {
    return true;
  } else {
    return false;
  }
}

int main() {
  
  int m,n,k;
  cin >> m >> n >> k;

  // Creating roomMap and walls
  vector<Point> roomMap(4, Point(-1,-1,1));

  for (int i=4; i<k+4; i++) {
    int px,py,senseRadius;
    cin >> px >> py >> senseRadius;
    roomMap.push_back(Point(px, py, senseRadius));

    // Check for wall collisions
    vector<bool> wallCollisions = checkForWallCollisions(px, py, senseRadius, m, n);
    for (int j=0; j<4; j++) {
      if (wallCollisions[j] == true) {
        roomMap[i].connectedTo.push_back(j);
        roomMap[j].connectedTo.push_back(i);
      }
    }

    // Check for collision with all the sensors added before
    for (int j=4; j<roomMap.size()-1; j++) {
      bool hasCollision = checkForSensorsCollision(px, py, senseRadius, roomMap[j].x, roomMap[j].y, roomMap[j].radius);
      if (hasCollision == true) {
        roomMap[i].connectedTo.push_back(j);
        roomMap[j].connectedTo.push_back(i);
      }
    }

  }

  // for (int i=0; i<roomMap.size(); i++) {
  //   cout << i << " - ";
  //   for (int j=0; j<roomMap[i].connectedTo.size(); j++) {
  //     cout << roomMap[i].connectedTo[j] << " ";
  //   }
  //   cout << endl;
  // }

  if (twoWallsConnect(1,2,k,roomMap) || twoWallsConnect(0,3,k,roomMap) || twoWallsConnect(1,3,k,roomMap) || twoWallsConnect(0,2,k,roomMap)) {
    cout << "N" << endl;
  } else {
    cout << "S" << endl;
  }


  return 0;
}