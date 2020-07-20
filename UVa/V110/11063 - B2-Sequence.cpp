#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100 + 5;

int n, a[MAXN];
unordered_set<int> S;

int main() {
    int kase = 0;
    while (cin >> n) {
        S.clear();
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }

        bool isB = true;
        for (int i = 1; i <= n && isB; i++) {
            if (a[i - 1] >= a[i]) {
                isB = false;
            }
            for (int j = i; j <= n && isB; j++) {
                int sum = a[i] + a[j];
                if (S.count(sum)) {
                    isB = false;
                } else {
                    S.insert(sum);
                }
            }
        }
        
        cout << "Case #" << ++kase << ": It is " << (isB ? "" : "not ") << "a B2-Sequence.\n\n";
    }
}