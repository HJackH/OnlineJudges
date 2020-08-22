#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);

const int MAXN = 50 + 5;
const int way[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

struct Pos {
    int x;
    int y;
    int face;
    int time;
};

int n, m, board[MAXN][MAXN];
bool vis[MAXN][MAXN][4];
Pos st, ed;

bool in(int x, int y) {
    return 1 <= x && x <= n - 1 && 1 <= y && y <= m - 1;
}

bool chkO(int x, int y) {
    return !(board[x - 1][y - 1] || board[x - 1][y] || board[x][y - 1] || board[x][y]);
}

int bfs() {
    if (!chkO(st.x, st.y)) {
        return -1;
    }

    memset(vis, 0, sizeof(vis));
    vis[st.x][st.y][st.face] = true;
    queue<Pos> q;
    q.push({st.x, st.y, st.face, 0});

    while (!q.empty()) {
        auto now = q.front();
        q.pop();
        
        if (now.x == ed.x && now.y == ed.y) {
            return now.time;
        }

        //turn left
        if (!vis[now.x][now.y][(now.face + 3) % 4]) {
            vis[now.x][now.y][(now.face + 3) % 4] = true;
            q.push({now.x, now.y, (now.face + 3) % 4, now.time + 1});
        }

        //turn right
        if (!vis[now.x][now.y][(now.face + 1) % 4]) {
            vis[now.x][now.y][(now.face + 1) % 4] = true;
            q.push({now.x, now.y, (now.face + 1) % 4, now.time + 1});
        }

        //go
        int tx = now.x;
        int ty = now.y;
        for (int i = 1; i <= 3; i++) {
            tx += way[now.face][0];
            ty += way[now.face][1];
            if (in(tx, ty) && chkO(tx, ty)) {
                if (!vis[tx][ty][now.face]) {
                    vis[tx][ty][now.face] = true;
                    q.push({tx, ty, now.face, now.time + 1});
                }
            } else {
                break;
            }
        }
    }

    return -1;
}

int main() {
    IOS
    unordered_map<string, int> mp;
    mp["north"] = 0;
    mp["east"] = 1;
    mp["south"] = 2;
    mp["west"] = 3;
    
    while (cin >> n >> m && (n || m)) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> board[i][j];
            }
        }
        
        string oface;
        cin >> st.x >> st.y >> ed.x >> ed.y >> oface;
        st.face = mp[oface];
        cout << bfs() << '\n';
    }
}