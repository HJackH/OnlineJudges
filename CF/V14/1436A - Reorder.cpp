#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);

int main() { IOS
    int T, n, m;
    cin >> T;
    while (T--) {
        int sum = 0;
        cin >> n >> m;
        for (int i = 0, tmp; i < n; i++) {
            cin >> tmp;
            sum += tmp;
        }
        if (sum == m) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}