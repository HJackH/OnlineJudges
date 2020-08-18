#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);

const int MAXN = 16;

bitset<MAXN + 5> vis;
bitset<2 * MAXN + 5> notP;
vector<int> a(MAXN + 5);
vector<vector<int>> ans[MAXN + 5];

void sieve() {
    notP.reset();
    for (int i = 2; i <= MAXN * 2; i++) {
        if (!notP[i]) {
            for (int j = i * i; j <= MAXN * 2; j += i) {
                notP[j] = 1;
            }
        }
    }
}

void dfs(int len, int nowlen) {
    if (nowlen == len) {
        if (!notP[a[1] + a[len]]) {
            ans[len].emplace_back(a.begin() + 1, a.begin() + len + 1);
        }
        return;
    }

    for (int i = 2; i <= len; i++) {
        if (!vis[i] && !notP[i + a[nowlen]]) {
            a[nowlen + 1] = i;
            vis[i] = 1;
            dfs(len, nowlen + 1);
            vis[i] = 0;
        }
    }
}

int main() {
    IOS
    sieve();
    for (int i = 1; i <= MAXN; i++) {
        vis.reset();
        a[1] = 1;
        dfs(i, 1);
    }

    int n, kase = 0;
    while (cin >> n) {
        if (kase) {
            cout << '\n';
        }
        cout << "Case " << ++kase << ":\n";
        for (auto vs : ans[n]) {
            bool first = true;
            for (auto i : vs) {
                if (!first) {
                    cout << ' ';
                }
                first = false;
                cout << i;
            }
            cout << '\n';
        }
    }
}