#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;

struct Edge {
    int from;
    int to;
    int cost;
    Edge(int _from, int _to, int _cost) : from(_from), to(_to), cost(_cost) {}
    bool operator < (const Edge &other) const {
        return cost < other.cost;
    }
};

int n, m, boss[MAXN];
vector<Edge> edges;

int find(int x) {
    if (boss[x] < 0) {
        return x;
    }
    return boss[x] = find(boss[x]);
}

bool uni(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) {
        return false;
    }
    if (boss[a] > boss[b]) {
        swap(a, b);
    }
    boss[a] += boss[b];
    boss[b] = a;
    return true;
}

int kruskal() {
    sort(edges.begin(), edges.end());
    for (int i = 0; i < n; i++) {
        boss[i] = -1;
    }

    int ans = 0;
    for (auto e : edges) {
        //not
        if (!uni(e.from, e.to)) {
            ans += e.cost;
        }
    }
    return ans;
}

int main() {
    edges.reserve(MAXN);
    while (cin >> n >> m && (n || m)) {
        edges.clear();
        int a, b, w;
        for (int i = 0; i < m; i++) {
            cin >> a >> b >> w;
            edges.emplace_back(a, b, w);
        }

        cout << kruskal() << '\n';
    }
}