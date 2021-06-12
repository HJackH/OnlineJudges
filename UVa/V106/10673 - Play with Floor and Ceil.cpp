#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
#define pb push_back
#define eb emplace_back
#define sz(x) int((x).size())

LL extgcd(LL a, LL b, LL c, LL &x, LL &y) {
    if (b == 0) {
        x = c / a;
        y = 0;
        return a;
    }
    LL d = extgcd(b, a % b, c, y, x);
    y -= (a / b) * x;
    return d;
}

int main() { IOS
    int T;
    LL x, y, a, b, c;
    cin >> T;
    while (T--) {
        cin >> x >> y;
        a = x / y;
        b = (x + y - 1) / y;
        c = x;
        LL gcd = extgcd(a, b, c, x, y);
        cout << x << " " << y << "\n";
    }
}