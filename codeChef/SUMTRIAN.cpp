#include <bits/stdc++.h>
using namespace std;

//int dfs(int row, int col, vector<int> arr[], int N) {
//  if (row + 1 == N) {
//    return arr[row].at(col);
//  }
//  return max(
//      arr[row].at(col) + dfs(row+1, col, arr, N),
//      arr[row].at(col) + dfs(row+1, col+1, arr, N)
//      );
//}
//
//int main() {
//  int T; cin >> T;
//  for (int t = 0; t < T; t++) {
//    int N; cin >> N;
//    vector<int> arr[N];
//    for (int i = 0; i < N; i++) {
//      vector<int> inner;
//      for (int j = 1; j <= i+1; j++) {
//        int temp; cin >> temp;
//        inner.push_back(temp);
//      }
//      arr[i] = inner;
//    }
//    cout << dfs(0, 0, arr, N) << endl;
//  }
//}

// too many possibilities. no need to test all of them (not necessary either)
// solution 2

int main() {
  int T; cin >> T;
  for (int t = 0; t < T; t++) {
    int N; cin >> N;
    int arr[N][N];
    int dp[N][N]; // contains the maximum value in each spot
    for (int i = 0; i < N; i++) { // filling dp with 0 so that we can compare with new value to store the max value
      for (int j = 0; j < i+1; j++) {
        int temp; cin >> temp;
        arr[i][j] = temp;
        dp[i][j] = 0;
      }
    }

    dp[0][0] = arr[0][0];
    for (int i = 1; i < N; i++) {
      for (int j = 0; j < i+1; j++) {
        if (j == 0) { // if it is the leftmost element in that row, it can only come from the element right above
          dp[i][j] = dp[i-1][j] + arr[i][j];
        } else if (j == i) { // if it is the rightmost element in that row, it can only come from the element above and left
          dp[i][j] = dp[i-1][j-1] + arr[i][j];
        } else {
          dp[i][j] = max(
              dp[i-1][j] + arr[i][j],
              dp[i-1][j-1] + arr[i][j]
              );
        }
      }
    }

    int max = 0;
    for (int i = 0; i < N; i++) {
      if (dp[N-1][i] > max) {
        max = dp[N-1][i];
      }
    }
    cout << max << endl;
  }
}