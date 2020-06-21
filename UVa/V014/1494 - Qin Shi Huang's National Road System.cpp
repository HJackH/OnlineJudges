#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000 + 5;

struct City {
    int x;
    int y;
    int p;
};

struct Edge {
    int from;
    int to;
    double cost;
    bool operator < (const Edge &other) const {
        return cost < other.cost;
    }
};

int n, boss[MAXN];
bool vis[MAXN];
double maxcost[MAXN][MAXN];
City cities[MAXN];
vector<Edge> edges, G[MAXN];

double dis(int a, int b) {
    int dx = cities[a].x - cities[b].x;
    int dy = cities[a].y - cities[b].y;
    return sqrt(dx * dx + dy * dy);
}

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

double kruskal() {
    //init
    for (int i = 0; i < n; i++) {
        boss[i] = -1;
        G[i].clear();
    }
    edges.clear();

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            edges.push_back({i, j, dis(i, j)});
        }
    }
    sort(edges.begin(), edges.end());

    double ans = 0.0;
    int edgeCnt = 0;
    for (Edge e : edges) {
        if (uni(e.from, e.to)) {
            G[e.from].push_back({e.from, e.to, e.cost});
            G[e.to].push_back({e.to, e.from, e.cost});
            ans += e.cost;
            if (++edgeCnt == n - 1) {
                break;
            }
        }
    }
    return ans;
}

void dfs(int root, int now) {
    vis[now] = true;
    for (Edge e : G[now]) {
        if (!vis[e.to]) {
            maxcost[root][e.to] = max(maxcost[root][now], e.cost);
            dfs(root, e.to);
        }
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        
        for (int i = 0; i < n; i++) {
            cin >> cities[i].x >> cities[i].y >> cities[i].p;
        }

        double mstc = kruskal();
        memset(maxcost, 0, sizeof(maxcost));
        for (int i = 0; i < n; i++) {
            memset(vis, 0, sizeof(vis));
            dfs(i, i);
        }

        double ans = 0.0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                double ta = cities[i].p + cities[j].p;
                double tb = mstc - maxcost[i][j];
                ans = max(ans, ta / tb);
            }
        }
        printf("%.2lf\n", ans);
    }
}