#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000 + 5;
const int INF = 1e9;
const int way[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

struct Node{
    int x;
    int y;
    int depth;
};

int r, c, fireOn[MAXN + 5][MAXN + 5], vis[MAXN + 5][MAXN + 5];
string lines[MAXN + 5];


void bfsOnFire(Node st) {
    queue<Node> q;
    q.push(st);
    fireOn[st.x][st.y] = -1;
    while (!q.empty()) {
        auto now = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int tx = now.x + way[i][0];
            int ty = now.y + way[i][1];
            if (tx >= 0 && tx < r && ty >= 0 && ty < c 
                    && lines[tx][ty] != '#' && fireOn[tx][ty] > (now.depth + 1)) {
                fireOn[tx][ty] = now.depth + 1;
                q.push({tx, ty, now.depth + 1});
            }
        }
    }
}

void bfsOnJoe(Node st) {
    memset(vis, 0, sizeof(vis));

    queue<Node> q;
    q.push(st);
    vis[st.x][st.y] = true;
    while (!q.empty()) {
        auto now = q.front();
        q.pop();
        if ((now.x == 0 || now.x == r - 1) || (now.y == 0 || now.y == c - 1)) {
            cout << now.depth + 1 << '\n';
            return;
        }

        for (int i = 0; i < 4; i++) {
            int tx = now.x + way[i][0];
            int ty = now.y + way[i][1];
            if (tx >= 0 && tx < r && ty >= 0 && ty < c
                    && lines[tx][ty] != '#' && fireOn[tx][ty] > (now.depth + 1) && !vis[tx][ty]) {
                vis[tx][ty] = true;
                q.push({tx, ty, now.depth + 1});
            }
        }
    }
    cout << "IMPOSSIBLE\n";
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> r >> c;

        Node joe;
        vector<Node> fires;
        bool findj = false, findf = false;
        for (int i = 0; i < r; i++) {
            cin >> lines[i];
            for (int j = 0, ed = lines[i].length(); j < ed; j++) {
                if (!findj && lines[i][j] == 'J') {
                    findj = true;
                    joe = {i, j, 0};
                } 
                if (lines[i][j] == 'F') {
                    findf = true;
                    fires.push_back({i, j, 0});
                }
            }
        }

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                fireOn[i][j] = INF;
            }
        }

        if (findf) {
            for (auto fire : fires) {
                bfsOnFire(fire);
            }
        }
        bfsOnJoe(joe);
    }
}