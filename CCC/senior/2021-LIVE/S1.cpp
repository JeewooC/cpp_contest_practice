#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  // -----------------------------
  int N; cin >> N;
  double heights[N+1];
  double widths[N];

  for (int i = 0; i < N+1; i++) {
    double h; cin >> h;
    heights[i] = h;
  }

  for (int i = 0; i < N; i++) {
    double w; cin >> w;
    widths[i] = w;
  }

  double totalArea = 0.0;
  for (int i = 0; i < N; i++) {
    double width = widths[i];
    double lHeight = heights[i];
    double rHeight = heights[i+1];

    totalArea += width * (lHeight + rHeight) / 2.0;
  }

  cout << totalArea << '\n';
  // -----------------------------
  return 0;
}