#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e4 + 5;
const int INF = 1e9;

struct Edge {
    int from;
    int to;
    int bdw;
    int cost;
};

int n, m, budget;
int in[MAXN], pre[MAXN], id[MAXN], vis[MAXN]; 
Edge edges[MAXN], tedges[MAXN];

int CLE(int root, int tn, int lowb) {
    copy(begin(edges), begin(edges) + m, begin(tedges));

    int res = 0;
    while (true) {
        for (int i = 0; i < tn; i++) {
            in[i] = INF;
        }

        //find in edge
        for (int i = 0; i < m; i++) {
            Edge e = tedges[i];
            if (e.from != e.to && e.bdw >= lowb && e.cost < in[e.to]) {
                pre[e.to] = e.from;
                in[e.to] = e.cost;
            }
        }

        //check in edge
        for (int i = 0; i < tn; i++) {
            if (i == root) {
                continue;
            }
            if (in[i] == INF) {
                return -1;
            }
        }

        int nodenum = 0;
        memset(id, -1, sizeof(id));
        memset(vis, -1, sizeof(vis));
        in[root] = 0;

        //find cycles
        for (int i = 0; i < tn; i++) {
            res += in[i];
            int v = i;
            while (vis[v] != i && id[v] == -1 && v != root) {
                vis[v] = i;
                v = pre[v];
            }

            if (v != root && id[v] == -1) {
                for (int j = pre[v]; j != v; j = pre[j]) {
                    id[j] = nodenum;
                }
                id[v] = nodenum++;
            }
        }

        //no cycle
        if (nodenum == 0) {
            break;
        }

        for (int i = 0; i < tn; i++) {
            if (id[i] == -1) {
                id[i] = nodenum++;
            }
        }

        //grouping the vertices
        for (int i = 0; i < m; i++) {
            int from = tedges[i].from;
            int to = tedges[i].to;

            tedges[i].from = id[from];
            tedges[i].to = id[to];

            if (tedges[i].from != tedges[i].to) {
                tedges[i].cost -= in[to];
            }
        }

        tn = nodenum;
        root = id[root];
    }
    return res;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m >> budget;

        int L = INF, R = 0;
        for (int i = 0; i < m; i++) {
            cin >> edges[i].from >> edges[i].to >> edges[i].bdw >> edges[i].cost;
            L = min(L, edges[i].bdw);
            R = max(R, edges[i].bdw);
        }

        int mid, res = -1;
        while (L <= R) {
            mid = (L + R) / 2;
            int tmp = CLE(0, n, mid);
            if (tmp == -1 || tmp > budget) {
                R = mid - 1;
            } else {
                L = mid + 1;
                res = mid;
            }
        }

        if (res == -1) {
            cout << "streaming not possible.\n";
        } else {
            cout << res << " kbps\n";
        }
    }
}