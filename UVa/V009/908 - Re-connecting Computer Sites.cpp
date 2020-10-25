#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
#define eb emplace_back
const int MAXN = 1e6 + 5;

struct Edge {
    int u;
    int v;
    int w;
    Edge (int tu, int tv, int tw) : u(tu), v(tv), w(tw) {}
    bool operator < (const Edge &other) const {
        return w < other.w;
    }
};

int n, m, k, boss[MAXN];
vector<Edge> edges;

int find(int x) {
    if (boss[x] < 0) {
        return x;
    }
    return boss[x] = find(boss[x]);
}

bool uni(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) {
        return false;
    }
    if (boss[x] > boss[y]) {
        swap(x, y);
    }
    boss[x] += boss[y];
    boss[y] = x;
    return true;
}

int kruskal() {
    sort(edges.begin(), edges.end());

    int ans = 0, cnt = 0;
    for (auto e: edges) {
        if (uni(e.u, e.v)) {
            ans += e.w;
            if (++cnt == n - 1) {
                break;
            }
        }
    }
    return ans;
}

int main() { IOS
    int u, v, w, first = 1;
    while (cin >> n) {
        edges.clear();
        for (int i = 0; i <= n; i++) {
            boss[i] = -1;
        }

        int ans1 = 0, ans2 = 0;
        for (int i = 1; i < n; i++) {
            cin >> u >> v >> w;
            ans1 += w;
        }

        cin >> k;
        for (int i = 0; i < k; i++) {
            cin >> u >> v >> w;
            edges.eb(u, v, w);
        }

        cin >> m;
        for (int i = 0; i < m; i++) {
            cin >> u >> v >> w;
            edges.eb(u, v, w);
        }

        ans2 = kruskal();

        if (!first) {
            cout << '\n';
        }
        first = 0;
        cout << ans1 << '\n' << ans2 << '\n';
    }
}