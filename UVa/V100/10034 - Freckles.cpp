#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100 + 5;

struct Point {
    double x;
    double y;
};

struct Edge {
    int u;
    int v;
    double w;
    Edge(int tu, int tv, double tw) : u(tu), v(tv), w(tw) {}
    bool operator < (const Edge &other) const {
        return w < other.w;
    }
};

int n, boss[MAXN];
Point points[MAXN];
vector<Edge> edges;

double dis(int a, int b) {
    double dx = points[a].x - points[b].x;
    double dy = points[a].y - points[b].y;
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
    sort(edges.begin(), edges.end());
    for (int i = 0; i < n; i++) {
        boss[i] = -1;
    }
    double res = 0.0;
    for (auto e : edges) {
        if (uni(e.u, e.v)) {
            res += e.w;
        }
    }
    return res;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> points[i].x >> points[i].y;
        }
        edges.clear();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                edges.emplace_back(i, j, dis(i, j));
            }
        }
        printf("%.2lf\n", kruskal());
        if (T) {
            cout << '\n';
        }
    }
}