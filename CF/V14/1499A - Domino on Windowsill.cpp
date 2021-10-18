#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
#define pb push_back

int main() { IOS
    int T;
    cin >> T;
    while (T--) {
        int n, k1, k2, w, b;
        cin >> n >> k1 >> k2 >> w >> b;
        int sw = k1 / 2 + k2 / 2 + min(k1 % 2, k2 % 2);
        int sb = (n - k1) / 2 + (n - k2) / 2 + min((n - k1) % 2, (n - k2) % 2);
        if (sw >= w && sb >= b) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}