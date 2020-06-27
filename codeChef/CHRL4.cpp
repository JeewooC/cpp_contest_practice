#include <algorithm>
#include <climits>
#include <iostream>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    long specialNumbers[N];
    for (int i = 0; i < N; i++) {
        cin >> specialNumbers[i];
    }
    
    long long d[N];
    fill_n(d, N, LONG_LONG_MAX);    
    d[0] = specialNumbers[0];

    for (int currentIndex = 0; currentIndex < N-1; currentIndex++) {
        for (int j = currentIndex+1; j-currentIndex <= K; j++) {
            if (j >= N) {
                break;
            }
            if (d[currentIndex] * specialNumbers[j] < d[j]) {
                d[j] = d[currentIndex] * specialNumbers[j];
            }
        }
    }

    cout << d[N-1]%1000000007 << endl;
}
