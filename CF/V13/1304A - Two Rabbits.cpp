#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);

int x, y, a, b;

int main() { IOS
    int T;
    cin >> T;
    while (T--) {
        cin >> x >> y >> a >> b;
        int len = y - x;
        if (len % (a + b) == 0) {
            cout << len / (a + b) << '\n';
        } else {
            cout << "-1\n";
        }
    }
}