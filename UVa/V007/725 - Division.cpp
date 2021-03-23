#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
#define pb push_back

bool chk(string s1, string s2) {
    vector<int> cnt(10, 0);
    for (char c : s1) {
        ++cnt[c - '0'];
    }
    for (char c : s2) {
        ++cnt[c - '0'];
    }
    for (int i : cnt) {
        if (i != 1) {
            return false;
        }
    }
    return true;
}

int main() { IOS
    int n, first = 1;
    while (cin >> n && n) {
        if (!first) {
            cout << '\n';
        }
        first = 0;

        bool output = 0;
        for (int d = 1234, ed = 98765 / n; d <= ed; d++) {
            string ds = to_string(d);
            string us = to_string(n * d);
            if (us.length() == 4) {
                us = "0" + us;
            }
            if (ds.length() == 4) {
                ds = "0" + ds;
            }
            if (chk(us, ds)) {
                cout << us << " / " << ds << " = " << n << '\n';
                output = 1;
            }
        }

        if (!output) {
            cout << "There are no solutions for " << n << ".\n";
        }
    }
}