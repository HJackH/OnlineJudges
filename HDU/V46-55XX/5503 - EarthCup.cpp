#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);

const int MAXN = 50000 + 5;

int n, a[MAXN];

bool chk() {
    LL sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += a[i];
        if (sum < ((LL)i * (i - 1) / 2)) {
            return false;
        }
    }
    if (sum != ((LL)n * (n - 1) / 2)) {
        return false;
    }
    return true;
}

int main() {
    IOS
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        sort(a + 1, a + n + 1);
        if (chk()) {
            cout << "It seems to have no problem.\n";
        } else {
            cout << "The data have been tampered with!\n";
        }
    }
}