#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  // store substitution rules as a pair in an array
  pair<string, string> subRules[3];
  for (int i = 0; i < 3; i++) {
    string A, B;
    cin >> A >> B;
    subRules[i] = make_pair(A, B);
  }

  int S;
  string I, F;
  cin >> S >> I >> F;

  int currentIndex = 0;
  while (S > 0) {
    // if the current index is out of bounds, restart from the beginning
    if (currentIndex >= I.size()) {
      currentIndex = 0;
    }
    // if there is a substitution rule that applies to this particular index, find which rule number it is
    // if there isn't, move forward one index
    int ruleNumber;
    if (currentIndex + subRules[0].first.size() <= I.size() &&
        I.substr(currentIndex, subRules[0].first.size()) == subRules[0].first) {
      ruleNumber = 0;
    } else if (currentIndex + subRules[1].first.size() <= I.size() &&
        I.substr(currentIndex, subRules[1].first.size()) == subRules[1].first) {
      ruleNumber = 1;
    } else if (currentIndex + subRules[2].first.size() <= I.size() &&
        I.substr(currentIndex, subRules[2].first.size()) == subRules[2].first) {
      ruleNumber = 2;
    } else {
      currentIndex++;
      continue;
    }
    I = I.substr(0, currentIndex) +
        subRules[ruleNumber].second +
        I.substr(currentIndex + subRules[ruleNumber].first.size());

    cout << ruleNumber+1 << ' ' << currentIndex+1 << ' ' << I << '\n';

    currentIndex += subRules[ruleNumber].second.size();
    S--;
  }
  return 0;
}