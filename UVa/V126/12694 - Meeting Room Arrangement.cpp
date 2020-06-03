#include <bits/stdc++.h>
using namespace std;

const int MAXN = 20 + 5;

struct Event{
    int st;
    int ed;
    bool operator < (const Event &other) const {
        return ed < other.ed;
    }
};

int n;
Event eve[MAXN + 5];

int main() {
    int T;
    cin >> T;
    while (T--) {
        n = 0;
        while (cin >> eve[n].st >> eve[n].ed && (eve[n].st || eve[n].ed)) {
            n++;
        }
        sort(eve, eve + n);

        int ans = 0, pre = 0;
        for (int i = 0; i < n; i++) {
            if (pre <= eve[i].st) {
                ans++;
                pre = eve[i].ed;
            }
        }
        cout << ans << '\n';
    }
}