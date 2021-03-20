#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
#define pb push_back

int main() { IOS
    int n, t;
    cin >> n >> t;
    if (t == 10) {
        if (n < 2) {
            cout << "-1\n";
        } else {
            cout << 10 << string(n - 2, '0') << '\n';
        }
        return 0;
    }
    cout << string(n, '0' + t) << '\n';
}