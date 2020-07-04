#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000 + 5;
const int INF = 1e9;
const int way[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

struct Node {
    int x;
    int y;
    int cost;
    bool operator < (const Node &other) const {
        return cost > other.cost;
    }
};

int n, m;
int maze[MAXN][MAXN], d[MAXN][MAXN];

bool in(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

void dijk() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            d[i][j] = INF;
        }
    }

    d[0][0] = maze[0][0];
    priority_queue<Node> pq;
    pq.push({0, 0, d[0][0]});
    while (!pq.empty()) {
        auto now = pq.top();
        pq.pop();
        if (now.x == n - 1 && now.y == m - 1) {
            return;
        }
        if (d[now.x][now.y] < now.cost) {
            continue;
        }

        for (int i = 0; i < 4; i++) {
            int tx = now.x + way[i][0];
            int ty = now.y + way[i][1];
            if (in(tx, ty) && d[tx][ty] > d[now.x][now.y] + maze[tx][ty]) {
                d[tx][ty] = d[now.x][now.y] + maze[tx][ty];
                pq.push({tx, ty, d[tx][ty]});
            }
        }
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> maze[i][j];
            }
        }

        dijk();

        cout << d[n - 1][m - 1] << '\n';
    }
}