#include <bits/stdc++.h>
using namespace std;

int main() {
  int T; cin >> T;
  for (int t = 0; t < T; t++) {
    int N; cin >> N;
    long arr[N];
    for (int i = 0; i < N; i++) {
      long temp; cin >> temp;
      arr[i] = temp;
    }
    long total = 0;
    for (int i = 0; i < N-1; i++) {
      if (arr[i] != arr[i+1]) {
        total += abs(arr[i] - arr[i+1]) - 1;
      }
    }
    cout << total << endl;
  }
}