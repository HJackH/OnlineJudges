#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);

LL SG(LL x) {
    if (x & 1) {
        return SG(x >> 1);
    }
    return x >> 1;
}

int main() { IOS
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        LL ans = 0, tmp;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            ans ^= SG(tmp);
        }
        if (ans) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }  
}