#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  // -----------------------------
  vector<int> numbers;
  for (int i = 0; i < 7; i++) {
    int temp; cin >> temp;
    numbers.push_back(temp);
  }
  sort(numbers.begin(), numbers.end());

  int A = min(numbers[0], numbers[1]);
  int B = max(numbers[0], numbers[1]);
  int C = numbers[numbers.size()-1] - (numbers[0] + numbers[1]);

  cout << A << ' ' << B << ' ' << C << '\n';
  // -----------------------------
  return 0;
}