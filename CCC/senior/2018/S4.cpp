#include <bits/stdc++.h>
using namespace std;

typedef long long lli;
map<lli, lli> dp;

lli balancedTree(int N) {
  if (N == 1 || N == 2) {
    return 1;
  } else if (dp.count(N)) {
    return dp[N];
  } else {
    lli answer = 0;
    int itr = N;

    while (itr >= 2) {
      int weight = N / itr;
      int nextNode = N / (weight+1);
      answer += (itr-nextNode) * balancedTree(weight);
      itr = nextNode;
    }
    dp[N] = answer;
    return dp[N];
  }

}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  // -----------------------------
  int N; cin >> N;
  lli balancedTrees = balancedTree(N);
  cout << balancedTrees << '\n';
  // -----------------------------
  return 0;
}