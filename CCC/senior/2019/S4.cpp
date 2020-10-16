#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000010;
int n;
int leafs[MAXN] = {0};
long long dp[MAXN][MAXN] = {0}; // row is number of days, col is each attraction, and value is maximum score
int tree[4*MAXN] = {0};

void build (int node, int start, int end) {
  if (start == end) {
    tree[node] = leafs[start];
  } else {
    int mid = (start + end) / 2;
    build(2*node, start, mid);
    build(2*node+1, mid+1, end);
    tree[node] = max(tree[2*node], tree[2*node+1]);
  }
}

int rmq(int node, int start, int end, int lBound, int rBound) {
  if (lBound <= start && rBound >= end) {
    return tree[node];
  }
  if (lBound > end || rBound < start) {
    return INT_MIN;
  }
  int mid = (start + end) / 2;
  int leftVal = rmq(2*node, start, mid, lBound, rBound);
  int rightVal = rmq(2*node+1, mid+1, end, lBound, rBound);
  return max(leftVal, rightVal);
}


int main() {
  ios_base::sync_with_stdio(false);

  // initiate leafs and n here
  int K;
  cin >> n >> K;
  for (int i = 0; i < n; i++) {
    int a; cin >> a;
    leafs[i] = a;
  }
  build(1, 0, n-1);

  int days = (n-1) / K + 1;
  if (n % K == 0) {
    int score = 0;
    for (int i = 0; i < days; i++) {
      int x = rmq(1, 0, n-1, i * K, K * (i+1) - 1);
      score += x;
    }
    cout << score << '\n';
  } else {
    for (int i = 0; i < n; i++) {
      for (int d = i / K + 1; d <= days; d++) {
        if (d > i+1) break;
        if (d == 1) {
          dp[1][i] = rmq(1, 0, n-1, 0, K-1);
        } else {

          // if

          dp[d][i] = max(
              dp[d-1][i-1] + rmq(1, 0, n-1, i, K * (i+1) - 1),

              )
        }
      }
    }
  }

  return 0;
}