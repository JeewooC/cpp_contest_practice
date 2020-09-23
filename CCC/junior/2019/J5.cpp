#include <bits/stdc++.h>
using namespace std;

struct Step {
  int R, P;
  string W;

  Step(int r, int p, string w) {
    R = r;
    P = p;
    W = w;
  }
};

void dfs(int S, string I, string F, vector<Step> steps, pair<string, string> subRules[3], set<pair<int, string>> &memo) {
  if (S == 0 && I == F) {
    for (Step s : steps) {
      cout << s.R << ' ' << s.P << ' ' << s.W << '\n';
    }
    exit(0);
  }

  if (S == 0) {
    return;
  } else {
      if (memo.find(make_pair(S, I)) != memo.end()) {
        return;
      }
      memo.insert(make_pair(S, I));
      for (int i = 0; i < 3; i++) {
        int searchIndex = 0;
        while (searchIndex < I.size() && I.substr(searchIndex).find(subRules[i].first) != string::npos) {
          if (searchIndex != 0) {
            S--;
          }

          int index = I.substr(searchIndex).find(subRules[i].first);
          string modified = I.substr(0, index) + subRules[i].second + I.substr(index+subRules[i].first.size());
          steps.push_back(Step(i+1, index+1, modified));
          dfs(S-1, modified, F, steps, subRules, memo);
          steps.pop_back();
          searchIndex = index+subRules[i].second.size();
        }
      }
    }
  }

int main() {
  ios_base::sync_with_stdio(false);

  pair<string, string> subRules[3];
  for (int i = 0; i < 3; i++) {
    string A, B;
    cin >> A >> B;
    subRules[i] = make_pair(A, B);
  }

  int S;
  string I, F;
  cin >> S >> I >> F;
  vector<Step> steps;
  set<pair<int, string>> memo;

  dfs(S, I, F, steps, subRules, memo);
  return 0;
}

