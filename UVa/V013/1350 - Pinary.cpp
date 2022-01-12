#include <bits/stdc++.h>
using namespace std;
const int MAXN = 40;

int n, f[MAXN + 5] = {0, 1}, sum[MAXN + 5] = {0, 1};

int main() {
    for (int i = 2; i <= MAXN; i++) {
        f[i] = f[i - 1] + f[i - 2];
        sum[i] = sum[i - 1] + f[i];
    }
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        int idx = lower_bound(sum, sum + MAXN + 1, n) - sum;
        for (int i = idx; i > 0; i--) {
            if (n > sum[i - 1]) {
                cout << "1";
                n -= sum[i - 1] + 1;
            } else {
                cout << "0";
            }
        }
        cout << "\n";
    }
}