#include <bits/stdc++.h>
using namespace std;

int K, M, N, x, y;
string ans;

void chkY() {
    if (y > N) {
        ans += 'N';
    } else {
        ans += 'S';
    }
}

void chkX() {
    if (x > M) {
        ans += 'E';
    } else {
        ans += 'O';
    }
}

int main() {
    while (cin >> K && K) {
        cin >> M >> N;

        for (int i = 0; i < K; i++) {
            cin >> x >> y;

            if (x == M || y == N) {
                cout << "divisa" << endl;
                continue;
            }

            ans.clear();
            chkY();
            chkX();
            cout << ans << endl;
        }
    }
}
