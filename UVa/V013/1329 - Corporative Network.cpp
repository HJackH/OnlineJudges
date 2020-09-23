#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
#define mp make_pair
#define F first
#define S second

const int MAXN = 2e4 + 5;

int n, boss[MAXN], len[MAXN];

pair<int, int> fi(int x) {  //<at, len>
    if (boss[x] < 0) {
        return mp(x, 0);
    }
    auto tmp = fi(boss[x]);
    return mp(boss[x] = tmp.F, len[x] += tmp.S);
}

void con(int x, int y) {
    boss[x] = y;
    len[x] = abs(x - y) % 1000;
}

int main() {
    IOS
    
    int T;
    cin >> T;
    while (T--) {
        cin >> n;

        for (int i = 1; i <= n; i++) {
            boss[i] = -1;
            len[i] = 0;
        }

        char mode;
        int ii, jj;
        while (cin >> mode && mode != 'O') {
            if (mode == 'E') {
                cin >> ii;
                cout << fi(ii).S << '\n';
            } else {
                cin >> ii >> jj;
                con(ii, jj);
            }
        }
    }
}