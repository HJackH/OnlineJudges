#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[35];

void sol() {
    if (n <= 1 || m <= 1) {
        cout << "Boring!\n";
        return;
    }
    a[1] = n;
    for (int i = 2; i < 35; i++) {
        if (a[i - 1] % m != 0) {
            cout << "Boring!\n";
            return;
        }
        a[i] = a[i - 1] / m;
        if (a[i] == 1) {
            break;
        }
    }

    cout << a[1];
    for (int i = 2; i < 35; i++) {
        cout << " " << a[i];
        if (a[i] == 1) {
            break;
        }
    }
    cout << "\n";
}

int main() {
    while (cin >> n >> m) {
        sol();
    }
}