#include <bits/stdc++.h>
using namespace std;

int main() {
  int T; cin >> T;
  for (int t = 0; t < T; t++) {
    int N; cin >> N;
    int maxProfit = -1;
    for (int i = 0; i < N; i++) {
      int S, P, V;
      cin >> S >> P >> V;
      int profit = (P / (S+1)) * V;
      if (profit > maxProfit) {
        maxProfit = profit;
      }
    }
    cout << maxProfit << endl;
  }
}