#include <bits/stdc++.h>
using namespace std;

int main() {
  int T; cin >> T;
  for (int t = 0; t < T; t++) {
    int arr[10] = {};
    int N; cin >> N;
    for (int i = 0; i < N; i++) {
      string s; cin >> s;
      for (int j = 0; j < 10; j++) {
        if (s.at(j) == '1') {
          arr[j]++;
        }
      }
    }
    int total = 0;
    for (int i = 0; i < 10; i++) {
      if (arr[i] != 0 && arr[i] % 2 == 1) {
        total++;
      }
    }
    cout << total << endl;
  }
}