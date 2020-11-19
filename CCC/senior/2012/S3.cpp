#include <bits/stdc++.h>
using namespace std;

bool sortByVal(const pair<int, int> &a, const pair<int, int> &b) {
  return a.second > b.second;
}


vector<pair<int, int>> eliminateByVal(const vector<pair<int, int>> &sensors, int n) {
  vector<pair<int, int>> newSensors;
  for (int i = 0; i < sensors.size(); i++) {
    if (sensors[i].second < n) {
      break;
    }
    newSensors.push_back(sensors[i]);
  }
  return newSensors;
}

int largestAbsoluteDifferenceR(const vector<pair<int, int>> &sensors, int n) {
  int max = 0;
  for (int i = 0; i < sensors.size(); i++) {
    if (abs(sensors[i].first - n) > max) {
      max = abs(sensors[i].first - n);
    }
  }
  return max;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  // -----------------------------
  int sensors[1002] = {0};
  int N; cin >> N;
  for (int i = 0; i < N; i++) {
    int R; cin >> R;
    sensors[R]++;
  }

  vector<pair<int, int>> sensorsSorted;
  for (int i = 1; i < 1001; i++) {
    if (sensors[i] != 0) {
      sensorsSorted.push_back(make_pair(i, sensors[i]));
    }
  }
  sort(sensorsSorted.begin(), sensorsSorted.end(), sortByVal);

  if (sensorsSorted[0].second == sensorsSorted[1].second) {
    if (sensorsSorted[1].second != sensorsSorted[2].second) {
      // there's exactly 2 highest frequency
      cout << abs(sensorsSorted[0].first-sensorsSorted[1].first) << '\n';
    } else {
      // there are more than 2 of the highest frequency
      vector<pair<int, int>> highestFreqs = eliminateByVal(sensorsSorted, sensorsSorted[0].second);
      int maxR = INT_MIN;
      int minR = INT_MAX;
      for (int i = 0; i < highestFreqs.size(); i++) {
        if (highestFreqs[i].first > maxR) maxR = highestFreqs[i].first;
        if (highestFreqs[i].first < minR) minR = highestFreqs[i].first;
      }
      cout << maxR-minR << '\n';
    }
  } else {
    if (sensorsSorted[1].second == sensorsSorted[2].second) {
      // there's 1 highest frequency and more than 1 second highest frequency
      int highestFreqR = sensorsSorted[0].first;
      vector<pair<int, int>> secondHighestFreqs = eliminateByVal(sensorsSorted, sensorsSorted[1].second);
      secondHighestFreqs.erase(secondHighestFreqs.begin());

      cout << largestAbsoluteDifferenceR(secondHighestFreqs, highestFreqR) << '\n';
    } else {
      // there's exactly 1 highest frequency and 1 second highest frequency
      cout << abs(sensorsSorted[0].first-sensorsSorted[1].first) << '\n';
    }
  }
  // -----------------------------
  return 0;
}