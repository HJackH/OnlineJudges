#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
const int MAXN = 200;

struct Edge {
    int to;
    int cost;

    Edge(int _to, int _cost) : to(_to), cost(_cost) {}
    bool operator < (Edge const &other) const {
        return cost < other.cost;
    }
};

int N, start, kase = 0;
vector<Edge> G[MAXN + 10];
vector<int> dis(MAXN + 10);

void init() {
    for (int i = 0; i <= N; i++) {
        G[i].clear();
        dis[i] = 0;
    }
}

void djk() {
    priority_queue<Edge, vector<Edge>> pq;
    pq.push(Edge(start, 0));
    dis[start] = 0;

    while (!pq.empty()) {
        Edge u = pq.top();
        pq.pop();

        if (u.cost != dis[u.to]) {
            continue;
        }

        for (Edge i : G[u.to]) {
            if (dis[i.to] < i.cost + u.cost) {
                dis[i.to] = i.cost + u.cost;
                pq.push(Edge(i.to, dis[i.to]));
            }
        }
    }
}
    
int main() { IOS
    while (cin >> N && N) {
        init();

        cin >> start;
        int p, q;
        while (cin >> p >> q && (p || q)) {
            G[p].push_back(Edge(q, 1));
        }

        djk();

        int anslen = 0, anspoint;
        for (int i = 1; i <= N; i++) {
            if (dis[i] > anslen) {
                anslen = dis[i];
                anspoint = i;
            }
        }

        cout << "Case " << ++kase << ": The longest path from " << start
            << " has length " << anslen << ", finishing at " << anspoint << "." << endl;
        cout << endl;
    }
}