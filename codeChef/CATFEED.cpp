#include <bits/stdc++.h>
using namespace std;

bool innerLoop(int N, int M, vector<int> order) {
  set<int> feeding;
  for (int j = 1; j <= M; j++) {
    if (feeding.find(order.at(j-1)) != feeding.end()) {
      return false;
    }
    feeding.insert(order.at(j-1));
    if (j % N == 0) {
      feeding.clear();
    }
  }
  return true;
}

int main() {
  int T; cin >> T;
  for (int i = 0; i < T; i++) {
    int N, M;
    cin >> N >> M;
    vector<int> order;
    for (int l = 0; l < M; l++) {
      int A;
      cin >> A;
      order.push_back(A);
    }
    if (innerLoop(N, M, order)) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}
