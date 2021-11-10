#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int ed;
LL sum[100], ans[100];

void build() {
    LL now = 9;
    for (ed = 1; ; ed++) {
        sum[ed] = sum[ed - 1] + now;
        if (ed % 2 == 0) {
            now *= 10;
        }
        if (sum[ed] > 2e9) {
            break;
        }
    }
}

int main() {
    build();
    LL n;
    while (cin >> n && n) {
        int len = lower_bound(sum, sum + ed + 1, n) - sum;
        n -= sum[len - 1] + 1;
        int cnt = len / 2 + 1;

        while (n) {
            ans[cnt++] = n % 10;
            n /= 10;
        }

        for (int i = cnt; i <= len; i++) {
            ans[i] = 0;
        }
        ans[len]++;
        for (int i = 1; i <= len / 2; i++) {
            ans[i] = ans[len - i + 1];
        }
        for (int i = 1; i <= len; i++) {
            cout << ans[i];
        }
        cout << "\n";
    }
}