#include <bits/stdc++.h>
using namespace std;

int n;
string s;

bool chk(int k) {
    int times = n / k;
    for (int i = 1; i < times; i++) {
        int st = i * k;
        for (int j = 0; j < k; j++) {
            if (s[j] != s[j + st]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> s;
        n = s.size();
        for (int k = 1; k <= n; k++) {
            if (n % k == 0 && chk(k)) {
                cout << k << "\n";
                break;
            }
        }
        if (T) {
            cout << "\n";
        }
    }
}