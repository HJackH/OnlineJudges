#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
const int MAXN = 1e4 + 5;

int n, r, back[MAXN];

int main() { IOS
    while (cin >> n >> r) {
        memset(back, 0, sizeof(back));
        for (int i = 0, b; i < r; i++) {
            cin >> b;
            back[b] = 1;
        }

        int chk = 0;
        for (int i = 1; i <= n; i++) {
            if (!back[i]) {
                chk = 1;
                cout << i << ' ';
            }
        }
        if (!chk) {
            cout << '*';
        }
        cout << '\n';
    }
}