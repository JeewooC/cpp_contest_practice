#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  // -----------------------------
  int qType, N;
  cin >> qType >> N;
  vector<int> dmoj, peg;
  for (int i = 0; i < N; i++) {
    int speed; cin >> speed;
    dmoj.push_back(speed);
  }
  for (int i = 0; i < N; i++) {
    int speed; cin >> speed;
    peg.push_back(speed);
  }

  sort(dmoj.begin(), dmoj.end());
  if (qType == 1) {
    sort(peg.begin(), peg.end());
  } else {
    sort(peg.begin(), peg.end(), greater<int>());
  }

  int total = 0;
  for (int i = 0; i < N; i++) {
    total += max(dmoj.at(i), peg.at(i));
  }
  cout << total << '\n';
  // -----------------------------
  return 0;
}