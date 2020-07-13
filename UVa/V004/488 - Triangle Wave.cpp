#include <bits/stdc++.h>
using namespace std;

int n, m;

void prt() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cout << i;
        }
        cout << '\n';
    }
    for (int i = n - 1; i >= 1; i--) {
        for (int j = i; j >= 1; j--) {
            cout << i;
        }
        cout << '\n';
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        for (int i = 0; i < m; i++) {
            prt();
            if (i != m - 1) {
                cout << '\n';
            }
        }
        if (T) {
            cout << '\n';
        }
    }
}