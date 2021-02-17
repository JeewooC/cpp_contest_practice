#include <bits/stdc++.h>
using namespace std;
typedef long long lld;

bool isInBounds(int pos, int leftBound, int rightBound) {
  if (pos >= leftBound && pos <= rightBound) {
    return true;
  } else {
    return false;
  }
}

lld getMoveTime(lld P, int W, int D, int c) {
  if (isInBounds(c, P-D, P+D)) {
    return 0;
  } else if (P < c) {
    return W * (c - (P+D));
  } else if (P > c) {
    return W * ((P-D) - c);
  }
}

lld getTotalMoveTime(map<lld, pair<int, int>> positions, int c) {
  lld total = 0;
  for (auto itr = positions.begin(); itr != positions.end(); itr++) {
    lld P = itr->first;
    int W = (itr->second).first;
    int D = (itr->second).second;

    total += getMoveTime(P, W, D, c);
  }
  return total;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  // -----------------------------
  int N; cin >> N;
  map<lld, pair<int, int>> positions;
  lld optimalPos = 0;
  for (int i = 0; i < N; i++) {
    lld P;
    int W, D;
    cin >> P >> W >> D;
    positions[P] = make_pair(W, D);

    optimalPos += P;
  }

  if (N == 1) {
    cout << 0 << '\n';
    return 0;
  }

//  optimalPos /= N;
//  lld optimalTimes[200001] = {0};
//  optimalTimes[optimalPos] = getTotalMoveTime(positions, optimalPos);
//  optimalTimes[optimalPos-1] = getTotalMoveTime(positions, optimalPos-1);
//  optimalTimes[optimalPos+1] = getTotalMoveTime(positions, optimalPos+1);
//  int idx = optimalPos;
//  bool direction = true; // true is right, false is left
//  while (true) {
//    if (!direction) {
//      if (optimalTimes[idx+1] > optimalTimes[idx]) {
//        idx--;
//        if (optimalTimes[idx] == 0) {
//          optimalTimes[idx] = getTotalMoveTime(positions, idx);
//        }
//      } else {
//        idx++;
//        direction = !direction;
//        if (optimalTimes[idx] == 0) {
//          optimalTimes[idx] = getTotalMoveTime(positions, idx);
//        }
//      }
//    } else {
//      if (optimalTimes[idx-1] > optimalTimes[idx]) {
//        idx++;
//        if (optimalTimes[idx] == 0) {
//          optimalTimes[idx] = getTotalMoveTime(positions, idx);
//        }
//      } else {
//        idx --;
//        direction = !direction;
//        if (optimalTimes[idx] == 0) {
//          optimalTimes[idx] = getTotalMoveTime(positions, idx);
//        }
//      }
//    }
//
//    if (optimalTimes[idx-1] >= optimalTimes[idx] && optimalTimes[idx+1] >= optimalTimes[idx]) {
//      optimalPos = idx;
//      break;
//    }
//  }

  lld optimalTime = INT_MAX;
  for (int i = 0; i <= (positions.rbegin()->first + positions.rbegin()->second.second); i++) {
    lld currentMoves = getTotalMoveTime(positions, i);
    if (currentMoves < optimalTime) {
      optimalTime = currentMoves;
    }
  }

  cout << optimalTime << '\n';
  // -----------------------------
  return 0;
}