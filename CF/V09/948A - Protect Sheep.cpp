#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
const int MAXN = 500 + 5;
const int way[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int R, C, chk;
string board[MAXN];

bool in(int x, int y) {
    return x >= 0 && x < R && y >= 0 && y < C;
}

void fill(int x, int y) {
    for (int i = 0; i < 4 && chk; i++) {
        int tx = x + way[i][0];
        int ty = y + way[i][1];
        if (in(tx, ty)) {
            if (board[tx][ty] == '.') {
                board[tx][ty] = 'D';
            } else if (board[tx][ty] == 'W') {
                chk = 0;
            }
        }
    }
}

int main() { IOS
    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        cin >> board[i];
    }

    chk = 1;
    for (int i = 0; i < R && chk; i++) {
        for (int j = 0; j < C && chk; j++) {
            if (board[i][j] == 'S') {
                fill(i, j);
            }
        }
    }

    if (chk) {
        cout << "YES\n";
        for (int i = 0; i < R; i++) {
            cout << board[i] << '\n';
        }
    } else {
        cout << "NO\n";
    }
}