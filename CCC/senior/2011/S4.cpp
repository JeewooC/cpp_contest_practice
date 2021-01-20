#include <bits/stdc++.h>
using namespace std;

int total = 0;
long bloods[8] = {0};
long patients[8] = {0};

void bGp(int bIdx, int pIdx) {
  total += patients[pIdx];
  bloods[bIdx] -= patients[pIdx];
  patients[pIdx] = 0;
}

void pGb(int bIdx, int pIdx) {
  total += bloods[bIdx];
  patients[pIdx] -= bloods[bIdx];
  bloods[bIdx] = 0;
}

void extraBlood(int bIdx, int pIdx) {
  if (bloods[bIdx] >= patients[pIdx]) {
    bGp(bIdx, pIdx);
  } else {
    pGb(bIdx, pIdx);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  // -----------------------------
  for (int i = 0; i < 8; i++) {
    int b; cin >> b;
    bloods[i] = b;
  }
  for (int i = 0; i < 8; i++) {
    int p; cin >> p;
    patients[i] = p;
  }

  // O- patients need O-
  if (bloods[0] >= patients[0]) {
    bGp(0, 0);
  } else {
    pGb(0, 0);
  }
  // O+ patients can have O+ or O-
  if (bloods[1] >= patients[1]) {
    bGp(1, 1);
  } else {
    // Give O+
    pGb(1, 1);
    // Give O-
    extraBlood(0, 1);
  }
  // A- patients can have A- or O-
  if (bloods[2] >= patients[2]) {
    bGp(2, 2);
  } else {
    // Give A-
    pGb(2, 2);
    // Give O-
    extraBlood(0, 2);
  }
  // B- patients can have B- or O-
  if (bloods[4] >= patients[4]) {
    bGp(4, 4);
  } else {
    // Give B-
    pGb(4, 4);
    // Give O-
    extraBlood(0, 4);
  }
  // AB- patients can have AB- or O- or A- or B-
  if (bloods[6] >= patients[6]) {
    bGp(6, 6);
  } else {
    // Give AB-
    pGb(6, 6);
    // Give O-
    extraBlood(0, 6);
    // Give A- and B-
    if (bloods[2] > bloods[4]) {
      extraBlood(2, 6);
      extraBlood(4, 6);
    } else {
      extraBlood(4, 6);
      extraBlood(2, 6);
    }
  }
  // A+ patients can have A+ or A- or O+ or O-
  if (bloods[3] >= patients[3]) {
    bGp(3, 3);
  } else {
    // Give A+
    pGb(3, 3);
    // Give A-
    extraBlood(2, 3);
    // Give O+
    extraBlood(1, 3);
    // Give O-
    extraBlood(0, 3);
  }
  // B+ patients can have B+ or B- or O+ or O-
  if (bloods[5] >= patients[5]) {
    bGp(5, 5);
  } else {
    // Give B+
    pGb(5, 5);
    // Give B-
    extraBlood(4, 5);
    // Give O+
    extraBlood(1, 5);
    // Give O-
    extraBlood(0, 5);
  }
  // AB+ patients can all leftovers
  if (bloods[7] >= patients[7]) {
    bGp(7, 7);
  } else {
    // Give AB+
    pGb(7, 7);
    // Give all leftovers until AB+ patients is zero or go through all the bloods
    int counter = 0;
    while (patients[7] > 0 && counter < 7) {
      extraBlood(counter, 7);
      counter++;
    }
  }

  cout << total << '\n';

  // -----------------------------
  return 0;
}


// O- O+ A- A+ B- B+ AB- AB+
// 0  1  2  3  4  5  6   7



// 4 0 0 0 0 0 0 27

// O- 2
// total 2
// O+ 28
// total 30
// A- 12(A-)+23(O-)
// total 65
// B- 5
// total 70
// AB- 36(AB-)+6(O-)
// total 112
// A+ 15(A+)+7(O+)+1(O-)
// total 135
// B+ 35(B+)+3(B-)+5(O-)
// total 178
// AB+ 16