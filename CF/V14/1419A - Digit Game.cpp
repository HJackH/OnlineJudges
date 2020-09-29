#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);

int main() {
    IOS

    int T, n;
    string s;

    cin >> T;
    while (T--) {
        cin >> n >> s;

        int cnt[2][2] = {0};
        for (int i = 0; i < n; i++) {
            ++cnt[i & 1][(s[i] - '0') & 1];
        }

        if (cnt[!(n & 1)][n & 1]) {
            cout << 2 - (n & 1) << '\n';
        } else {
            cout << 2 - !(n & 1) << '\n';
        }
    }
}