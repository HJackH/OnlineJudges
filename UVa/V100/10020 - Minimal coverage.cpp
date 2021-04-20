#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
#define pb push_back
#define eb emplace_back

struct Line {
    int l;
    int r;
    Line(int _l, int _r) : l(_l), r(_r) {}
    bool operator < (const Line &other) const {
        if (l == other.l) {
            return r > other.r;
        }
        return l < other.l;
    }
};

int n, m;
vector<Line> lines;

void sol() {
    int l = 0, r, i = 0;
    vector<int> ans;
    while (l < m) {
        r = l;
        int choose = -1;
        while (i < n && lines[i].l <= l) {
            if (lines[i].r > r) {
                r = lines[i].r;
                choose = i;
            }
            i++;
        }
        if (choose == -1) {
            cout << "0\n";
            return;
        }
        ans.pb(choose);
        l = r;
    }

    cout << ans.size() << "\n";
    for (int j : ans) {
        cout << lines[j].l << " " << lines[j].r << "\n";
    }
}

int main() { IOS
    int T;
    cin >> T;
    while (T--) {
        cin >> m;

        lines.clear();
        int l, r;
        while (cin >> l >> r && (l || r)) {
            lines.eb(l, r);
        }
        n = lines.size();
        sort(lines.begin(), lines.end());

        sol();

        if (T) {
            cout << "\n";
        }
    }
}