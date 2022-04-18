#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e3 + 5;

int n, m;
int board[MAXN][MAXN];

int main() {
    board[0][1] = 1;
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                board[i][j] = 0;
            }
        }
        
        string s;
        getline(cin, s);
        for (int i = 1; i <= n; i++) {
            getline(cin, s);
            stringstream ss(s);
            int row, col;
            ss >> row;
            while (ss >> col) {
                board[row][col] = -1;
            }
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (board[i][j] == -1) {
                    continue;
                }
                if (board[i - 1][j] != -1) {
                    board[i][j] += board[i - 1][j];
                }
                if (board[i][j - 1] != -1) {
                    board[i][j] += board[i][j - 1];
                }
            }
        }

        cout << board[n][m] << "\n";
        if (T) {
            cout << "\n";
        }
    }
}