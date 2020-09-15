/*
ID: jeewoo.1
TASK: socdist1
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  ofstream fout ("socdist1.out");
  ifstream fin ("socdist1.in");

  int N; fin >> N;
  vector<int> spaces;
  int counter = 1, cowCounter = 0;

  string str; fin >> str;

  for (int i = 0; i < N; i++) {
    if (str[i] == '0') {
      counter++;
    } else if (str[i] == '1' && counter > 1) {
      spaces.push_back(counter);
      counter = 1;
      cowCounter++;
    } else if (i == 0 && str[i] == '1') {
      cowCounter++;
    }
  }

  // if it ends with a gap
  if (counter > 1) {
    spaces.push_back(counter);
  }

  vector<int> spacesCopy = spaces;
  sort(spaces.begin(), spaces.end(), greater<int>());

  if (spaces.size() > 1) {
    // ignoring the beginning and ending gap if they're not the biggest or second biggest
    if (spacesCopy.at(0) < spaces.at(1) && str[0] != '1') {
      spacesCopy.erase(spacesCopy.begin());
    }
    if (spacesCopy.at(spacesCopy.size()-1) < spaces.at(1) && str[N-1] != '1') {
      spacesCopy.erase(spacesCopy.end()-1);
    }
  }

  sort(spacesCopy.begin(), spacesCopy.end(), greater<int>());
  spaces = spacesCopy;

  if (cowCounter == 0) {
    // there are no cows
    fout << N-1 << '\n';
    return 0;
  } else if (cowCounter == 1 && spaces.size() == 1) {
    // there is one cow at an edge
    // therefore divide the gap by half b/c one of the cows are going on the other edge
    spaces.at(0) /= 2;
  } else if (cowCounter == 1 && spaces.size() == 2) {
    // there is one cow in the middle
    spaces.at(0) -= 1;
    spaces.at(1) -= 1;
  } else if (spaces.size() == 1) {
      // there is only one 'gap'
      spaces.at(0) /= 3;
  } else if (spaces.at(0)/3 > spaces.at(1)/2) {
    // putting both cows into the biggest gap is better than putting one into the second
    // biggest gap
    spaces.at(0) /= 3;
  } else {
    spaces.at(0) /= 2;
    spaces.at(1) /= 2;
  }

  int d = spaces.at(0);
  for (int i = 1; i < spaces.size(); i++) {
    if (spaces.at(i) < d) {
      d = spaces.at(i);
    }
  }
  fout << d << '\n';
  return 0;
}
  