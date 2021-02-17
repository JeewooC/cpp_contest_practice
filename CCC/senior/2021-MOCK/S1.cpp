#include <bits/stdc++.h>
using namespace std;

bool isVowel(char c) {
  if (
      c == 'a' ||
      c == 'e' ||
      c == 'i' ||
      c == 'o' ||
      c == 'u') {
    return true;
  } else {
    return false;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  // -----------------------------
  int N, C, V;
  cin >> N >> C >> V;
  string s; cin >> s;

  int cCtr = 0, vCtr = 0;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == 'y') {
      vCtr++;
      cCtr++;
    } else if (isVowel(s[i])) {
      vCtr++;
      cCtr = 0;
    } else {
      cCtr++;
      vCtr = 0;
    }

    // checking if over constraint
    if (cCtr > C || vCtr > V) {
      cout << "NO" << '\n';
      return 0;
    }
  }
  cout << "YES" << '\n';
  // -----------------------------
  return 0;
}