#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  int N; cin >> N;
  long woods[2002] = {0};
  for (int i = 0;i < N; i++) {
    long temp; cin >> temp;
    woods[temp]++;
  }

  long sums[4004] = {0};
  for (int i = 1; i < 2001; i++) {
    if (woods[i] > 0) {
      for (int j = i; j < 2001; j++) {
        if (j == i) {
          // divide by two because if there is only one piece then it wouldn't add anything
          // but if there are more than one pieces, it would add the appropriate number of pairs
          sums[i*2] += woods[i] / 2;
        } else if (woods[j] > 0) {
          // add the minimum of these two because the less of the two is how many pairs
          // of these two lengths can be made
          sums[i+j] += min(woods[i], woods[j]);
        }
      }
    }
  }

  long maxLength = 0, combinations = 0;
  for (int i = 2; i < 4001; i++) {
    if (sums[i] > maxLength) {
      maxLength = sums[i];
      combinations = 1;
    } else if (sums[i] == maxLength) {
      combinations++;
    }
  }

  cout << maxLength << ' ' << combinations << '\n';
}