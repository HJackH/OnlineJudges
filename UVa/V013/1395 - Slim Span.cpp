#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100 + 5;
const int INF = 1e9;

struct Edge {
    int from;
    int to;
    int weight;
    bool operator < (const Edge &other) const {
        return weight < other.weight;
    }
};

int n, m, ans;
int boss[MAXN];
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

bool kruskal(int st) {
    for (int i = 0; i <= n; i++) {
        boss[i] = -1;
    }

    int cnt = 0;
    for (int i = st; i < m; i++) {
        Edge e = edges[i];
        if (uni(e.from, e.to)) {
            if (++cnt == n - 1) {
                ans = min(ans, e.weight - edges[st].weight);
                return true;
            }
        }
    }
    return false;
}

int main() {
    while (cin >> n >> m && (n || m)) {
        edges.clear();

        int a, b, w;
        for (int i = 0; i < m; i++) {
            cin >> a >> b >> w;
            edges.push_back({a, b, w});
        }

        sort(edges.begin(), edges.end());

        ans = INF;
        for (int i = 0; i < m && kruskal(i); i++);

        if (ans == INF) {
            cout << "-1\n";
        } else {
            cout << ans << '\n';
        }
    }
}