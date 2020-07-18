#include <bits/stdc++.h>
using namespace std;

long long f, sz, n, value;

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> f;
        long long ans = 0;
        for (int i = 0; i < f; i++) {
            cin >> sz >> n >> value;
            ans += sz * value;
        }
        cout << ans << '\n';
    }
}