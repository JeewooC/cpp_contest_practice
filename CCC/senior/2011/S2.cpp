#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  // -----------------------------
  int N; cin >> N;
  char s[N], a[N];
  for (int i = 0; i < N; i++) {
    char c; cin >> c;
    s[i] = c;
  }
  for (int i = 0; i < N; i++) {
    char c; cin >> c;
    a[i] = c;
  }
  int count = 0;
  for (int i = 0; i < N; i++) {
    if (s[i] == a[i]) count++;
  }
  cout << count << '\n';
  // -----------------------------
  return 0;
}