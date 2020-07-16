#include <bits/stdc++.h>
using namespace std;

int innerLoop() {
  int N, M;
  cin >> N >> M;
  int profits[N];
  int weights[N];
  for (int i = 0; i < N; i++) {
    int temp; cin >> temp;
    profits[i] = temp;
  }
  for (int i = 0; i < N; i++) {
    int temp; cin >> temp;
    weights[i] = temp;
  }

  int dp[N+1][M+1];
  for (int i = 0; i <= N; i++) {
    for (int w = 0; w <= M; w++) {
      if (i == 0 || w == 0) {
        dp[i][w] = 0;
      } else if (weights[i-1] <= w) {
        dp[i][w] = max(
            profits[i-1] + dp[i-1][w-weights[i-1]],
            dp[i-1][w]
            );
      } else {
        dp[i][w] = dp[i-1][w];
      }
    }
  }
  return dp[N][M];
}

int main() {
  int T; cin >> T;
  for (int t = 0; t < T; t++) {
    cout << innerLoop() << endl;
  }
}