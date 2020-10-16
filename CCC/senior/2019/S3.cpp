#include <bits/stdc++.h>
using namespace std;
int CAP = INT_MIN;

void printGrid(int grid[3][3]) {
  for (int i = 0; i < 3; i++) {
    cout << grid[i][0] << ' ' << grid[i][1] << ' ' << grid[i][2] << '\n';
  }
}

int theOtherNumber(int x, int y) {
  if ((x == 0 && y == 1) || (x == 1 && y == 0)) {
    return 2;
  } else if ((x == 1 && y == 2) || (x == 2 && y == 1)) {
    return 0;
  } else if ((x == 0 && y == 2) || (x == 2 && y == 0)) {
    return 1;
  }
}

pair<int, int> theOtherTwoNumbers(int n) {
  if (n == 0) {
    return make_pair(1, 2);
  } else if (n == 1) {
    return make_pair(0, 2);
  } else {
    return make_pair(0, 1);
  }
}

int lastNumberCalculator(int missingIndex, int x, int y) {

  if (missingIndex == 0) {
    return x - (y - x);
  } else if (missingIndex == 1) {
    return (x + y) / 2;
  } else {
    return y + (y - x);
  }
}

pair<int, pair<int, int>> findLastCell(set<pair<int, int>> emptyCells, set<pair<int, int>> filledCells) {
  int rowCount[3] = {0};
  int colCount[3] = {0};
  vector<int> rowsWithTwo, colsWithTwo;
  for (auto it = filledCells.begin(); it != filledCells.end(); it++) {
    rowCount[it->first]++;
    colCount[it->second]++;
  }
  for (int i = 0; i < 3; i++) {
    if (rowCount[i] == 2) {
      rowsWithTwo.push_back(i);
    }
    if (colCount[i] == 2) {
      colsWithTwo.push_back(i);
    }
  }
  for (auto it = emptyCells.begin(); it != emptyCells.end(); it++) {
    if (count(rowsWithTwo.begin(), rowsWithTwo.end(), it->first)) {
      // returning 1 means this is row wise
      return make_pair(1, *it);
    }
    if (count(colsWithTwo.begin(), colsWithTwo.end(), it-> second)) {
      // returning 2 means this is col wise
      return make_pair(2, *it);
    }
  }

}

int main() {
  ios_base::sync_with_stdio(false);
  // input the grid into a 2d array, if it's an unspecified integer, put it as CAP
  // store all unspecified cell as pair of coords in a set
  int grid[3][3];
  set<pair<int, int>> emptyCells;
  set<pair<int, int>> filledCells;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      string n; cin >> n;
      if (n == "X") {
        grid[i][j] = CAP;
        emptyCells.insert(make_pair(i, j));
      } else {
        grid[i][j] = stoi(n);
        filledCells.insert(make_pair(i, j));
      }
    }
  }

  int emptyCellCount = emptyCells.size();
  // possible conditions
  // if all cells are emtpy (9 empty cells)
    // fill all cells with 1
  // if there are exactly 6 empty cells
    // there could be one in each line
    // there could be two in one line and one in another with one empty line
    // there could be all three in one line with two empty lines
  // if there are 5 or less empty cells
    // like filling in the blanks, find a line with only one empty cell and fill it in
  // if there are 7 empty cells
    // if both numbers are in one line, fill in the empty cell in that line then copy that line to the other lines
    // if the two numbers are in a different line, copy each other to its respective position in each others line and fill the rest in
  // if there are 8 empty cells
    // fill all cells with that one number

  if (emptyCellCount == 9) {
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        grid[i][j] = 1;
      }
    }
  } else if (emptyCellCount == 8) {
    int n = grid[emptyCells.begin()->first][emptyCells.begin()->second];
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        grid[i][j] = n;
      }
    }
  } else if (emptyCellCount == 7) {
    auto it = filledCells.begin();
    pair<int, int> one = *(it); it++;
    pair<int, int> two = *(it);

    if (one.first > two.first || one.second > two.second) {
      pair<int, int> temp = one;
      one = two;
      two = temp;
    }

    if (one.first != two.first && one.second != two.second) {
      // this means the two filled cells are in different lines
      // first, copy the the filled cells values into the respective empty cells in each other's line
      // then, fill the other cell in both lines (do row wise since it doesn't matter either way)
      // finally, copy the values of the first row to the remaining row
      grid[two.first][one.second] = grid[one.first][one.second];
      grid[one.first][two.second] = grid[two.first][two.second];
      int otherNumber = lastNumberCalculator(
          theOtherNumber(one.second, two.second),
          grid[one.first][one.second],
          grid[two.first][two.second]
          );
      grid[one.first][theOtherNumber(one.second, two.second)] = otherNumber;
      grid[two.first][theOtherNumber(one.second, two.second)] = otherNumber;
      for (int i = 0; i < 3; i++) {
        grid[theOtherNumber(one.first, two.first)][i] = grid[one.first][i];
      }
    } else {
      if (one.first == two.first) {
        // this means there are two filled cells in a same row
        // first, fill in the empty cell in this row
        // then, copy this row to the other two rows
        grid[one.first][theOtherNumber(one.second, two.second)] = lastNumberCalculator(
            theOtherNumber(one.second, two.second),
            grid[one.first][one.second],
            grid[two.first][two.second]);
        for (int i = 0; i < 3; i++) {
          if (i != one.first) {
            for (int j = 0; j < 3; j++) {
              grid[i][j] = grid[one.first][j];
            }
          }
        }
      } else if (one.second == two.second) {
        // this means there are two filled cells in a same col
        // do the exact same thing but instead for col
        grid[theOtherNumber(one.first, two.first)][one.second] = lastNumberCalculator(
            theOtherNumber(one.first, two.first),
            grid[one.first][one.second],
            grid[two.first][two.second]);
        for (int i = 0; i < 3; i++) {
          if (i != one.second) {
            for (int j = 0; j < 3; j++) {
              grid[j][i] = grid[j][one.second];
            }
          }
        }
      }
    }
  } else if (emptyCellCount == 6) {


  } else if (emptyCellCount <= 5 && emptyCellCount > 0) {
    while (emptyCellCount > 0) {
      pair<int, pair<int, int>> temp = findLastCell(emptyCells, filledCells);
      int caseNumber = temp.first;
      pair<int, int> targetEmptyCell = temp.second;

      if (caseNumber == 1) {
        pair<int, int> otherTwoCols = theOtherTwoNumbers(targetEmptyCell.second);
        grid[targetEmptyCell.first][targetEmptyCell.second] = lastNumberCalculator(
            targetEmptyCell.second,
            grid[targetEmptyCell.first][otherTwoCols.first],
            grid[targetEmptyCell.first][otherTwoCols.second]
            );
      } else if (caseNumber == 2) {
        pair<int, int> otherTwoRows = theOtherTwoNumbers(targetEmptyCell.first);
        grid[targetEmptyCell.first][targetEmptyCell.second] = lastNumberCalculator(
            targetEmptyCell.first,
            grid[otherTwoRows.first][targetEmptyCell.second],
            grid[otherTwoRows.second][targetEmptyCell.second]
            );
      }

      emptyCells.erase(targetEmptyCell);
      emptyCellCount--;
      filledCells.insert(targetEmptyCell);
    }
  }


  printGrid(grid);

  return 0;
}