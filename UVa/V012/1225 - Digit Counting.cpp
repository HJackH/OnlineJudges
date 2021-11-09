#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e4 + 5;

int cnt[MAXN][10];

void build() {
    for (int i = 1; i < MAXN; i++) {
        string s = to_string(i);
        for (char c : s) {
            cnt[i][c - '0']++;
        }
        for (int j = 0; j < 10; j++) {
            cnt[i][j] += cnt[i - 1][j];
        }
    }
}

int main() {
    build();

    int T, n;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 0; i < 10; i++) {
            cout << cnt[n][i] << " \n"[i + 1 == 10];
        }
    }
}