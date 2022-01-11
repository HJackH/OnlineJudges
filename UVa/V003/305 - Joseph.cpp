#include <bits/stdc++.h>
using namespace std;
const int MAXN = 13;

int ans[MAXN + 5];

bool jo(int k, int m) {
    int st = 0, n = 2 * k;
    while (n > k) {
        st = (st + m - 1) % n;
        if (st < k) {
            return false;
        }
        n--;
    }
    return true;
}

int main() {
    for (int k = 1; k <= MAXN; k++) {
        for (int m = k + 1; ; m++) {
            if (jo(k, m)) {
                ans[k] = m;
                break;
            }
        }
    }
    int k;
    while (cin >> k && k) {
        cout << ans[k] << "\n";
    }
}