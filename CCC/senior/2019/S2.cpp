#include <bits/stdc++.h>
using namespace std;

//int power(int a, unsigned int n, int p) {
//  int res = 1;
//  a = a % p;
//
//  while (n > 0) {
//    if (n & 1) {
//      res = (res*a) % p;
//    }
//
//    n /= 2;
//    a = (a*a) % p;
//  }
//  return res;
//}
//
//int gcd(int a, int b) {
//  if (a < b) {
//    return gcd(b, a);
//  } else if (a%b == 0) {
//    return b;
//  } else {
//    return gcd(b, a%b);
//  }
//}
//
//bool isPrime(unsigned int n, int k) {
//  while (k > 0) {
//    int a = 2 + rand() % (n-4);
//    if (gcd(n, a) != 1) {
//      return false;
//    }
//    if (power(a, n-1, n) != 1) {
//      return false;
//    }
//    k--;
//  }
//  return true;
//}
//
//int main() {
//  ios_base::sync_with_stdio(false);
//
//  int T; cin >> T;
//  set<int> primes;
//  primes.insert(2);
//  primes.insert(3);
//  primes.insert(5);
//  primes.insert(7);
//  primes.insert(11);
//  primes.insert(13);
//  int max = 16;
//
//  for (int t = 0; t < T; t++) {
//    int N; cin >> N;
//    if (N*2-2 > max) {
//      for (; max < N*2; max++) {
//        if (max%2 != 0 && isPrime(max, 100)) {
//          // if max is a prime number add it to primes
//          primes.insert(max);
//        }
//      } max--;
//    }
//
//    for (auto it = primes.begin(); it != primes.end(); it++) {
//      if (primes.find((N*2)-(*it)) != primes.end()) {
//        cout << *it << ' ' << (N*2)-(*it) << '\n';
//        break;
//      }
//    }
//  }
//
//
//  return 0;
//}


void sieveOfEratosthenes(int n, set<int> &primes) {
  bool prime[n+1];
  memset(prime, true, sizeof(prime));

  for (int p = 2; p*p <= n; p++) {
    if (prime[p]) {
      for (int i = p*p; i <= n; i += p) {
        prime[i] = false;
      }
    }
  }

  for (int p = 2; p <= n; p++) {
    if (prime[p]) {
      primes.insert(p);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);

  int T; cin >> T;
  set<int> primes;
  int arr[T];
  int maxN = 0;

  for (int t = 0; t < T; t++) {
    int N; cin >> N;
    arr[t] = N;
    if (N > maxN) maxN = N;
  }

  sieveOfEratosthenes(maxN*2, primes);

  for (int t = 0; t < T; t++) {
    int N = arr[t];
    for (auto it = primes.begin(); it != primes.end(); it++) {
      if (primes.find((N*2)-(*it)) != primes.end()) {
        cout << *it << ' ' << (N*2)-(*it) << '\n';
        break;
      }
    }

  }


  return 0;
}