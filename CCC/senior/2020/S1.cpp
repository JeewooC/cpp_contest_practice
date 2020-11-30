#include <bits/stdc++.h>
using namespace std;
typedef long long lli;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  // -----------------------------
  int N; cin >> N;
  map<lli, lli> obv;
  for (int i = 0; i < N; i++) {
    lli T, X;
    cin >> T >> X;
    obv.insert(make_pair(T, X));
  }

  double maxSpeed = -5.5;
  auto itr = obv.begin(); itr++;
  for (; itr != obv.end(); itr++) {
    lli t1 = itr->first;
    lli s1 = itr->second;
    itr++;
    lli t2 = itr->first;
    lli s2 = itr->second;
    itr--;

    // multiply one side by 1.0 to make it a decimal
    double speed = ((double) abs(s2 - s1)) / (t2 - t1);
    if (speed > maxSpeed) maxSpeed = speed;
  }

  cout << fixed << setprecision(1) << maxSpeed << '\n';
  // -----------------------------
  return 0;
}