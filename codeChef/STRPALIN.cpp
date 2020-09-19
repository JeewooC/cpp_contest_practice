#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  int T; cin >> T;
  while (T-- > 0) {
    string A, B;
    cin >> A >> B;
    int aCharCount[26] = {0};
    int bCharCount[26] = {0};
    for (char a : A) {
      aCharCount[a - 'a']++;
    }
    for (char b : B) {
      bCharCount[b - 'a']++;
    }

    bool cond = false;
    for (int i = 0; i < 26; i++) {
      if (aCharCount[i] > 0 && bCharCount[i] > 0) {
        cond = true;
        break;
      }
    }
    if (cond) {
      cout << "Yes" << '\n';
    } else {
      cout << "No" << '\n';
    }
  }
  return 0;
}