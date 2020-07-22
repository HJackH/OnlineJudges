#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100 + 5;
const int way[8][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};

int n, m;
string board[MAXN];

bool chk(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m && board[x][y] == '*';
}

int main() {
    int kase = 0;
    cin >> n >> m;
    while (n || m) {
        for (int i = 0; i < n; i++) {
            cin >> board[i];
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == '.') {
                    board[i][j] = '0';
                    //8 directions
                    for (int k = 0; k < 8; k++) {
                        int ti = i + way[k][0];
                        int tj = j + way[k][1];
                        if (chk(ti, tj)) {
                            board[i][j]++;
                        }
                    }
                }
            }
        }

        cout << "Field #" << ++kase << ":\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << board[i][j];
            }
            cout << '\n';
        }

        cin >> n >> m;
        if (n || m) {
            cout << '\n';
        }
    }
}