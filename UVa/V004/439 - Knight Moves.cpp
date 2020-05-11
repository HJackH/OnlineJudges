#include <bits/stdc++.h>
using namespace std;

const int way[8][2] = {{-1, 2}, {1, 2}, {2, 1}, {2, -1}, {-1, -2}, {1, -2}, {-2, -1}, {-2, 1}};

struct Pos{
    int x;
    int y;
    int cnt;
};

string from, to;
bool vis[10][10];

int main() {
    while (cin >> from >> to) {
        memset(vis, 0, sizeof(vis));
        int endx = to[0] - 'a', endy = to[1] - '1';
        queue<Pos> q;
        q.push((Pos) {from[0] - 'a', from[1] - '1', 0});
        while (!q.empty()) {
            auto now = q.front();
            q.pop();
            if (now.x == endx && now.y == endy) {
                cout << "To get from " << from << " to " << to << " takes " << now.cnt << " knight moves.\n";
                break;
            }

            vis[now.x][now.y] = true;
            for (int i = 0; i < 8; i++) {
                int k = now.x + way[i][0];
                int l = now.y + way[i][1];
                if (k >= 0 && k < 8 && l >= 0 && l < 8 && !vis[k][l]) {
                    q.push((Pos) {k, l, now.cnt + 1});
                }
            }
        }
    } 
}