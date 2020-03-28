#include <bits/stdc++.h>
using namespace std;

int T, n;
long long k;
set<long long> S;

long long pow10(int e) {
    long long res = 1, base = 10;
    while (e > 0) {
        if (e & 1) {
            res *= base;
        }
        base *= base;
        e >>= 1;
    }
    return res;
}

int main() {
    cin >> T;
    while (T--) {
        cin >> n >> k;
        S.clear();
        long long ans = k, tmp = k;
        
        while (!S.count(tmp)) {
            ans = max(ans, tmp);
            S.insert(tmp);
            tmp *= tmp;
            tmp = tmp / pow10(log10(tmp) + 1 - n);
        }

        cout << ans << '\n';
    }
}
