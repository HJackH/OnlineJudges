#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10000 + 5;

int n, a[MAXN], tmp[MAXN];

void solve(int L, int R) {
    if (L == R) {
        return;
    }

    for (int i = L; i <= R; i++) {
        tmp[i] = a[i];
    }

    int mid = (L + R) / 2;
    for (int i = L, j = L; i <= mid; i++, j += 2) {
        a[i] = tmp[j];
    }
    for (int i = mid + 1, j = L + 1; i <= R; i++, j += 2) {
        a[i] = tmp[j];
    }

    solve(L, mid);
    solve(mid + 1, R);
}

int main() {
    while (cin >> n && n) {
        for (int i = 0; i < n; i++) {
            a[i] = i;
        }
        solve(0, n - 1);

        cout << n << ':';
        for (int i = 0; i < n; i++) {
            cout << ' ' << a[i];
        }
        cout << '\n';
    }
}