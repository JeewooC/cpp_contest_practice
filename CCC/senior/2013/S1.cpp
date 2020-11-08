#include <bits/stdc++.h>
using namespace std;

bool isDistinct(int n) {
  int digitCount = 0;
  set<int> digits;
  while (n > 0) {
    digits.insert(n%10);
    n /= 10;
    digitCount++;
  }
  return digits.size() == digitCount;
}

int main() {
  ios_base::sync_with_stdio(false);
  int Y; cin >> Y;
  Y++;

  if (Y <= 10) {
    cout << Y << '\n';
  } else if (Y >= 9900) {
    cout << 10234 << '\n';
  } else {
    while (!isDistinct(Y)) {
      Y++;
    }
    cout << Y << '\n';
  }

  return 0;
}