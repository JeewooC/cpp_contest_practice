#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  // -----------------------------
  int T; cin >> T;
  for (int t = 1; t <= T; t++) {
    int N, K;
    string S;
    cin >> N >> K >> S;

    int counter = 0;
    for (int i = 0; i < N/2; i++) {
      if (S[i] != S[N-i-1]) {
        counter++;
      }
    }

    cout << "Case #" << t << ": " << abs(K-counter) << '\n';
  }
  // -----------------------------
  return 0;
}