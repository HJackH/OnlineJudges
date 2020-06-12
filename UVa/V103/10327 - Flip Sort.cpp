#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000 + 5;

int n, a[MAXN];

int main() {
    while (cin >> n) {
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int ans = 0;
        for (int t = 0; t < n; t++) {
            for (int i = 1; i < n; i++) {
                if (a[i - 1] > a[i]) {
                    swap(a[i - 1], a[i]);
                    ans++;
                }
            }
        }

        cout << "Minimum exchange operations : " << ans << '\n';
    }
}