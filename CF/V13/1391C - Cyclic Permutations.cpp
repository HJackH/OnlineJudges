#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
#define pb push_back
const LL MOD = 1e9 + 7;

LL fac(LL n) {
    LL ans = 1;
    for (LL i = 1; i <= n; i++) {
        ans = (ans * i) % MOD;
    }
    return ans;
}

LL pow2(LL n) {
    LL ans = 1, base = 2;
    while (n) {
        if (n & 1) {
            ans = (ans * base) % MOD;
        }
        base = (base * base) % MOD;
        n >>= 1;
    }
    return ans;
}

int main() { IOS
    LL n;
    cin >> n;
    cout << (fac(n) - pow2(n - 1) + MOD) % MOD << '\n';
}