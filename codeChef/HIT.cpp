#include <bits/stdc++.h>
using namespace std;

void innerLoop() {
  int N; cin >> N;
  vector<int> scores;
  for (int i = 0; i < N; i++) {
    int temp; cin >> temp;
    scores.push_back(temp);
  }
  sort(scores.begin(), scores.end());
  vector<int> thresholds;
  int studentsPerBracket = N/4;
  for (int i = 1; i <= N-1; i++) {
    int currentIndex = i-1;

    if (i%studentsPerBracket==0) {
      if (scores.at(currentIndex+1) == scores.at(currentIndex)) {
        cout << -1 << endl;
        return;
      } else {
        thresholds.push_back(scores.at(currentIndex+1));
      }
    }

  }
  for (int i = 0; i < 3; i++) {
    cout << thresholds.at(i) << " ";
  }
  cout << endl;
}

int main() {
  int T; cin >> T;
  for (int t = 0; t < T; t++) {
    innerLoop();
  }
}