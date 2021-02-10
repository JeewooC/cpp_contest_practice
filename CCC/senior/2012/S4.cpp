#include <bits/stdc++.h>
using namespace std;

bool isGoalLineup(vector<int> lineup) {
  for (int i = 1; i < lineup.size(); i++) {
    if (lineup[i] - 1 != lineup[i-1]) {
      return false;
    }
  }
  return true;
}

int solve(int n, vector<int> lineup) {
  if (isGoalLineup(lineup)) {
    return 0;
  } else {
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  // -----------------------------
  int n; cin >> n;
  while (n != 0) {
    vector<int> lineup;
    for (int i = 0; i < n; i++) {
      int coin; cin >> coin;
      lineup.push_back(coin);
    }
    int moves = solve(n, lineup);
    if (moves == -1) {
      cout << "IMPOSSIBLE" << '\n';
    } else {
      cout << moves << '\n';
    }

    cin >> n;
  }
  // -----------------------------
  return 0;
}