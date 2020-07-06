#include <bits/stdc++.h>
using namespace std;

int main() {
  int T; cin >> T;
  for (int t = 0; t < T; t++) {
    int N; cin >> N;
    int min = INT_MAX;
    for (int i = 0; i < N; i++) {
      int A; cin >> A;
      if (A < min) {
        min = A;
      }
    }
    cout << min << endl;
  }
}