#include <bits/stdc++.h>
using namespace std;

int N;
string s;

int paintInRange(int a, int b) {
  string s1 = s.substr(a, (b-a+1));
  priority_queue<char, vector<char>, greater<char>> pq;
  set<char> containing;
  int count = 1;
  pq.push(s1[0]);
  containing.insert(s1[0]);
  for (int i = 1; i < s1.size(); i++) {
    if (s1[i] == s1[i-1]) {
      continue;
    }
    if (containing.find(s1[i]) != containing.end()) {
      if (s1[i] == pq.top()) {
        count++;
      }
    } else {
      pq.push(s1[i]);
      containing.insert(s1[i]);
      count++;
    }
  }
  return count;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  // -----------------------------
  int Q;
  cin >> N >> Q >> s;

  for (int i = 0; i < Q; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    if (a == 0) {
      cout << paintInRange(b+1, N-1) << '\n';
    } else if (b == N-1) {
      cout << paintInRange(0, a-1) << '\n';
    } else {
      cout << paintInRange(0, a-1) + paintInRange(b+1, N-1) << '\n';
    }
  }
  // -----------------------------
  return 0;
}