#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
const int MAXM = 15 + 5;

LL n, m, ans;
LL a[MAXM];

LL lcm(LL x, LL y) {
    return x / __gcd(x, y) * y;
}

void dfs(int i, int lv, LL mul) {
    if (mul > n) {
        return;
    }

    LL tmp = n / mul;
    if (lv & 1) {
        ans -= tmp;
    } else {
        ans += tmp;
    }

    for (int j = i + 1; j < m; j++) {
        dfs(j, lv + 1, lcm(a[j], mul));
    }
}

int main() { IOS
    while (cin >> n >> m) {
        for (int i = 0; i < m; i++) {
            cin >> a[i];
        }

        ans = 0;
        dfs(-1, 0, 1);
        cout << ans << '\n';
    }
}