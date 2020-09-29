// ********************************
// Optimize prime finding algorithm

#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n) {
  for (int i = 3; i <= n/2; i++) {
    if (n%i == 0) {
      return false;
    }
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);

  int T; cin >> T;
  set<int> primes;
  primes.insert(2);
  primes.insert(3);
  primes.insert(5);
  primes.insert(7);
  primes.insert(11);
  primes.insert(13);
  int max = 16;

  for (int t = 0; t < T; t++) {
    int N; cin >> N;
    if (N*2-2 > max) {
      for (; max < N*2; max++) {
        if (max%2 != 0 && isPrime(max)) {
          // if max is a prime number add it to primes
          primes.insert(max);
        }
      } max--;
    }

    for (auto it = primes.begin(); it != primes.end(); it++) {
      if (primes.find((N*2)-(*it)) != primes.end()) {
        cout << *it << ' ' << (N*2)-(*it) << '\n';
        break;
      }
    }
  }


  return 0;
}