#include <bits/stdc++.h>
using namespace std;

int getTotal(int i, int j, vector<int> petals) {
  int total = 0;
  for (int start = i; start <= j; start++) {
    total += petals[start];
  }
  return total;
}

bool contains(int i, int j, vector<int> petals, int X) {
  for (int start = i; start <= j; start++) {
    if (petals[start] == X) {
      return true;
    }
  }
  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  // -----------------------------
  int N; cin >> N;
  vector<int> petals;
  for (int i = 0; i < N; i++) {
    int temp; cin >> temp;
    petals.push_back(temp);
  }


  int counter = N;
  for (int i = 0; i < N-1; i++) {
    for (int j = i+1; j < N; j++) {
      int total = getTotal(i, j, petals);
      if (total % (j-i+1) == 0) {
        int avg = total / (j-i+1);
        if (contains(i, j, petals, avg)) {
          counter++;
        }
      }
    }
  }

  cout << counter << '\n';
  // -----------------------------
  return 0;
}