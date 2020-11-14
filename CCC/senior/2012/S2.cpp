#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);

  map<char, int> symbols;
  symbols.insert(make_pair('I', 1));
  symbols.insert(make_pair('V', 5));
  symbols.insert(make_pair('X', 10));
  symbols.insert(make_pair('L', 50));
  symbols.insert(make_pair('C', 100));
  symbols.insert(make_pair('D', 500));
  symbols.insert(make_pair('M', 1000));

  string aromaNums; cin >> aromaNums;
  int total = 0;
  while (aromaNums.size() > 2) {
    int A = stoi(aromaNums.substr(0, 1));
    char R = aromaNums[1];

    char nextR = aromaNums[3];
    if (symbols.at(nextR) > symbols.at(R)) {
      total -= A * symbols.at(R);
    } else {
      total += A * symbols.at(R);
    }

    aromaNums = aromaNums.substr(2);
  }
  total += stoi(aromaNums.substr(0, 1)) * symbols.at(aromaNums[1]);
  cout << total << '\n';

  return 0;
}