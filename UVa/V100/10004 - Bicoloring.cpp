#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);

const int MAXN = 200 + 5;

int n, l, color[MAXN];
vector<int> G[MAXN];

bool solve(int at, int draw) {
    for (auto v : G[at]) {
        if (color[v] == -1) {
            color[v] = draw ^ 1;
            if (!solve(v, draw ^ 1)) {
                return false;
            }
        } else if (color[v] == draw) {
            return false;
        }
    }
    return true;
}

int main() {
    IOS
    while (cin >> n && n) {
        cin >> l;
        for (int i = 0; i < n; i++) {
            G[i].clear();
            color[i] = -1;
        }
        int u, v;
        for (int i = 0; i < l; i++) {
            cin >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
        }

        color[0] = 0;
        if (solve(0, 0)) {
            cout << "BICOLORABLE.\n";
        } else {
            cout << "NOT BICOLORABLE.\n";
        }
    }   
}