#include <bits/stdc++.h>
using namespace std;

const int MAXN = 30 + 5;
const int way[6][3] = {{0, 1, 0}, {0, 0, 1}, {0, -1, 0}, {0, 0, -1}, {1, 0, 0}, {-1, 0, 0}};

struct Pos {
    int l;
    int r;
    int c;
    int cnt;
};

int L, R, C;
bool vis[MAXN][MAXN][MAXN];
string maze[MAXN][MAXN];    //level, row

int main() {
    while (cin >> L >> R >> C && L && R && C) {
        int stl, str, stc;
        bool flag = false;
        for (int tl = 0; tl < L; tl++) {
            for (int tr = 0; tr < R; tr++) {
                cin >> maze[tl][tr];
                if (!flag) {
                    for (int i = 0, sz = maze[tl][tr].length(); i < sz; i++) {
                        if (maze[tl][tr][i] == 'S') {
                            stl = tl;
                            str = tr;
                            stc = i;
                            flag = true;
                            break;
                        }
                    }
                }
            }
        }

        memset(vis, 0, sizeof(vis));
        flag = false;
        queue<Pos> q;
        q.push((Pos) {stl, str, stc, 0});
        while (!q.empty()) {
            auto now = q.front();
            q.pop();
            if (maze[now.l][now.r][now.c] == 'E') {
                cout << "Escaped in " << now.cnt << " minute(s).\n";
                flag = true;
                break;
            }

            for (int i = 0; i < 6; i++) {
                int tl = now.l + way[i][0];
                int tr = now.r + way[i][1];
                int tc = now.c + way[i][2];
                if (tl >= 0 && tl < L && tr >= 0 && tr < R && tc >= 0 && tc < C && 
                        maze[tl][tr][tc] != '#' && !vis[tl][tr][tc]) {
                    vis[tl][tr][tc] = true;
                    q.push((Pos) {tl, tr, tc, now.cnt + 1});
                }
            }
        }

        if (!flag) {
            cout << "Trapped!\n";
        }
    }
}