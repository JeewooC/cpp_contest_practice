#include <bits/stdc++.h>
using namespace std;

int main() {
  // generating the sequence
  int occ[128];
  int seq[128]; seq[0] = 0;
  fill(begin(occ), begin(occ)+128, -1); occ[0] = 0;
  for (int i = 0; i + 1 < 128; i++) {
    if (occ[seq[i]] >= 0) {
      seq[i+1] = i-occ[seq[i]];
    } else {
      seq[i+1] = 0;
    }
    occ[seq[i]] = i;
  }

  // Printing the output
  int T; cin >> T;
  for (int t = 0; t < T; t++) {
    int N; cin >> N;
    int total = 0;
    for (int i = 0; i < N; i++) {
      if (seq[i] == seq[N-1]) {
        total++;
      }
    }
    cout << total << endl;
  }
}