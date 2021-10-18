#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
#define pb push_back

int main() { IOS
    int T, n;
    cin >> T;
    while (T--) {
        cin >> n;
        int one = 0, two = 0;
        for (int i = 0, x; i < n; i++) {
            cin >> x;
            if (x == 1) {
                one++;
            } else {
                two++;
            }
        }
        
        if (one % 2 != 0 || (one == 0 && two % 2 != 0)) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
}