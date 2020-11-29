#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
const int MAXN = 1e4 + 5;

int n, at[MAXN];

bool chk() {
    for (int i = 0; i < n; i++) {
        for (int j = 1; i + 2 * j < n; j++) {
            if ((at[i] < at[i + j] && at[i + j] < at[i + 2 * j]) || 
                (at[i] > at[i + j] && at[i + j] > at[i + 2 * j])) {
                return false;
            }
        }
    }
    return true;
}

int main() { IOS
    while (cin >> n && n) {
        cin.ignore(1);
        for (int i = 0, x; i < n; i++) {
            cin >> x;
            at[x] = i;
        }
        if (chk()) {
            cout << "yes\n";
        } else {
            cout << "no\n";
        }
    }
}