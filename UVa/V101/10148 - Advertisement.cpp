#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000 + 5;
const int MAXL = 1e4;

struct Man {
    int l;
    int r;
    bool operator < (const Man &other) const {
        if (r == other.r) {
            return l > other.l;
        }
        return r < other.r;
    }
};

int k, n;
Man mans[MAXN];
bool vis[MAXL * 2 + 5];

int qry(int l, int r) {
    int ret = 0;
    for (int i = l; i <= r; i++) {
        ret += vis[i];
    }
    return ret;
}

void fill(int st, int cnt) {
    for (int i = st; i >= 0 && cnt > 0; i--) {
        if (!vis[i]) {
            vis[i] = 1;
            cnt--;
        }
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> k >> n;

        int ls = MAXL * 2, rs = -MAXL * 2;
        for (int i = 0, l, r; i < n; i++) {
            cin >> l >> r;
            mans[i].l = min(l, r) + MAXL;
            mans[i].r = max(l, r) + MAXL;
            ls = min(ls, mans[i].l);
            rs = max(rs, mans[i].r);
        }

        sort(mans, mans + n);

        for (int i = ls; i <= rs; i++) {
            vis[i] = 0;
        }

        for (int i = 0; i < n; i++) {
            auto &m = mans[i];
            if (m.r - m.l < k) {
                for (int j = m.l; j <= m.r; j++) {
                    vis[j] = 1;
                }
            } else {
                int in = qry(m.l, m.r);
                if (in >= k) {
                    continue;
                }
                in = k - in;
                fill(m.r, in);
            }
        }

        vector<int> ans;
        for (int i = ls; i <= rs; i++) {
            if (vis[i]) {
                ans.push_back(i - MAXL);
            }
        }

        cout << ans.size() << "\n";
        for (int i : ans) {
            cout << i << "\n";
        }

        if (T) {
            cout << "\n";
        }
    }
}