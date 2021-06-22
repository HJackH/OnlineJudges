#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
#define pb push_back
#define sz(x) int((x).size())
const int MAXN = 20 + 5;

int sg[MAXN], n, m, plk[MAXN];

void build() {
    int mex[MAXN];
    sg[0] = 0;
    for (int i = 1; i < MAXN; i++) {
        memset(mex, 0, sizeof(mex));
        for (int j = 0; j < i; j++) {
            mex[sg[j] ^ sg[i - j - 1]] = 1;
            if (i - j - 2 >= 0) {
                mex[sg[j] ^ sg[i - j - 2]] = 1;
            }
        }
        int g = 0;
        for (; mex[g]; g++);
        sg[i] = g;
    }
}

int main() { IOS
    build();
    int T;
    cin >> T;
    for (int kase = 1; kase <= T; kase++) {
        cin >> n >> m;
        memset(plk, 0, sizeof(plk));
        int last;
        for (int i = 0, x; i < m; i++) {
            cin >> x;
            last = --x;
            plk[last] = 1;
        }

        vector<int> nim;
        for (int i = 0, tmp = 0, pos; i < n; i++) {
            pos = (last + i) % n;
            if (plk[pos] == 0) {
                tmp++;
            }
            if (plk[pos] || i == n - 1) {
                if (tmp) {
                    nim.pb(tmp);
                }
                tmp = 0;
            }
        }

        int ans = 0;
        for (int i : nim) {
            ans ^= sg[i];
        }
        cout << "Case " << kase << ": " << (ans ? "yes" : "no") << "\n";
    }
}