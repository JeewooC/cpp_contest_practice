#include <bits/stdc++.h>
using namespace std;

void rotate(int **table, int width) {
  // Transpose
  for (int i = 0; i < width - 1; i++) {
    for (int j = i + 1; j < width; j++) {
      int tmp = table[i][j];
      table[i][j] = table[j][i];
      table[j][i] = tmp;
    }
  }
  // Mirror
  for (int r = 0; r < width; r++) {
    for (int c = 0; c < width / 2; c++) {
      int tmp = table[r][c];
      table[r][c] = table[r][width - c - 1];
      table[r][width - c - 1] = tmp;
    }
  }
}


void rotateBy90 (int **table, int N) {
    for (int i = 0; i < N; i++) {
      for (int j = i+1; j < N; j++) {
        int temp = table[i][j];
        table[i][j] = table[j][i];
        table[j][i] = temp;
      }
    }

    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N/2; j++) {
        int temp = table[i][j];
        table[i][j] = table[i][N - j - 1];
        table[i][N - j - 1] = temp;
      }
    }


    // testing
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cout << table[i][j] << " ";
    }
    cout << "\n";
  }
  cout << '\n';
}

bool check(int **table, int N) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (i != N-1 && table[i+1][j] <= table[i][j]) {
        return false;
      }
      if (j != N-1 && table[i][j+1] <= table[i][j]) {
        return false;
      }
    }
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);

  int N; cin >> N;
  int **table;
  table = new int *[N];
  for (int i = 0; i < N; i++) {
    table[i] = new int[N];
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      int height; cin >> height;
      table[i][j] = height;
    }
  }

  while (!check(table, N)) {
    rotate(table, N);
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cout << table[i][j] << " ";
    }
    cout << "\n";
  }

  return 0;
}