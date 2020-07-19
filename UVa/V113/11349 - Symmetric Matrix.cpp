#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100 + 5;

int n;
long long matrix[MAXN][MAXN];

bool chk() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i + 1; j++) {
            if (matrix[i][j] < 0 || matrix[i][j] != matrix[n - 1 - i][n - 1 - j]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int T;
    cin >> T;
    for (int kase = 1; kase <= T; kase++) {
        char c;
        cin >> c >> c >> n;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }

        cout << "Test #" << kase << ": ";
        if (chk()) {
            cout << "Symmetric.\n";
        } else {
            cout << "Non-symmetric.\n";
        }
    }
}