#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);

  int T; cin >> T;
  cin.ignore();
  for (int t = 0; t < T; t++) {
    vector<int> box;

    string S, N;
    getline(cin, S);
    stringstream ss(S);
    while (getline(ss, N, ' ')) {
      box.push_back(stoi(N));
    }

    box.erase(find(box.begin(), box.end(), box.size()-1));
    int max = INT_MIN;
    for (auto it = box.begin(); it != box.end(); it++) {
      if (*it > max) {
        max = *it;
      }
    }
    cout << max << '\n';
  }
  return 0;
}