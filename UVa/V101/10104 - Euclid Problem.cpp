#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);

// ax + by = c
LL extgcd(LL a, LL b, LL c, LL &x, LL &y) {
  if (b == 0) {
    x = c / a;
    y = 0;
    return a;
  }
  LL d = extgcd(b, a % b, c, x, y);
  LL tmp = x;
  x = y;
  y = tmp - (a / b) * y;
  return d;
}

int main() { IOS
    LL a, b, x, y;
    while (cin >> a >> b) {
        LL d = extgcd(a, b, __gcd(a, b), x, y);
        cout << x << ' ' << y << ' ' << d << '\n';
    }
}