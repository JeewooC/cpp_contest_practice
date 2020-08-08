#include <bits/stdc++.h>
using namespace std;

int main() {
  int T; cin >> T;
  for (int t = 0; t < T; t++) {
    int N; cin >> N;
    long multiple = 1;
    for (int i = 0; i < N; i++) {
      int A; cin >> A;
      multiple *= A;
    }
    if (multiple % 2 == 0) {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
    }
  }
}