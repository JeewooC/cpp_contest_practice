#include <iostream>
using namespace std;

int query(int N, int K, int arr[]) {
   int revenueLost = 0;
   for (int i = 0; i < N; i++) {
       if (arr[i] > K) {
           revenueLost += arr[i]-K;
       }
   }
   
    return revenueLost;
} 

int main() {
    int T; cin >> T;
    for (int i = 0; i < T ; i++) {
        int N, K;
        cin >> N >> K;
        int arr[N];
        for (int j = 0; j < N; j++) {
            cin >> arr[j];
        }
        cout << query(N, K, arr) << endl;
    }
}
