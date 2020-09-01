#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  int N; cin >> N;
  int sums[4001] = {0};
  int woods[N];

  for (int i = 0; i < N; i++) {
    int temp; cin >> temp;
    woods[i] = temp;
  }

  int maxSum = 0; // keeping track of the largest sum (no need to check all 4000 later)
  for (int i = 0; i < N; i++) {
    for (int j = i+1; j < N; j++) {
      int sum = woods[i] + woods[j];
      sums[sum]++;
      if (sum > maxSum) {
        maxSum = sum;
      }
    }
  }

  int maxLength = 0, combinations = 0;
  for (int i = 2; i < maxSum+1; i++) {
    if (sums[i] > maxLength) {
      maxLength = sums[i];
      combinations = 1;
    } else if (sums[i] == maxLength) {
      combinations++;
    }
  }

  cout << maxLength << " " << combinations << '\n';
}