#include <bits/stdc++.h>
using namespace std;

const int MAXN = 500000 + 5;

int n, a[MAXN], tmp[MAXN];
long long cnt;

void solve(int L, int R) {
    if (L == R) {
        return;
    }
    int mid = (L + R) / 2;
    solve(L, mid);
    solve(mid + 1, R);

    int tl = L, tr = mid + 1, tk = 0;
    while (tk < (R - L + 1)) {
        if (tl <= mid && tr <= R) {
            if (a[tl] <= a[tr]) {
                tmp[tk] = a[tl];
                tl++;
            } else {
                tmp[tk] = a[tr];
                tr++;
                cnt += mid - tl + 1;
            }
        } else if (tl <= mid) {
            tmp[tk] = a[tl];
            tl++;
        } else {
            tmp[tk] = a[tr];
            tr++;
        }
        tk++;
    }

    for (int i = L; i <= R; i++) {
        a[i] = tmp[i - L];
    }
}

int main() {
    while (cin >> n && n) {
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        cnt = 0;
        solve(0, n - 1);
        cout << cnt << '\n';
    }
}