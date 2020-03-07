#include <bits/stdc++.h>
using namespace std;

int T, n, a[20], tmp[20];

bool chkZero() {
    for (int i = 0; i < n; i++) {
        if (a[i] != 0) {
            return false;
        }
    }
    return true;
}

void nextArr() {
    memcpy(tmp, a, n * sizeof(int));

    for (int i = 0; i < n; i++) {
        a[i] = abs(tmp[i] - tmp[(i + 1) % n]);
    }
}

int main() {
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        bool flag = chkZero();

        if (!flag) {
            for (int i = 1; i <= 1000 && !flag; i++) {
                nextArr();
                flag = chkZero();
            }
        }

        if (flag) {
            cout << "ZERO" << endl;
        } else {
            cout << "LOOP" << endl;
        }
    }
}