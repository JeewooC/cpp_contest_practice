#include <bits/stdc++.h>
using namespace std;

int main() {
  // -----------------------------
  int N; cin >> N;
  cin.ignore();

  int sCount = 0, tCount = 0;
  while (N > 0) {
    string line;
    getline(cin, line);
    for (int i = 0; i < line.size(); i++) {
      char c = line[i];
      if (c == 't' || c == 'T') {
        tCount++;
      } else if (c == 's' || c == 'S') {
        sCount++;
      }
    }
    N--;
  }

  if (tCount > sCount) {
    cout << "English" << '\n';
  } else {
    cout << "French" << '\n';
  }
  // -----------------------------
  return 0;
}

