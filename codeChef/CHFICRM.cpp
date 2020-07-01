#include <iostream>
using namespace std;

bool query(int N, int arr[]) {
    if (arr[0] != 5) {
        return false;
    }
    int count5 = 1, count10 = 0, count15 = 0;
    for (int i = 1; i < N; i++) {
        if (arr[i] == 5) {
            count5++;
        } else if (arr[i] == 10) {
            if (count5 >= 1) {
                count5--;
                count10++;
            } else {
                return false;
            }
        } else if (arr[i] == 15) {
            if (count10 >= 1) {
                count10--;
                count15++;
            } else if (count5 >= 2) {
                count5 -= 2;
                count15++;
            } else {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int N;
        cin >> N;
        int arr[N];
        for (int j = 0; j < N; j++) {
            cin >> arr[j];
        }
        
        if (query(N, arr)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}
