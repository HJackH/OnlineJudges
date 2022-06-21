#include <bits/stdc++.h>
using namespace std;
using LL = long long;

LL n, k, limit;

LL pow10(int e) {
    LL ret = 1, base = 10;
    while (e > 0) {
        if (e & 1) {
            ret *= base;
        }
        base *= base;
        e >>= 1;
    }
    return ret;
}

LL mul(LL x) {
    x *= x;
    while (x >= limit) {
        x /= 10;
    }
    return x;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> k;
        limit = pow10(n);

        LL ans = k, tmp = k;
        unordered_set<LL> st;
        while (!st.count(tmp)) {
            st.insert(tmp);
            ans = max(ans, tmp);
            tmp = mul(tmp);
        }
        cout << ans << "\n";
    }
}
