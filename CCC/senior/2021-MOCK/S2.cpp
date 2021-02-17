#include <bits/stdc++.h>
using namespace std;
typedef long long lld;

template<typename A, typename B>
pair<B,A> flip_pair(const pair<A,B> &p) {
  return pair<B,A>(p.second, p.first);
}

template<typename A, typename B>
multimap<B,A> flip_map(const map<A,B> &src) {
  multimap<B,A> dst;
  transform(src.begin(), src.end(), inserter(dst, dst.begin()), flip_pair<A,B>);
  return dst;
}

int getCombinations(vector<pair<lld, lld>> factors, unordered_map<lld, int> counts) {
  int combinations = 0;
  for (int i = 0; i < factors.size()-1; i++) {
    for (int j = i+1; j < factors.size(); j++) {
      int p1Left = factors[i].first;
      int p1Right = factors[i].second;
      int p2Left = factors[j].first;
      int p2Right = factors[j].second;

      int currentComb = 8;
      if (p1Left != p1Right) {
        currentComb *= counts[p1Left] * counts[p1Right];
      } else {
        currentComb *= (counts[p1Left] - 1);
      }
      if (p2Left != p2Right) {
        currentComb *= counts[p2Left] * counts[p2Right];
      } else {
        currentComb *= (counts[p2Left] - 1);
      }

      combinations += currentComb;
    }
  }
  return combinations;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  // -----------------------------
  set<lld> numbers;
  unordered_map<lld, int> counts;
  map<pair<lld, lld>, lld> products;

  int N; cin >> N;
  for (int i = 0; i < N; i++) {
    lld a; cin >> a;
    if (numbers.find(a) != numbers.end()){
      counts[a]++;
    } else {
      counts.insert(make_pair(a, 1));
      numbers.insert(a);
    }
  }

  for (auto leftItr = numbers.begin(); leftItr != numbers.end(); leftItr++) {
    lld left = *leftItr;
    if (counts[left] >= 2) {
      products.insert(make_pair(make_pair(left, left), left*left));
    }
    auto rightItr = leftItr; rightItr++;
    for (; rightItr != numbers.end(); rightItr++) {
      lld right = *rightItr;
      products.insert(make_pair(make_pair(left, right), left*right));
    }
  }

  multimap<lld, pair<lld, lld>> valueOrderProducts = flip_map(products);

  unordered_map<int, vector<pair<lld, lld>>> productsGrouped;
  for (auto itr = valueOrderProducts.begin(); itr != valueOrderProducts.end(); itr++) {
    pair<lld, lld> factors = itr->second;
    lld product = itr->first;

    productsGrouped[product].push_back(factors);
  }

  for (auto itr = productsGrouped.begin(); itr != productsGrouped.end(); itr++) {
    int product = itr->first;
    vector<pair<lld, lld>> factors = itr->second;

    if (factors.size() > 1) {
      cout << "factors of " << product << ":\n";
      for (pair<lld, lld> factor : factors) {
        cout << factor.first << " x " << factor.second << '\n';
      }
      cout << '\n';
    }
  }

  int totalCombinations = 0;
  for (auto itr = productsGrouped.begin(); itr != productsGrouped.end(); itr++) {
    if ((itr->second).size() > 1) {
      totalCombinations += getCombinations(itr->second, counts);
    } else {
      pair<lld, lld> pair = (itr->second)[0];
      if (pair.first == pair.second && counts[pair.first] >= 4) {
        totalCombinations += 24 * (counts[pair.first] - 3);
      }
    }
  }

  cout << totalCombinations << '\n';
  // -----------------------------
  return 0;
}

// cases:
//  4 of the same numbers (8 x 3 combi)
//  2 of the same numbers (8 x 2 combi)
//  no same numbers (8 combi)
//    - multiply the number of combinations by the number of duplicates
//    - i.e. 1 2 4 8  if there are two 2s and two 4s, the number of combi is 8 x 2 x 2 = 32 combi

// for each 4-tuple that matches the criteria:
//  there are 8 combinations

// storing data:
//  set of all numbers
//  vector of pair of the count of all numbers
//  vector of pair of pair and int of all possible products

// when making vector of all possible products
//  if a number has 2 or more count include the product of itself as well (n^2)