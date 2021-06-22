#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
#define pb push_back
#define sz(x) int((x).size())

LL extgcd(LL a, LL b, LL &x, LL &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    LL d = extgcd(b, a % b, y, x);
    y -= (a / b) * x;
    return d;
}

int main() { IOS
    LL n, c1, n1, c2, n2;
    while (cin >> n && n) {
        cin >> c1 >> n1 >> c2 >> n2;
        LL x, y;
        LL gcd = extgcd(n1, n2, x, y);

        LL up = floor(1.0 * n * y / n1);
        LL down = ceil(-1.0 * n * x / n2);

        if (n % gcd || down > up) {
            cout << "failed\n";
            continue;
        }

        LL k = (c1 * n2 - c2 * n1 >= 0) ? down : up;
        x = x * n / gcd + k * n2 / gcd;
        y = y * n / gcd - k * n1 / gcd;
        cout << x << " " << y << "\n";
    }
}