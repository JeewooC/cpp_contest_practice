#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  int T; cin >> T;
  for (int t = 0; t < T; t++) {
    int N; cin >> N;
    int max = 0;
    int arr[N];

    for (int i = 0; i < N; i++) {
      int temp; cin >> temp;
      arr[i] = temp;
      if (temp > max) {
        max = temp;
      }
    }

    int GCD = 1;
    for (int i = 2; i <= max; i++) {
      bool cond = true;
      for (int j = 0; j < N; j++) {
        if (arr[j] % i != 0) {
          cond = false;
          break;
        }
      }

      if (cond) {
        GCD = i;
      }
    }

    for (int i = 0; i < N; i++) {
      cout << arr[i]/GCD << " ";
    }
    cout << '\n';
  }
  return 0;
}