#include <bits/stdc++.h>
using namespace std;

int T;
bool games[5][5] = {false};
int totalOutcome = 0;

pair<int, int> pop_front(vector<pair<int, int>>& vec) {
  pair<int, int> g1 = vec.front();
  vec.front() = move(vec.back());
  vec.pop_back();
  return g1;
}

bool checkIfTeamWon(array<int, 5> scores) {
  array<int, 5> copy = scores;
  sort(copy.begin(), copy.end(), greater<int>());
  if (copy[0] == scores[T] && copy[0] != copy[1]) {
    return true;
  }
  return false;
}

void playRemainingGames(vector<pair<int, int>> gamesToPlay, array<int, 5> scores) {
  if (gamesToPlay.size() == 0) {
    if (checkIfTeamWon(scores)) totalOutcome++;
  } else {
    for (int i = 0; i < 3; i++) {
      pair<int, int> g1 = pop_front(gamesToPlay);
      int l = g1.first, r = g1.second;
      if (i == 0) {
        // left win
        scores[l] += 3;
        playRemainingGames(gamesToPlay, scores);
        scores[l] -= 3;
      } else if (i == 1) {
        // draw
        scores[l]++;
        scores[r]++;
        playRemainingGames(gamesToPlay, scores);
        scores[l]--;
        scores[r]--;
      } else {
        // left loss
        scores[r] += 3;
        playRemainingGames(gamesToPlay, scores);
        scores[r] -= 3;
      }
      gamesToPlay.insert(gamesToPlay.begin(), g1);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);

  games[1][2] = true;
  games[1][3] = true;
  games[1][4] = true;
  games[2][3] = true;
  games[2][4] = true;
  games[3][4] = true;

  array<int, 5> scores = {0};
  int G;
  cin >> T >> G;
  for (int i = 0; i < G; i++) {
    int A, B, Sa, Sb;
    cin >> A >> B >> Sa >> Sb;

    games[A][B] = false;
    if (Sa > Sb) {
      scores[A] += 3;
    } else if (Sa < Sb) {
      scores[B] += 3;
    } else {
      scores[A]++;
      scores[B]++;
    }
  }

  vector<pair<int, int>> gamesToPlay;
  for (int i = 1; i <= 3; i++) {
    for (int j = i+1; j <= 4; j++) {
      if (games[i][j]) {
        gamesToPlay.push_back(make_pair(i, j));
      }
    }
  }

  playRemainingGames(gamesToPlay, scores);
  cout << totalOutcome << '\n';

  return 0;
}