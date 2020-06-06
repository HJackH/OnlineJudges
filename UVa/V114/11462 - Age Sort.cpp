#include <bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(0); cin.tie(0);

const int MAXN = 2000000 + 5;

int n, a[MAXN], s[100 + 5];

int main() {
    IOS
    while (cin >> n && n) {
        memset(s, 0, sizeof(0));

        int mx = -1;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            mx = max(mx, a[i]);
            s[a[i]]++;
        }

        for (int i = 0, cnt = 0; i <= mx; i++) {
            while (s[i] > 0) {
                cout << i;
                if (cnt != n - 1) {
                    cout << ' ';
                }
                cnt++;
                s[i]--;
            }
        }
        cout << '\n';
    }
}