#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);

const int MAXN = 50 + 5;

int n, a[MAXN];

int main() {
    IOS
    int kase = 0;
    while (cin >> n && n) {
        int ans = 0, avg = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            avg += a[i];
        }
        avg /= n;
        for (int i = 0; i < n; i++) {
            ans += abs(a[i] - avg);
        }
        cout << "Set #" << ++kase << '\n';
        cout << "The minimum number of moves is " << ans / 2 << ".\n\n";
    }
}