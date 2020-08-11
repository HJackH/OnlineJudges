#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);

const int MAXN = 30 + 5;

int n, a[MAXN];
unordered_set<int> Sa, S;

bool chk() {
    S.clear();
    for (int i = 1; i <= n; i++) {
        if (a[i - 1] >= a[i]) {
            return false;
        }
        int tmp = a[i];
        for (auto j : S) {
            if (Sa.count(tmp + j)) {
                return false;
            }
            S.insert(tmp + j);
        }
        S.insert(tmp);
    }
    return true;
}

int main() {
    IOS
    int kase = 0;
    while (cin >> n) {
        Sa.clear();
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            Sa.insert(a[i]);
        }
        cout << "Case #" << ++kase << ":";
        for (int i = 1; i <= n; i++) {
            cout << ' ' << a[i];
        }
        cout << "\nThis is " << (chk() ? "" : "not ") << "an A-sequence.\n";  
    }
}