#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);

LL n, ord;
string s;

LL mpow(LL a, LL b) {
    LL ans = 1;
    while (b) {
        if (b & 1) {
            ans *= a;
        }
        a *= a;
        b >>= 1;
    }
    return ans;
}

int main() { IOS
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        s = to_string(n);
        ord = s.length();

        LL sum = 0;
        for (char c: s) {
            sum += mpow(c - '0', ord);
        }

        if (sum != n) {
            cout << "Not ";    
        }
        cout << "Armstrong\n";
    }
}