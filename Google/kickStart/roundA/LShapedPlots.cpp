#include <bits/stdc++.h>
using namespace std;

bool grid[1002][1002] = {false};
int R, C;

bool upLength(int length, int i, int j) {
  if (i-length+1 < 1) {
    return false;
  }
  int lastRow = i-length+1;
  i--;
  for (; i >= lastRow; i--) {
    if (!grid[i][j]) {
      return false;
    }
  }
  return true;
}

bool downLength(int length, int i, int j) {
  if (i+length-1 > R) {
    return false;
  }
  int lastRow = i+length-1;
  i++;
  for (; i <= lastRow; i++) {
    if (!grid[i][j]) {
      return false;
    }
  }
  return true;
}

bool leftLength(int length, int i, int j) {
  if (j-length+1 < 1) {
    return false;
  }
  int lastCol = j-length+1;
  j--;
  for (; j >= lastCol; j--) {
    if (!grid[i][j]) {
      return false;
    }
  }
  return true;
}

bool rightLength(int length, int i, int j) {
  if (j+length-1 > C) {
    return false;
  }
  int lastCol = j+length-1;
  j++;
  for (; j <= lastCol; j++) {
    if (!grid[i][j]) {
      return false;
    }
  }
  return true;
}

int upRightCheck(int i, int j) {
  int total = 0;
  int vertLongCounter = 2;
  while (upLength(vertLongCounter*2, i, j) && rightLength(vertLongCounter, i, j)) {
    total++;
    vertLongCounter++;
  }

  int horiLongCounter = 2;
  while (upLength(horiLongCounter, i, j) && rightLength(horiLongCounter*2, i, j)) {
    total++;
    horiLongCounter++;
  }

  return total;
}

int upLeftCheck(int i, int j) {
  int total = 0;
  int vertLongCounter = 2;
  while (upLength(vertLongCounter*2, i, j) && leftLength(vertLongCounter, i, j)) {
    total++;
    vertLongCounter++;
  }

  int horiLongCounter = 2;
  while (upLength(horiLongCounter, i, j) && leftLength(horiLongCounter*2, i, j)) {
    total++;
    horiLongCounter++;
  }

  return total;
}

int downRightCheck(int i, int j) {
  int total = 0;
  int vertLongCounter = 2;
  while (downLength(vertLongCounter*2, i, j) && rightLength(vertLongCounter, i, j)) {
    total++;
    vertLongCounter++;
  }

  int horiLongCounter = 2;
  while (downLength(horiLongCounter, i, j) && rightLength(horiLongCounter*2, i, j)) {
    total++;
    horiLongCounter++;
  }

  return total;
}

int downLeftCheck(int i, int j) {
  int total = 0;
  int vertLongCounter = 2;
  while (downLength(vertLongCounter*2, i, j) && leftLength(vertLongCounter, i, j)) {
    total++;
    vertLongCounter++;
  }

  int horiLongCounter = 2;
  while (downLength(horiLongCounter, i, j) && leftLength(horiLongCounter*2, i, j)) {
    total++;
    horiLongCounter++;
  }

  return total;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  // -----------------------------
  int T; cin >> T;
  for (int t = 1; t <= T; t++) {

    cin >> R >> C;
    for (int i = 1; i <= R; i++) {
      for (int j = 1; j <= C; j++) {
        int cell; cin >> cell;
        grid[i][j] = cell;
      }
    }

    vector<pair<int, int>> intersections;
    for (int i = 1; i <= R; i++) {
      for (int j = 1; j <= C; j++) {
        if (grid[i][j]) {
          if (grid[i-1][j] && (grid[i][j-1] || grid[i][j+1])) {
            intersections.push_back(make_pair(i, j));
          } else if (grid[i+1][j] && (grid[i][j-1] || grid[i][j+1])) {
            intersections.push_back(make_pair(i, j));
          }
        }
      }
    }

    int total = 0;
   for (pair<int, int> p : intersections) {
     int i = p.first;
     int j = p.second;
     // up-right
     if (grid[i-1][j] && grid[i][j+1]) {
       total += upRightCheck(i, j);
     }
     // up-left
     if (grid[i-1][j] && grid[i][j-1]) {
       total += upLeftCheck(i, j);
     }
     // down-right
     if (grid[i+1][j] && grid[i][j+1]) {
       total += downRightCheck(i, j);
     }
     // down-left
     if (grid[i+1][j] && grid[i][j-1]) {
       total += downLeftCheck(i, j);
     }
   }
    cout << "Case #" << t << ": " << total << '\n';

   // resetting grid
    for (int i = 1; i <= R; i++) {
      for (int j = 1; j <= C; j++) {
        grid[i][j] = 0;
      }
    }
  }
  // -----------------------------
  return 0;
}