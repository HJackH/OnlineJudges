#include <bits/stdc++.h>
using namespace std;

long long n, l, u;

int main() {
    while (cin >> n >> l >> u) {
        long long ans = 0;
        for (int i = 31; i >= 0; i--) {
            long long tmp = 1LL << i;
            if (n & tmp) { // 1
                if ((ans + tmp) <= l) {
                    ans += tmp;
                }
            } else { // 0
                if ((ans + tmp) <= u) {
                    ans += tmp;
                }
            }
        }
        cout << ans << endl;
    }
}
