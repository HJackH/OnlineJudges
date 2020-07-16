#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000 + 5;

struct Edge {
    Edge (int _from, int _to, int _w) : from(_from), to(_to), w(_w) {}
    int from;
    int to;
    int w;
    bool operator < (const Edge &other) const {
        return w < other.w;
    }
};

int n, m, boss[MAXN];
vector<Edge> edges, ans;

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

void kruskal() {
    for (int i = 0; i < n; i++) {
        boss[i] = -1;
    }
    sort(edges.begin(), edges.end());
    for (auto e : edges) {
        if (!uni(e.from, e.to)) {
            ans.emplace_back(e);
        }
    }
}

int main() {
    while (cin >> n >> m && (n || m)) {
        edges.clear();
        int from, to, w;
        for (int i = 0; i < m; i++) {
            cin >> from >> to >> w;
            edges.emplace_back(from, to, w);
        }

        ans.clear();
        kruskal();
        
        bool first = true;
        for (auto e : ans) {
            if (!first) {
                cout << ' ';
            }
            first = false;
            cout << e.w;
        }
        if (first) {
            cout << "forest";
        }
        cout << '\n';
    }
}