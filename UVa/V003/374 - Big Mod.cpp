#include <bits/stdc++.h>
using namespace std;

long long b, p, m;

int main() {
    while (cin >> b >> p >> m) {
        long long ans = 1;
        while (p) {
            if (p & 1) {
                ans = (ans * b) % m;
            }
            b = (b * b) % m;
            p >>= 1;
        }
        cout << ans << '\n';
    }
}