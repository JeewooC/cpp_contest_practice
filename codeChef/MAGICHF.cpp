#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  int T; cin >> T;
  while (T-- > 0) {
    int N, X, S;
    cin >> N >> X >> S;
    for (int s = 0; s < S; s++) {
      int A, B;
      cin >> A >> B;
      if (A == X) {
        X = B;
      } else if (B == X) {
        X = A;
      }
    }
    cout << X << '\n';
  }
  return 0;
}