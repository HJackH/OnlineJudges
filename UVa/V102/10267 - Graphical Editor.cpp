#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
const int MAXN = 250;
const int way[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int m = MAXN, n = MAXN;
char board[MAXN + 5][MAXN + 5];
bool vis[MAXN + 5][MAXN + 5];

// top-left to bottom-right
void setC(int x1, int y1, int x2, int y2, char clr) {
    for (int j = y1; j <= y2; j++) {
        for (int i = x1; i <= x2; i++) {
            board[i][j] = clr;
        }
    }
}

void print() {
    for (int j = 1; j <= n; j++) {
        for (int i = 1; i <= m; i++) {
            cout << board[i][j];
        }
        cout << '\n';
    }
}

bool in(int x, int y) {
    return x >= 1 && x <= m && y >= 1 && y <= n;
}

void dfs(int x, int y, char clr) {
    vis[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        int tx = x + way[i][0];
        int ty = y + way[i][1];
        if (in(tx, ty) && board[tx][ty] == board[x][y] && !vis[tx][ty]) {
            dfs(tx, ty, clr);
        }
    }
    board[x][y] = clr;
}

int main() { IOS
    char cmd, color;
    int x1, y1, x2, y2;
    string str;

    while (getline(cin, str)) {
        stringstream ss(str);

        ss >> cmd;
        switch (cmd)
        {
        case 'I':
            ss >> m >> n;
            setC(1, 1, m, n, 'O');
            break;

        case 'C':
            setC(1, 1, m, n, 'O');
            break;

        case 'L':
            ss >> x1 >> y1 >> color;
            board[x1][y1] = color;
            break;

        case 'V':
            ss >> x1 >> y1 >> y2 >> color;
            setC(x1, min(y1, y2), x1, max(y1, y2), color);
            break;

        case 'H':
            ss >> x1 >> x2 >> y1 >> color;
            setC(min(x1, x2), y1, max(x1, x2), y1, color);
            break;

        case 'K':
            ss >> x1 >> y1 >> x2 >> y2 >> color;
            setC(min(x1, x2), min(y1, y2), max(x1, x2), max(y1, y2), color);
            break;

        case 'F':
            ss >> x1 >> y1 >> color;
            memset(vis, 0, sizeof(vis));
            dfs(x1, y1, color);
            break;

        case 'S':
            ss >> str;
            cout << str << '\n';
            print();
            break;

        case 'X':
            return 0;
        default:
            break;
        }
    }
}