#include <bits/stdc++.h>
using namespace std;

const int MAXN = 500 + 5;

struct Point {
    double x;
    double y;
};

struct Edge {
    int u;
    int v;
    double cost;
    Edge(int _u, int _v, double _cost) : u(_u), v(_v), cost(_cost) {}
    bool operator < (const Edge &other) const {
        return cost < other.cost;
    }
};

int s, n, boss[MAXN];
Point points[MAXN];
vector<Edge> edges;
vector<double> mst;

void init() {
    edges.clear();
    mst.clear();
    for (int i = 0; i < n; i++) {
        boss[i] = -1;
    }
}

int find(int x) {
    if (boss[x] < 0) {
        return x;
    }
    return boss[x] = find(boss[x]);
}

bool merge(int a, int b) {
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

double dis(int a, int b) {
    double dx = points[a].x - points[b].x;
    double dy = points[a].y - points[b].y;
    return sqrt(dx * dx + dy * dy);
}

void kruskal() {
    sort(edges.begin(), edges.end());
    for (auto &e : edges) {
        if (merge(e.u, e.v)) {
            mst.push_back(e.cost);
        }
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> s >> n;
        for (int i = 0; i < n; i++) {
            cin >> points[i].x >> points[i].y;
        }
        init();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                edges.emplace_back(i, j, dis(i, j));
            }
        }
        kruskal();
        printf("%.2lf\n", mst[n - 1 - s]);
    }
}