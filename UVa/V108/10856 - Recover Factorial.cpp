#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
const int MAXX = 3e6;

int n, cnt[MAXX + 5];

void table() {
    for (int i = 2; i < MAXX; i++) {
        if (!cnt[i]) {
            cnt[i] = 1;
            for (int j = 2; i * j < MAXX; j++) {
                cnt[i * j] = cnt[i] + cnt[j];
            }
        }
    }
    for (int i = 2; i < MAXX; i++) {
        cnt[i] += cnt[i - 1];
    }
}

int main() { IOS
    table();
    int kase = 0;
    while (cin >> n && n >= 0) {
        auto t = lower_bound(cnt, cnt + MAXX, n);
        cout << "Case " << ++kase << ": ";
        if (*t == n) {
            cout << int(t - cnt) << "!\n";
        } else {
            cout << "Not possible.\n";
        }
    }
}