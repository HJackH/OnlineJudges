#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000 + 5;

struct Soldier {
    int b;
    int j;
    bool operator < (const Soldier &other) const {
        return j > other.j;
    }
};

int n;
Soldier a[MAXN];

int main() {
    int kase = 0;
    while (cin >> n && n) {
        for (int i = 0; i < n; i++) {
            cin >> a[i].b >> a[i].j;
        }
        sort(a, a + n);
        int ans = 0, time = 0;
        for (int i = 0; i < n; i++) {
            time += a[i].b;
            if (time + a[i].j > ans) {
                ans = time + a[i].j;
            }
        }
        cout << "Case " << ++kase << ": " << ans << "\n";
    }
}