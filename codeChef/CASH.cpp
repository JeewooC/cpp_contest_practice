#include <bits/stdc++.h>
using namespace std;

int main() {
  int T; cin >> T;
  for (int t = 0; t < T; t++) {
    int N, K;
    cin >> N >> K;
    long total = 0;
    for (int i = 0; i < N; i++) {
      int temp; cin >> temp;
      total += temp;
    }
    cout << total % K << endl;
  }
}