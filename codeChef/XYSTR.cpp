#include <iostream>
using namespace std;

int query(string row) {
    int total = 0;
    for (int i = 0; i < row.length(); i++) {
        if (row.at(i) == 'x') {
            if (i < row.length()-1 && row.at(i+1) == 'y') {
                total++;
                i++;
            }
        } else {
            if (i < row.length()-1 && row.at(i+1) == 'x') {
                total++;
                i++;
            }
        }
    }
    return total;
}

int main() {
    int T; cin >> T;
    for (int i = 0; i < T; i++) {
        string row; cin >> row;
        cout << query(row) << endl;
    }
}
