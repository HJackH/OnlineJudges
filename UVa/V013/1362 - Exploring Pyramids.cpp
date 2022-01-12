#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const LL MOD = 1e9;
const int MAXN = 300 + 5;

string s;
LL dp[MAXN][MAXN];

LL sol(int l, int r) {
    if (l > r || s[l] != s[r]) {
        return 0;
    }
    if (l == r) {
        return 1;
    }
    auto &ans = dp[l][r];
    if (ans != -1) {
        return ans;
    }
    ans = 0;
    for (int k = l + 2; k <= r; k++) {
        ans += sol(l + 1, k - 1) * sol(k, r) % MOD;
        ans %= MOD;
    }
    return ans;
}

int main() {
    while (cin >> s) {
        memset(dp, -1, sizeof(dp));
        cout << sol(0, s.size() - 1) << "\n";
    }
}