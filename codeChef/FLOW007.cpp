#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  int T; cin >> T;
  while (T-- > 0) {
    int N; cin >> N;
    int reversedN = 0;
    while (N > 0) {
      reversedN += N%10;
      reversedN *= 10;
      N /= 10;
    }
    cout << reversedN/10 << '\n';
  }
  return 0;
}