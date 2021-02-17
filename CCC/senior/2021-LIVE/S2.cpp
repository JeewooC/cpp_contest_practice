#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  // -----------------------------
  int M, N, K;
  cin >> M >> N >> K;
  bool isGold[M][N];
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      isGold[i][j] = false;
    }
  }


  for (int k = 0; k < K; k++) {
    char c;
    int idx;
    cin >> c >> idx;

    idx--;
    if (c == 'R') {
      for (int i = 0; i < N; i++) {
        isGold[idx][i] = !isGold[idx][i];
      }
    } else if (c == 'C') {
      for (int i = 0; i < M; i++) {
        isGold[i][idx] = !isGold[i][idx];
      }
    } else {
      cout << "ERROR: unidentified selector" << '\n';
    }
  }

  int total = 0;
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      if (isGold[i][j]) {
        total++;
      }
    }
  }
  cout << total << '\n';
  // -----------------------------
  return 0;
}