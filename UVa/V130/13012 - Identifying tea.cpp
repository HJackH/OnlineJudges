#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);

int main() {
    IOS

    int T;
    while (cin >> T) {
        int ans = 0;
        for (int i = 0, tmp; i < 5; i++) {
            cin >> tmp;
            if (tmp == T) {
                ++ans;
            }
        }
        cout << ans << '\n';
    }
}