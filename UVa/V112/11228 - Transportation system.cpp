#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e4 + 5;

struct Point {
    double x;
    double y;
};

struct Edge {
    int from;
    int to;
    double cost;
    Edge(int _from, int _to, double _cost) : from(_from), to(_to), cost(_cost) {}
    bool operator < (const Edge &other) const {
        return cost < other.cost;
    }
};

int n, boss[MAXN], states;
double r, road, rail;
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

void kruskal() {
    for (int i = 0; i < n; i++) {
        boss[i] = -1;
    }
    sort(edges.begin(), edges.end());

    int cnt = 0;
    for (auto e : edges) {
        if (uni(e.from, e.to)) {
            if (e.cost < r) {
                road += e.cost;
            } else {
                rail += e.cost;
                states++;
            }
            if (++cnt == n - 1) {
                return;
            }
        }
    }
}

int main() {
    int T;
    cin >> T;
    for (int kase = 1; kase <= T; kase++) {
        cin >> n >> r;
        for (int i = 0; i < n; i++) {
            cin >> points[i].x >> points[i].y;
        }
        
        edges.clear();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                edges.emplace_back(i, j, dis(i, j));
            }
        }

        states = 1;
        road = rail = 0.0;
        kruskal();
        cout << "Case #" << kase << ": " << states << ' ' << round(road) << ' ' << round(rail) << '\n';
    }
}