#include <bits/stdc++.h>
using namespace std;
long windows[1010][5];
long tintGrid[2020][2020] = {0};
vector<long> xCoords, yCoords;
long N, T;
long xl, yt, xr, yb, ti;

int binarySearch(long i, vector<long> arr) {
  int start = 0;
  int end = arr.size()-1;
  while (start <= end) {
    int mid = (start+end)/2;
    if (arr.at(mid) == i) {
      return mid;
    } else if (arr.at(mid) > i) {
      end = mid-1;
    } else if (arr.at(mid) < i) {
      start = mid+1;
    }
  }
  return -1;
}

int main() {
  ios_base::sync_with_stdio(false);

  cin >> N >> T;

  for (int i = 0; i < N; i++) {
    cin >> xl >> yt >> xr >> yb >> ti;
    windows[i][0] = xl;
    windows[i][1] = yt;
    windows[i][2] = xr;
    windows[i][3] = yb;
    windows[i][4] = ti;

    xCoords.push_back(xl);
    xCoords.push_back(xr);
    yCoords.push_back(yt);
    yCoords.push_back(yb);
  }

  // sorting the coords and then getting rid of any duplicate ones
  // i.e. if it's [1, 2] and [1, 3] later when looping through x coords and y coords,
  // it will do [1, 2] twice and [1, 3] twice
  sort(xCoords.begin(), xCoords.end());
  auto itr = unique(xCoords.begin(), xCoords.end());
  xCoords.erase(itr, xCoords.end());

  sort(yCoords.begin(), yCoords.end());
  auto itr1 = unique(yCoords.begin(), yCoords.end());
  yCoords.erase(itr1, yCoords.end());

  long long totalArea = 0;
  for (long *arr : windows) {
    long x1 = arr[0], y1 = arr[1], x2 = arr[2], y2 = arr[3], tint = arr[4];

    // finding all the "vertices" that are within this "window's" area
    // each unit/square is represented by its top left vertex
    // (stop loop before the bottom right vertex because the bottom right vertex represents a square outside the window)
    for (int xIdx = binarySearch(x1, xCoords);
    xCoords.at(xIdx) < x2 && xIdx < xCoords.size()-1; xIdx++) {

      for (int yIdx = binarySearch(y1, yCoords);
      yCoords.at(yIdx) < y2 && yIdx < yCoords.size()-1; yIdx++) {

        // if this section has already reached T before, don't add it to total (preventing double adding)
        if (tintGrid[xIdx][yIdx] < T) {
          if (tintGrid[xIdx][yIdx] + tint >= T) {
            // add the area of this section which is the area between top left vertex and bottom right vertex
            totalArea += (xCoords.at(xIdx + 1) - xCoords.at(xIdx)) * (yCoords.at(yIdx + 1) - yCoords.at(yIdx));
          }
        }
        tintGrid[xIdx][yIdx] += tint;
      }
    }
  }
  cout << totalArea << '\n';

  return 0;
}