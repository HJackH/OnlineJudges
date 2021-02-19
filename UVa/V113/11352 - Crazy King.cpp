#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
#define pb push_back
const int MAXN = 100 + 5;
const int way[8][2] = {
    { -2, -1 },
    { -2, 1 },
    { -1, 2 },
    { 1, 2 },
    { 2, -1 },
    { 2, 1 },
    { -1, -2 },
    { 1, -2 }
};
const int way_king[8][2] = {
    { -1, -1 },
    { -1, 0 },
    { -1, 1 },
    { 0, -1 },
    { 0, 1 },
    { 1, -1 },
    { 1, 0 },
    { 1, 1 }
};

struct Pos {
    int x;
    int y;
    int cnt;
};

int n, m;
string board[MAXN];
bool vis[MAXN][MAXN];

bool in(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

int bfs(Pos st, Pos ed) {
    deque<Pos> dq;
    dq.pb(st);
    vis[st.x][st.y] = 1;
    vis[ed.x][ed.y] = 0;
    while (!dq.empty()) {
        auto now = dq.front();
        dq.pop_front();
        if (now.x == ed.x && now.y == ed.y) {
            return now.cnt;
        }
        for (int i = 0; i < 8; i++) {
            int tx = now.x + way_king[i][0];
            int ty = now.y + way_king[i][1];
            if (in(tx, ty) && !vis[tx][ty]) {
                vis[tx][ty] = 1;
                dq.pb({ tx, ty, now.cnt + 1 });
            }
        }
    }
    return -1;
}

int main() { IOS
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            cin >> board[i];
            for (int j = 0; j < m; j++) {
                vis[i][j] = 0;
            }
        }

        Pos st, ed;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'Z') {
                    vis[i][j] = 1;
                    for (int k = 0; k < 8; k++) {
                        int tx = i + way[k][0];
                        int ty = j + way[k][1];
                        if (in(tx, ty)) {
                            vis[tx][ty] = 1;
                        }
                    }
                } else if (board[i][j] == 'A') {
                    st = { i, j, 0 };
                } else if (board[i][j] == 'B') {
                    ed = { i, j, 0 };
                }
            }
        }

        int res = bfs(st, ed);
        if (res == -1) {
            cout << "King Peter, you can't go now!\n";
        } else {
            cout << "Minimal possible length of a trip is " << res << '\n';
        }
    }
}