#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  int T; cin >> T;
  for (int t = 0; t < T; t++) {
    int N, K;
    string s;
    cin >> N >> K >> s;

    int capitalCount = 0, smallCount = 0;
    for (char c : s) {
      if (c >= 'a' && c <= 'z') {
        smallCount++;
      } else {
        capitalCount++;
      }
    }

    if (capitalCount <= K && smallCount <= K) {
      cout << "both" << '\n';
    } else if (capitalCount <= K) {
      cout << "chef" << '\n';
    } else if (smallCount <= K) {
      cout << "brother" << '\n';
    } else {
      cout << "none" << '\n';
    }
  }
  return 0;
}