#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e4 + 5;

struct Edge {
    int from;
    int to;
    int w;
    Edge(int _from, int _to, int _w) : from(_from), to(_to), w(_w) {}
    bool operator < (const Edge &other) const {
        return w > other.w;
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
    for (int i = 1; i <= n; i++) {
        boss[i] = -1;
    }

    //count the edges not on the maximum spanning tree
    int ans = 0;
    for (auto e : edges) {
        if (!uni(e.from, e.to)) {
            ans += e.w;
        }
    }
    return ans;
}

int main() {
    int T;
    while (cin >> T && T) {
        while (T--) {
            cin >> n >> m;
            edges.clear();
            int from, to, w;
            for (int i = 0; i < m; i++) {
                cin >> from >> to >> w;
                edges.emplace_back(from, to, w);
            }
            cout << kruskal() << '\n';
        }
    }
}