#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
const int MAXN = 1e4 + 5;

struct Gas {
    int l;
    int r;
    bool operator < (const Gas &other) const {
        return l < other.l;
    }
};

int l, g;
Gas gases[MAXN];

int main() { IOS
    while (cin >> l >> g && (l || g)) {
        int x, r;
        for (int i = 0; i < g; i++) {
            cin >> x >> r;
            gases[i].l = max(x - r, 0);
            gases[i].r = min(x + r, l);
        }

        sort(gases, gases + g);

        int ml = 0, mr = 0, cnt = 0, i = 0;
        while (ml < l) {
            mr = ml;
            while (ml >= gases[i].l && i < g) {
                if (gases[i].r > mr) {
                    mr = gases[i].r;
                }
                ++i;
            }
            if (ml == mr) {
                break;
            }
            ml = mr;
            ++cnt;
        }

        if (ml < l) {
            cout << "-1\n";
        } else {
            cout << g - cnt << '\n';
        }
    }
}