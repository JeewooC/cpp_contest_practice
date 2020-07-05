#include <bits/stdc++.h>
using namespace std;

int main() {
  int T; cin >> T;
  for (int i = 0; i < T; i++) {
    int N, K;
    cin >> N >> K;
    for (int a = N-K; a <= N; a++) {
      cout << a << " ";
    }
    for (int b = 1; b < N-K; b++) {
      cout << b;
      if (b != N-K-1) {
        cout << " ";
      }
    }
    cout << endl;
  }
}