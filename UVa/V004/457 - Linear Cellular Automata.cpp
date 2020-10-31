#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
const int MAXN = 50 + 5;

int lb[15], board[MAXN][MAXN];
const string format = " .xW";

int main() { IOS
    for (int i = 1; i <= 40; i++) {
        board[1][i] = 0;
    }
    board[1][20] = 1;

    int T;
    cin >> T;
    while (T--) {
        for (int i = 0; i < 10; i++) {
            cin >> lb[i];
        }

        for (int i = 1; i <= 40; i++) {
            cout << format[board[1][i]];
        }
        cout << '\n';

        for (int i = 2; i <= 50; i++) {
            auto &pre = board[i - 1];
            for (int j = 1; j <= 40; j++) {
                board[i][j] = lb[pre[j - 1] + pre[j] + pre[j + 1]];
                cout << format[board[i][j]];
            }
            cout << '\n';
        }
        if (T) {
            cout << '\n';
        }
    }
}