#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e4;

long long d[MAXN + 5];

void solve() {
    d[0] = 1;
    for (int i = 1; i <= MAXN; i++) {
        d[i] = d[i - 1] * i;
        while (d[i] % 10 == 0) {
            d[i] /= 10;
        }
        d[i] %= 1000000;
    }
}

int main() {
    solve();

    int n;
    while (cin >> n) {
        printf("%5d -> %lld\n", n, d[n] % 10);
    }
}