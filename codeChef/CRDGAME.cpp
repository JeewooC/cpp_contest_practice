#include <bits/stdc++.h>
using namespace std;

// rules of the game
// two piles of cards: Chef's pile A, Morty's pile B
// each has N cards in it
// power of a card: sum of digits of the integer on that card
// game consists of N rounds
// both players draw a card from the top of their pile
// player with higher power card wins and gets a point
// if two powers are equal then they both get 1 point
// player with more points at the end of N rounds win

int main() {
  int T; cin >> T;
  for (int t = 0; t < T; t++) {
    int N; cin >> N;
    int chefScore = 0, mortyScore = 0;
    for (int i = 0; i < N; i++) {
      int A, B;
      cin >> A >> B;
      int ADigits = 0, BDigits = 0;
      while (A > 0) {
        ADigits += A%10;
        A /= 10;
      }
      while (B > 0) {
        BDigits += B%10;
        B /= 10;
      }
      if (ADigits > BDigits) {
        chefScore++;
      } else if (BDigits > ADigits) {
        mortyScore++;
      } else {
        chefScore++;
        mortyScore++;
      }
    }
    if (chefScore > mortyScore) {
      cout << 0 << " " << chefScore << endl;
    } else if (mortyScore > chefScore) {
      cout << 1 << " " << mortyScore << endl;
    } else {
      cout << 2 << " " << chefScore << endl;
    }
  }
}