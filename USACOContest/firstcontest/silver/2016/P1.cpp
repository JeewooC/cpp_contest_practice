/*
ID: jeewoo.1
TASK: haybales
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;

int count_haybales(vector<int> &ve, int val) {
  int lower = 0;
  int upper = ve.size() - 1;

  while (lower != upper) {
    int mid = (lower + upper) / 2;
    if (ve.at(mid) <= val) {
      lower = mid;
    } else {
      upper = mid - 1;
    }
  }

  return lower + 1;
}

int main() {
  ios_base::sync_with_stdio(false);
  ifstream fin ("haybales.in");
  ofstream fout ("haybales.out");

  vector<int> ve;
  int N, Q;
  cin >> N >> Q;

  for (int i = 0; i < N; i++) {
    int val;
    cin >> val;
    ve.push_back(val);
  }

  while (Q-- > 0) {
    int min, max;
    cin >> min >> max;
    cout << count_haybales(ve, max)  - count_haybales(ve, min - 1) << '\n';
  }

  return 0;
}
  