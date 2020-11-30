#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  // -----------------------------
  string first, second;
  cin >> first >> second;

  int fFreq[26] = {0};
  for (int i = 0; i < first.size(); i++) {
    fFreq[first[i] - 97]++;
  }

  int asteriskCount = 0;
  for (int i = 0; i < second.size(); i++) {
    if (second[i] == '*') {
      asteriskCount++;
    } else {
      fFreq[second[i] - 97]--;
    }
  }

  bool cond = true;
  for (int i = 0; i < 26; i++) {
    if (fFreq[i] < 0) {
      cond = false;
      break;
    } else if (fFreq[i] > 0) {
      asteriskCount -= fFreq[i];
    }
  }
  if (asteriskCount != 0) cond = false;

  if (cond) {
    cout << "A\n";
  } else {
    cout << "N\n";
  }
  // -----------------------------
  return 0;
}