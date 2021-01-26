#include <bits/stdc++.h>
using namespace std;

bool backToBeginning(int cows[], int size) {
  for (int i = 1; i < size; i++) {
    if (cows[i] != i) {
      return false;
    }
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  // -----------------------------
  int N, K;
  cin >> N >> K;
  int cows[N+1]; cows[0] = 0;
  for (int i = 1; i <= N; i++) {
    cows[i] = i;
  }
  pair<int, int> moves[K];
  for (int i = 0; i < K; i++) {
    int a, b;
    cin >> a >> b;
    moves[i] = make_pair(a, b);
  }

  set<int> visited[N+1];
  for (int i = 1; i <= N; i++) {
    visited[i].clear();
    visited[i].insert(i);
  }
  bool firstLoop = true;
  while (firstLoop || !backToBeginning(cows, N+1)) {
    firstLoop = false;
    for (int i = 0; i < K; i++) {
      int a = cows[moves[i].first];
      int b = cows[moves[i].second];
      visited[a].insert(moves[i].second);
      visited[b].insert(moves[i].first);
      cows[moves[i].first] = b;
      cows[moves[i].second] = a;
    }
  }
  for (int i = 1; i <= N; i++) {
    cout << visited[i].size() << '\n';
  }
  // -----------------------------
  return 0;
}