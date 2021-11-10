#include <bits/stdc++.h>
using namespace std;

int jo(int n, int k) {
    return n > 1 ? (jo(n - 1, k) + k) % n : 0;
}

int main() {
    int n, k, m;
    while (cin >> n >> k >> m && (n || k || m)) {
        int ans = jo(n, k);
        ans = ((ans - k + m) % n + n) % n + 1;
        cout << ans << "\n";
    }
}