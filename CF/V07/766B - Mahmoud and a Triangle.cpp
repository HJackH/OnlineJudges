#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);

const int MAXN = 1e5 + 5;

int n, a[MAXN];

int main() {
    IOS

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);

    bool chk = false;
    for (int i = 2; i < n; i++) {
        if (a[i - 2] + a[i - 1] > a[i]) {
            chk = true;
            break;
        }
    }

    if (chk) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}