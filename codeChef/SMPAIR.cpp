#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  int T; cin >> T;
  for (int t = 0; t < T; t++) {
    int N; cin >> N;
    int smallest = INT_MAX, second = INT_MAX;
    for (int i = 0; i < N; i++) {
      int a; cin >> a;
      if (a < second) {
        if (a < smallest) {
          second = smallest;
          smallest = a;
        } else {
          second = a;
        }
      }
    }
    cout << smallest + second << '\n';
  }
  return 0;
}