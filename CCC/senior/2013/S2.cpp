#include <bits/stdc++.h>
using namespace std;

int W, N;

int main() {
  ios_base::sync_with_stdio(false);
  cin >> W >> N;
  vector<int> trains;
  trains.push_back(-1);
  for (int i = 0; i < N; i++) {
    int w; cin >> w;
    trains.push_back(w);
  }
  int bridgeWeight = 0;
  for (int i = 1; i <= N; i++) {
    if (i <= 4) {
      bridgeWeight += trains.at(i);
      if (bridgeWeight > W) {
        cout << i-1 << '\n';
        return 0;
      }
    } else {
      bridgeWeight += trains.at(i);
      bridgeWeight -= trains.at(i-4);
      if (bridgeWeight > W) {
        cout << i-1 << '\n';
        return 0;
      }
    }
  }
  cout << N << '\n';

  return 0;
}