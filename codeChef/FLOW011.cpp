#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  int T; cin >> T;
  for (int t = 0; t < T; t++) {
    double base; cin >> base;
    if (base < 1500) {
      base += (0.1 * base) + (0.9 * base);
    } else {
      base += 500 + (0.98 * base);
    }
    cout << fixed << setprecision(2) << base << '\n';
  }
  return 0;
}