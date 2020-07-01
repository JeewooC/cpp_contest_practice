#include <algorithm>
#include <climits>
#include <iostream>
#include <math.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    long specialNumbers[N];
    for (int i = 0; i < N; i++) {
        cin >> specialNumbers[i];
    }
    
    long d[N];
    fill_n(d, N, LONG_MAX);
    if (specialNumbers[0] == 1) {
        d[0] = 1;
    } else {
        d[0] = log(specialNumbers[0]);
    }

    for (int currentIndex = 0; currentIndex < N-1; currentIndex++) {
        for (int j = currentIndex+1; j-currentIndex <= K; j++) {
            if (j >= N) {
                break;
            }
            if (d[currentIndex] * specialNumbers[j] == 1) {
                if (1 < d[j]) {
                    d[j] = 1;
                }
            } else {
                if (log(d[currentIndex] * specialNumbers[j]) < d[j]) {
                    d[j] = log(d[currentIndex] * specialNumbers[j]);
                }
            }
        }
    }

    long res = exp(d[N-1]);
    cout << res%1000000007 << endl;
}
