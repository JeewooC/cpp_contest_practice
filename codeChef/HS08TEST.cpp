#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  int X;
  double Y;
  cin >> X >> Y;

  cout << fixed << setprecision(2);
  if (X % 5 == 0 && X+0.5 <= Y) {
    cout << Y-X-0.5 << '\n';
  } else {
    cout << Y << '\n';
  }
  return 0;
}