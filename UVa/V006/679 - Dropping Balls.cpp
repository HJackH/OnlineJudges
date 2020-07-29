#include <bits/stdc++.h>
using namespace std;

int l, d, n;

int main() {
    while (cin >> l && l != -1) {
        while (l--) {
            cin >> d >> n;
            --n;
            int ans = 1;
            for (int i = 1; i < d; i++) {
                if (n & 1) {
                    ans = ans * 2 + 1;
                } else {
                    ans = ans * 2;
                }
                n >>= 1;
            }
            cout << ans << '\n';
        }
    }
}