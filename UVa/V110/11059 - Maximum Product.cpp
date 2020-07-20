#include <bits/stdc++.h>
using namespace std;

const int MAXN = 18 + 5;

int n;
long long a[MAXN];

int main() {
    int kase = 0;
    while (cin >> n) {
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        long long ans = 0;
        for (int i = 0; i < n; i++) {
            long long tmp = 1;
            for (int j = i; j < n; j++) {
                tmp *= a[j];
                ans = max(ans, tmp);
            }
        }
        cout << "Case #" << ++kase << ": The maximum product is " << ans << ".\n\n";
    }
}