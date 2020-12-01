#include <bits/stdc++.h>
using namespace std;

bool isCrystal(int mCurrent, int m, int x, int y) {
  int oneBaseX = (int) (x / pow(5, mCurrent-1));
  int oneBaseY = (int) (y / pow(5, mCurrent-1));

  if ((oneBaseX >= 1 && oneBaseX <= 3 && oneBaseY == 0) || (oneBaseX == 2 && oneBaseY == 1)) {
    // in the tetris shape
    return true;
  } else if (mCurrent == 1) {
    // not in tetris shape and is final magnification
    return false;
  } else if (oneBaseX == 1 && oneBaseY == 1) {
    // left crown
    return isCrystal(mCurrent-1, m, x-pow(5, mCurrent-1), y-pow(5, mCurrent-1));
  } else if (oneBaseX == 2 && oneBaseY == 2) {
    // top crown
    return isCrystal(mCurrent-1, m, x-2*pow(5, mCurrent-1), y-2*pow(5, mCurrent-1));
  } else if (oneBaseX == 3 && oneBaseY == 1) {
    // right crown
    return isCrystal(mCurrent-1, m, x-3*pow(5, mCurrent-1), y-pow(5, mCurrent-1));
  } else {
    // irrelevant
    return false;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  // -----------------------------
  int T; cin >> T;
  while (T-- > 0) {
    int m, x, y;
    cin >> m >> x >> y;
    if (isCrystal(m, m, x, y)) {
      cout << "crystal" << '\n';
    } else {
      cout << "empty" << '\n';
    }
  }
  // -----------------------------
  return 0;
}