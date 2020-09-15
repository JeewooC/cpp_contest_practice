#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  int T; cin >> T;
  for (int t = 0; t < T; t++) {
    int A, B, C;
    cin >> A >> B >> C;
    if (A + B + C == 180) {
      cout << "YES" << '\n';
    } else {
      cout << "NO" << '\n';
    }
  }
  return 0;
}