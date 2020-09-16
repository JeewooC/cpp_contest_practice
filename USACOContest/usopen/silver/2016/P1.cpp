/*
ID: jeewoo.1
TASK: reduce
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  ofstream fout ("reduce.out");
  ifstream fin ("reduce.in");
  int N; cin >> N;
  vector<pair<int, int>> coords;
  int xAvg = 0, yAvg = 0;
  for (int i = 0; i < N; i++) {
    int x, y;
    cin >> x >> y;
    coords.push_back(make_pair(x, y));
    xAvg += x;
    yAvg += y;
  }
  xAvg /= N;
  yAvg /= N;


  // get 3 coords with x coord farthest from xAvg and get 3 coords with y coord farthest from yAvg
  // sort coords into x increasing order and another into y increasing order
  // there should be a total of 38 combinations, for each combination get the area without those coords
  // find the combination with the smallest area

  vector<pair<int, int>> farthestFromXAvg = coords;
  sort(farthestFromXAvg.begin(), farthestFromXAvg.end(), [&xAvg] (pair<int, int> const& p1, pair<int, int> const& p2) {
    return abs(xAvg-p1.first) > abs(xAvg-p2.first);
  });
  vector<pair<int, int>> farthestFromYAvg = coords;
  sort(farthestFromYAvg.begin(), farthestFromYAvg.end(), [&yAvg] (pair<int, int> const& p1, pair<int, int> const& p2) {
    return abs(yAvg-p1.second) > abs(yAvg-p2.second);
  });
  vector<pair<int, int>> xIncrease = coords;
  sort(xIncrease.begin(), xIncrease.end(), [] (pair<int, int> const& p1, pair<int, int> const& p2) {
    return p1.first < p2.first;
  });
  vector<pair<int, int>> yIncrease = coords;
  sort(yIncrease.begin(), yIncrease.end(), [] (pair<int, int> const& p1, pair<int, int> const& p2) {
    return p1.second < p2.second;
  });

  // 2 from xAvg, 1 from yAvg

  // 1 from xAvg, 2 from yAvg

  // All 3 from xAvg
  vector<pair<int,int>> xTemp = xIncrease;
  auto one = find(xTemp.begin(), xTemp.end(), farthestFromXAvg.at(0));
  auto two = find(xTemp.begin(), xTemp.end(), farthestFromXAvg.at(1));
  auto three = find(xTemp.begin(), xTemp.end(), farthestFromXAvg.at(2));
  xTemp.erase(one);
  xTemp.erase(two);
  xTemp.erase(three);
  int xLength = xTemp.at(xTemp.size()-1).first - xTemp.at(0).first;
  vector<pair<int,int>> yTemp = yIncrease;
  one = find(yTemp.begin(), yTemp.end(), farthestFromXAvg.at(0));
  two = find(yTemp.begin(), yTemp.end(), farthestFromXAvg.at(1));
  three = find(yTemp.begin(), yTemp.end(), farthestFromXAvg.at(2));
  xTemp.erase(one);
  xTemp.erase(two);
  xTemp.erase(three);
  int yLength = yTemp.at(yTemp.size()-1).second - yTemp.at(0).second;

  int area = xLength * yLength;
  // All 3 from yAvg

  
  return 0;
}
  