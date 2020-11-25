#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  // -----------------------------
  int M, N;
  cin >> M >> N;
  int grid[M+1][N+1];
  for (int r = 1; r <= M; r++) {
    for (int c = 1; c <= N; c++) {
      int val; cin >> val;
      grid[r][c] = val;
    }
  }

  bool cond = false;
  bool check[1000001] = {false};
  queue<int> q; q.push(grid[1][1]);
  while (!q.empty()) {
    int x = q.front(); q.pop();
    // check if x has been used already
    if (check[x]) {
      continue;
    }
    check[x] = true;

    // check if this goes straight to the end
    if (x == M*N) {
      cond = true;
      break;
    }

    for (int r = 1; r <= x/2 && r <= M; r++) {
      // check if r is a factor of x
      if (x % r == 0) {
        int c = x / r;
        // check if c is in range
        if (c <= N) {
          q.push(grid[r][c]);
        }
        // checking if the inverse (c, r) works as well
        if (c <= M && r <= N) {
          q.push(grid[c][r]);
        }
      }
    }
  }

  if (cond) {
    cout << "yes" << '\n';
  } else {
    cout << "no" << '\n';
  }
  // -----------------------------
  return 0;
}



// start at 1, 1
// instead of finding all factors of x (which is less than or equal to 1 000 000)
// loop through all rows (less than or equal to 1 000) that are less than or equal to x/2
// if the row is a factor of x (x % row == 0), check if the the column (x / row) is not index out of range



// if x is the product of M and N then it can go to final destination