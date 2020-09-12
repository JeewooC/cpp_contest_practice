#include <bits/stdc++.h>
using namespace std;

// **** IMPORTANT ****
// direction is as follows
// 1 is up (from below)
// 2 is down (from above)
// 3 is right (from left)
// 4 is left (from right)

bool safeFromCamera(int row, int col, vector<vector<char>> grid) {
  if (grid.at(row-1).at(col) == 'C' || grid.at(row+1).at(col) == 'C' ||
  grid.at(row).at(col-1) == 'C' || grid.at(row).at(col+1) == 'C') {
    // if there is a camera directly beside this cell
    return false;
  }
  if (grid.at(row-1).at(col) == 'L' || grid.at(row-1).at(col) == 'R' || grid.at(row-1).at(col) == 'U' || grid.at(row-1).at(col) == 'D') {
    // if there is a conveyor above this cell
    if (grid.at(row-2).at(col) == 'C') {
      // if there is a camera next to the the conveyor that is next to this cell
      return false;
    }
  }
  if (grid.at(row+1).at(col) == 'L' || grid.at(row+1).at(col) == 'R' || grid.at(row+1).at(col) == 'U' || grid.at(row+1).at(col) == 'D') {
    // if there is a conveyor below this cell
    if (grid.at(row+2).at(col) == 'C') {
      // if there is a camera next to the the conveyor that is next to this cell
      return false;
    }
  }
  if (grid.at(row).at(col-1) == 'L' || grid.at(row).at(col-1) == 'R' || grid.at(row).at(col-1) == 'U' || grid.at(row).at(col-1) == 'D') {
    // if there is a conveyor left of this cell
    if (grid.at(row).at(col-2) == 'C') {
      // if there is a camera next to the the conveyor that is next to this cell
      return false;
    }
  }
  if (grid.at(row).at(col+1) == 'L' || grid.at(row).at(col+1) == 'R' || grid.at(row).at(col+1) == 'U' || grid.at(row).at(col+1) == 'D') {
    // if there is a conveyor right of this cell
    if (grid.at(row).at(col+2) == 'C') {
      // if there is a camera next to the the conveyor that is next to this cell
      return false;
    }
  }
  return true;
}

void dfs(int row, int col, int prevRow, int prevCol, vector<vector<char>> grid, vector<vector<int>> &dp, int direction) {
  // start from robot's starting position, scan all four sides for an empty cell and begin dfs
  // recording the amount of moves needed to get to each spot in dp
  if (row == prevRow && col == prevCol) {
    // at the beginning
    if (safeFromCamera(row, col, grid)) {
      dfs(row-1, col, row, col, grid, dp, 1);
      dfs(row+1, col, row, col, grid, dp, 2);
      dfs(row, col-1, row, col, grid, dp, 4);
      dfs(row, col+1, row, col, grid, dp, 3);
    }
  } else {
    char curr = grid.at(row).at(col);
    if (curr == '.') {
      // empty cell
      if (safeFromCamera(row, col, grid)) {
        if (dp.at(row).at(col) == 0) {
          // if this cell hasn't been visited yet
          dp.at(row).at(col) = dp.at(prevRow).at(prevCol) + 1;
        } else {
          // if this cell has been visited and possibly has a shorter path
          dp.at(row).at(col) = min(dp.at(row).at(col), dp.at(prevRow).at(prevCol)+1);
        }
        // dfs all four adjacent cells except for the one that it just came from

        if (direction != 1) {
          dfs(row+1, col, row, col, grid, dp, 2);
        }
        if (direction != 2) {
          dfs(row-1, col, row, col, grid, dp, 1);
        }
        if (direction != 3) {
          dfs(row, col-1, row, col, grid, dp, 4);
        }
        if (direction != 4) {
          dfs(row, col+1, row, col, grid, dp, 3);
        }
      }
    } else if (curr == 'L' || curr == 'R' || curr == 'U' || curr == 'D') {
      // conveyor
      if (curr == 'L') {
        if (grid.at(row).at(col-1) != 'R') {
          // if the cell that this conveyor leads to leads back to this conveyor then it is an infinite loop
          dfs(row, col-1, prevRow, prevCol, grid, dp, 4);
        }
      } else if (curr == 'R') {
        if (grid.at(row).at(col+1) != 'L') {
          // if the cell that this conveyor leads to leads back to this conveyor then it is an infinite loop
          dfs(row, col+1, prevRow, prevCol, grid, dp, 3);
        }
      } else if (curr == 'U') {
        if (grid.at(row-1).at(col) != 'D') {
          // if the cell that this conveyor leads to leads back to this conveyor then it is an infinite loop
          dfs(row-1, col, prevRow, prevCol, grid, dp, 1);
        }
      } else {
        if (grid.at(row+1).at(col) != 'U') {
          // if the cell that this conveyor leads to leads back to this conveyor then it is an infinite loop
          dfs(row+1, col, prevRow, prevCol, grid, dp, 2);
        }
      }
    }
    // if it is not a empty cell or conveyor then there is no need to go further
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  int N, M;
  cin >> N >> M;

  vector<vector<char>> grid(N, vector<char>(M));
  vector<vector<int>> dp(N, vector<int>(M));
  int sRow, sCol;
  vector<pair<int, int>> emptyCellCoords;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      char temp;
      cin >> temp;
      grid.at(i).at(j) = temp;
      if (temp == 'S') {
        sRow = i; sCol = j;
      } else if (temp == '.') {
        emptyCellCoords.push_back(make_pair(i, j));
      }
    }
  }

  dfs(sRow, sCol, sRow, sCol, grid, dp, 0);

  // print all the number of moves stored in dp (of the coordinates in 'emptyCellCoords')
  // if an "empty cell coordinate" doesn't have a value in dp, then it is not accessible therefore print -1
  for (pair<int, int> p : emptyCellCoords) {
    if (dp.at(p.first).at(p.second) != 0) {
      cout << dp.at(p.first).at(p.second) << '\n';
    } else {
      cout << -1 << '\n';
    }
  }

  return 0;
}