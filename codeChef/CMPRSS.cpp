#include <bits/stdc++.h>
using namespace std;

int main() {
  /*int T; cin >> T;
  for (int t = 0; t < T; t++) {
    int N; cin >> N;
    int arr[N];
    for (int i = 0; i < N; i++) {
      int temp; cin >> temp;
      arr[i] = temp;
    }
    if (N == 1) {
      cout << arr[0] << endl;
    } else if (N == 2) {
      cout << arr[0] << "," << arr[1] << endl;
    } else {
      for (int i = 0; i < N; i++) {
        if (i < N-2) {
          if (arr[i] + 1 == arr[i+1]) {
            if (arr[i+1] + 1 == arr[i+2]) {
              cout << arr[i] << "...";
              i += 2;
              while (i < N-1 && arr[i] + 1 == arr[i+1]) {
                i++;
              }
              if (i == N-1) {
                cout << arr[i] << endl;
              } else {
                cout << arr[i] << ",";
              }
            } else {
              cout << arr[i] << "," << arr[i+1] << ",";
              i++;
            }
          } else {
            cout << arr[i] << ",";
          }
        } else {
          cout << arr[i] << "," << arr[i+1] << endl;
          i++;
        }
      }
    }

  }*/

  // new solution
  int T; cin >> T;
  for (int t = 0; t < T; t++) {
    int N; cin >> N;
    vector<vector<int>> groups;
    for (int i = 0; i < N; i++) {
      int A; cin >> A;
      // add first element into a new group
      if (i == 0) {
        vector<int> newGroup;
        newGroup.push_back(A);
        groups.push_back(newGroup);
        newGroup.clear();
      } else {
        // if A is the next integer of the last element add it to the same group
        // (x+1) - x = 1
        int outerSize = groups.size();
        int innerSize = groups.at(outerSize-1).size();
        if (A - groups.at(outerSize-1).at(innerSize-1) == 1) {
          groups.at(outerSize-1).push_back(A);
        } else {
          // if A isn't the next integer then make a new group with A and add it to groups
          vector<int> newGroup;
          newGroup.push_back(A);
          groups.push_back(newGroup);
          newGroup.clear();
        }
      }
    }
    for (auto it = groups.begin(); it != groups.end(); it++) {
      vector<int> group = *it;
      // if it is the last group
      if (it == groups.end()-1) {
        if (group.size() == 1) {
          cout << group.at(0);
        } else if (group.size() == 2) {
          cout << group.at(0) << "," << group.at(1);
        } else {
          cout << group.at(0) << "..." << group.at(group.size()-1);
        }
      } else {
        if (group.size() == 1) {
          cout << group.at(0) << ",";
        } else if (group.size() == 2) {
          cout << group.at(0) << "," << group.at(1) << ",";
        } else {
          cout << group.at(0) << "..." << group.at(group.size()-1) << ",";
        }
      }
    }
    cout << endl;
  }
}