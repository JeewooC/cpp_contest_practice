#include <bits/stdc++.h>
using namespace std;

struct Student {
  int id;
  vector<int> shorter;
  vector<int> taller;
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  // -----------------------------
  int N, M;
  cin >> N >> M;
  Student *students[N+1];
  memset(&students, 0, sizeof students);
  while (M-- > 0) {
    int x, y;
    cin >> x >> y;
    if (students[x] == NULL) {
      students[x] = new Student();
    }
    if (students[y] == NULL) {
      students[y] = new Student();
    }
    students[x]->id = x;
    students[x]->shorter.push_back(y);
    students[y]->id = y;
    students[y]->taller.push_back(x);
  }

  int p, q;
  cin >> p >> q;
  // search shorter
  bool inShorter = false;
  queue<int> sQ;
  bool visited[N+1];
  memset(visited, false, N+1);
  for (int i = 0; i < students[p]->shorter.size(); i++) {
    sQ.push(students[p]->shorter[i]);
  }
  while (!sQ.empty()) {
    int curr = sQ.front(); sQ.pop();
    visited[curr] = true;
    if (curr == q) {
      inShorter = true;
      break;
    }
    for (int i = 0; i < students[curr]->shorter.size(); i++) {
      if (!visited[students[curr]->shorter[i]]) {
        sQ.push(students[curr]->shorter[i]);
      }
    }
  }
  if (inShorter) {
    cout << "yes" << '\n';
  } else {
    // search taller
    bool inTaller = false;
    queue<int> tQ;
    for (int i = 0; i < students[p]->taller.size(); i++) {
      tQ.push(students[p]->taller[i]);
    }
    while (!tQ.empty()) {
      int curr = tQ.front(); tQ.pop();
      if (curr == q) {
        inTaller = true;
        break;
      }
      for (int i = 0; i < students[curr]->taller.size(); i++) {
        tQ.push(students[curr]->taller[i]);
      }
    }
    if (inTaller) {
      cout << "no" << '\n';
    } else {
      cout << "unknown" << '\n';
    }
  }

  // -----------------------------
  return 0;
}