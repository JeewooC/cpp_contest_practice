#include <bits/stdc++.h>
using namespace std;

struct coord {
  int X, Y, P;
};

int main() {
  int N, m, c;
  cin >> N >> m >> c;
  vector<coord> coords;
  for (int i = 0; i < N; i++) {
    int x, y, p;
    cin >> x >> y >> p;
    coords.push_back({x, y, p});
  }

  int above = 0, below = 0;
  for (auto it = coords.begin(); it != coords.end(); ++it) {
    int yOfRiver = m * (it->X) + c;
    if (it->Y > yOfRiver) {
      above += it->P;
    } else if (it->Y < yOfRiver) {
      below += it->P;
    }
  }

  cout << ((above > below)?above:below) << endl;
}