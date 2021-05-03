#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
#define pb push_back
#define eb emplace_back
const int INF = 1e9;
const int MAXN = 100 + 5;

struct Ball {
    int x;
    int y;
    int z;
    int r;
};

struct Edge {
    int to;
    double cost;
    Edge(int t, double c) : to(t), cost(c) {}
    bool operator < (const Edge &other) const {
        return cost > other.cost;
    }
};

int n;
Ball balls[MAXN];
vector<Edge> G[MAXN];

double dijk(int st, int ed) {
    priority_queue<Edge> pq;
    vector<double> d(n, INF);
    pq.emplace(st, 0);
    d[st] = 0;
    while (!pq.empty()) {
        auto now = pq.top();
        pq.pop();
        if (now.to == ed) {
            return now.cost;
        }
        for (auto e : G[now.to]) {
            if (d[e.to] > now.cost + e.cost) {
                d[e.to] = now.cost + e.cost;
                pq.emplace(e.to, d[e.to]);
            }
        }
    }
    return -1;
}

int main() { IOS
    int kase = 0;
    while (cin >> n && n != -1) {
        n += 2;
        for (int i = 2; i < n; i++) {
            auto &t = balls[i];
            cin >> t.x >> t.y >> t.z >> t.r;
        }

        for (int i = 0; i < 2; i++) {
            auto &t = balls[i];
            cin >> t.x >> t.y >> t.z;
            t.r = 0;
        }

        for (int i = 0; i < n; i++) {
            G[i].clear();
        }
        
        for (int i = 0; i < n; i++) {
            auto &t1 = balls[i];
            for (int j = i + 1; j < n; j++) {
                auto &t2 = balls[j];
                double dx = t1.x - t2.x;
                double dy = t1.y - t2.y;
                double dz = t1.z - t2.z;
                double len = max(0.0, sqrt(dx * dx + dy * dy + dz * dz) - t1.r - t2.r);
                G[i].eb(j, len);
                G[j].eb(i, len);
            }
        }

        cout << "Cheese " << ++kase << ": Travel time = " << (int)round(dijk(0, 1) * 10.0) << " sec\n"; 
    }
}