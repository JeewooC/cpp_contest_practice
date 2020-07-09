#include <bits/stdc++.h>
using namespace std;

int main() {
  int T; cin >> T;
  for (int t = 0; t < T; t++) {
    int N, K;
    cin >> N >> K;
    vector<int> scores;
    for (int i = 0; i < N; i++) {
      int temp; cin >> temp;
      scores.push_back(temp);
    }
    sort(scores.begin(), scores.end(), greater<>());

    int count = 0;
    for (int i = 0; i < N; i++) {
      if (scores.at(i) < scores.at(K-1)) {
        break;
      } else {
        count++;
      }
    }
    cout << count << endl;
  }
}