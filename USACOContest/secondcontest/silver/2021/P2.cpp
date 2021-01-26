#include <bits/stdc++.h>
using namespace std;

int dp[100001][100001] = {0};
bool visited[100001][100001] = {false};
string s;

void paint(int a, int b) {
  if (!visited[a][b]) {
    if (a == 0) {
      paint(0, b-1);
      visited[a][b] = true;

    } else {

    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  // -----------------------------
  int N, Q;
  cin >> N >> Q >> s;
  for (int i = 0; i <= N; i++) {
    dp[i][i] = 1;
    visited[i][i] = true;
  }

  for (int i = 0; i < Q; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    if (a == 0) {
      paint(b+1, N-1);
      cout << dp[b+1][N-1] << '\n';
    } else if (b == N-1) {
      paint(0, a-1);
      cout << dp[0][a-1] << '\n';
    } else {
      paint(0, a-1);
      paint(b+1, N-1);
      cout << dp[0][a-1] + dp[b+1][N-1] << '\n';
    }
  }
  // -----------------------------
  return 0;
}