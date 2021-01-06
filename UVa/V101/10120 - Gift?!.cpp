#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
const int MAXN = 1e6 + 5;

LL n, m;
bool vis[MAXN];

bool in(LL x) {
    return x > 0 && x <= n;
}

bool dfs(LL at, LL l) {
    LL to = 2 * l - 1;
    if (!in(at)) {
        return false;
    }
    if (at == m) {
        return true;
    }
    return dfs(at + to, l + 1) || dfs(at - to, l + 1);
}

int main() { IOS
    while (cin >> n >> m && (n || m)) {
        memset(vis, 0, sizeof(vis));
        if (n >= 49 || dfs(1, 2)) {
            cout << "Let me try!\n";
        } else {
            cout << "Don't make fun of me!\n";
        }
    }
}