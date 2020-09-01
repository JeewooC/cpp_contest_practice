#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  int T; cin >> T;
  for (int i = 0; i < T; i++) {
    int n; cin >> n;
    int count = 0;
    while (n > 0) {
      if (n % 10 == 4) count++;
      n /= 10;
    }
    cout << count << endl;
  }
}