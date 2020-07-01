#include <bits/stdc++.h>

#define maxn 100000
#define mod 1000000007
using namespace std;

double dp[maxn];
long ans[maxn];
priority_queue<pair<double, int>> pq;

int main() {
    int N, K;
    cin >> N >> K;
    int specialNumbers[N];
    for (int i = 0; i < N; i++) {
      cin >> specialNumbers[i];
    }

    dp[0] = log(specialNumbers[0]);
    ans[0] = specialNumbers[0];
    pq.push(make_pair(-dp[0], 0));

    for (int i = 1; i < N; i++) {
      while (i - pq.top().second > K) {
        pq.pop();
      }
      dp[i] = dp[pq.top().second] + log(specialNumbers[i]);
      ans[i] = (ans[pq.top().second] * 1LL * specialNumbers[i]) % mod;
      pq.push(make_pair(-dp[i], i));
    }

    cout << ans[N-1] << endl;
}
