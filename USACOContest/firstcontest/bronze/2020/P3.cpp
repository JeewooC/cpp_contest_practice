#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> North;
vector<pair<int, int>> East;

bool sortBySecond(const pair<int, int> &a, const pair<int, int> &b) {
  return (a.second < b.second);
}

int northFacingCowsGetY(pair<int, int> cow1) {
  for (auto cow2 = East.begin(); cow2 != East.end(); cow2++) {
    if (cow2->second > cow1.second && cow2->first < cow1.first) {
      // Only bother to check if y coord of cow2 is actually above y coord of cow1
      // and the x coord of cow2 is behind the x coord of cow1
      if (((cow2->second)-(cow1.second)) > ((cow1.first)-(cow2->first))) {
        // If the time it takes for cow1 to get to the y coord of cow2 is greater than
        // the time it takes for cow2 to get to the x coord of cow1, cow2 will block cow1
        return cow1.second + (cow2->second - cow1.second);
      }
    }
  }
  return -1;
}

int eastFacingCowsGetX(pair<int, int> cow1) {
  for (auto cow2 = North.begin(); cow2 != North.end(); cow2++) {
    if (cow2->first > cow1.first && cow2->second < cow1.second) {
      // Only bother to check if x coord of cow2 is actually after x coord of cow1
      // and the y coord of cow2 is below cow1
      if (((cow2->first)-(cow1.first)) > ((cow1.second)-(cow2->second))) {
        // If the time it takes for cow1 to get to the x coord of cow2 is greater than
        // the time it takes for cow2 to get to the y coord of cow1, cow2 will block cow1
        return cow1.first + (cow2->first-cow1.first);
      }
    }
  }
  return -1;
}


void northFacingCows(pair<int, int> cow1) {
  for (auto cow2 = East.begin(); cow2 != East.end(); cow2++) {
    if (cow2->second > cow1.second && cow2->first < cow1.first) {
      // Only bother to check if y coord of cow2 is actually above y coord of cow1
      // and the x coord of cow2 is behind the x coord of cow1
      if (((cow2->second)-(cow1.second)) > ((cow1.first)-(cow2->first))) {
        // If the time it takes for cow1 to get to the y coord of cow2 is greater than
        // the time it takes for cow2 to get to the x coord of cow1, cow2 will block cow1
        int xOfCow2 = eastFacingCowsGetX(*cow2);
        if (xOfCow2 == -1 || xOfCow2 >= cow1.first) {
          cout << (cow2->second - cow1.second) << '\n';
          return;
        }
      }
    }
  }
  cout << "Infinity" << '\n';
}



//void northFacingCows(pair<int, int> cow1) {
//  for (int i = 0; i < East.size(); i++) {
//    pair<int, int> cow2 = East[i];
//    if (cow2.second > cow1.second && cow2.first < cow1.first) {
//      // Only bother to check if y coord of cow2 is actually above y coord of cow1
//      // and the x coord of cow2 is behind the x coord of cow1
//      if (((cow2.second)-(cow1.second)) > ((cow1.first)-(cow2.first))) {
//        // If the time it takes for cow1 to get to the y coord of cow2 is greater than
//        // the time it takes for cow2 to get to the x coord of cow1, cow2 will block cow1
//        cout << (cow2.second - cow1.second) << '\n';
//        return;
//      }
//    }
//  }
//  cout << "Infinity" << '\n';
//}

void eastFacingCows(pair<int, int> cow1) {
  for (auto cow2 = North.begin(); cow2 != North.end(); cow2++) {
    if (cow2->first > cow1.first && cow2->second < cow1.second) {
      // Only bother to check if x coord of cow2 is actually after x coord of cow1
      // and the y coord of cow2 is below cow1
      if (((cow2->first)-(cow1.first)) > ((cow1.second)-(cow2->second))) {
        // If the time it takes for cow1 to get to the x coord of cow2 is greater than
        // the time it takes for cow2 to get to the y coord of cow1, cow2 will block cow1
        int yOfCow2 = northFacingCowsGetY(*cow2);
        if (yOfCow2 == -1 || yOfCow2 >= cow1.second) {
          cout << (cow2->first - cow1.first) << '\n';
          return;
        }
      }
    }
  }
  cout << "Infinity" << '\n';
}



//void eastFacingCows(pair<int, int> cow1) {
//  for (int i = 0; i < North.size(); i++) {
//    pair<int, int> cow2 = North[i];
//    if (cow2.first > cow1.first && cow2.second < cow1.second) {
//      // Only bother to check if x coord of cow2 is actually after x coord of cow1
//      // and the y coord of cow2 is below cow1
//      if (((cow2.first) - (cow1.first)) > ((cow1.second) - (cow2.second))) {
//        // If the time it takes for cow1 to get to the x coord of cow2 is greater than
//        // the time it takes for cow2 to get to the y coord of cow1, cow2 will block cow1
//        cout << (cow2.first - cow1.first) << '\n';
//        return;
//      }
//    }
//  }
//  cout << "Infinity" << '\n';
//}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  // -----------------------------
  int N; cin >> N;
  vector<pair<char, pair<int, int>>> cowsInOrder;
  for (int i = 0; i < N; i++) {
    char direction;
    int x, y;
    cin >> direction >> x >> y;
    cowsInOrder.push_back(make_pair(direction, make_pair(x, y)));
    if (direction == 'N') {
      North.push_back(make_pair(x, y));
    } else {
      East.push_back(make_pair(x, y));
    }
  }
  sort(North.begin(), North.end());
  sort(East.begin(), East.end(), sortBySecond);

  for (auto itr = cowsInOrder.begin(); itr != cowsInOrder.end(); itr++) {
    if (itr->first == 'N') {
      northFacingCows(itr->second);
    } else {
      eastFacingCows(itr->second);
    }
  }
  // -----------------------------
  return 0;
}