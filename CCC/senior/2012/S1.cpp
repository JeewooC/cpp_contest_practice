#include <bits/stdc++.h>
using namespace std;

int modifiedFactorial(int n, int r) {
  if (n > r) {
    return n * modifiedFactorial(n-1, r);
  } else {
    return 1;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  int J; cin >> J;
  cout << modifiedFactorial(J-1, J-4) / 6 << '\n';
  return 0;
}