#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
#define pb push_back
const int MAXN = 500 + 5;

int dis(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

struct Taxi {
    int stTime, edTime;
    int fx, fy;
    int tx, ty;
    void read() {
        char c;
        int h, m;
        cin >> h >> c >> m >> fx >> fy >> tx >> ty;
        stTime = h * 60 + m;
        edTime = stTime + dis(fx, fy, tx, ty);
    }
};

int n, my[MAXN];
Taxi taxis[MAXN];
vector<int> G[MAXN];
bool vis[MAXN];

bool inTime(Taxi &a, Taxi &b) {
    return (a.edTime + dis(a.tx, a.ty, b.fx, b.fy)) < b.stTime;
}

bool match(int u) {
    for (int v : G[u]) {
        if (vis[v]) {
            continue;
        }
        vis[v] = 1;
        if (my[v] == -1 || match(my[v])) {
            my[v] = u;
            return true;
        }
    }
    return false;
}

int KM() {
    memset(my, -1, sizeof(my));
    int ans = 0;
    for (int i = 0; i < n; i++) {
        memset(vis, 0, sizeof(vis));
        if (match(i)) {
            ++ans;
        }
    }
    return ans;
}

int main() { IOS
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            taxis[i].read();
            G[i].clear();
        }

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (inTime(taxis[i], taxis[j])) {
                    G[i].pb(j);
                }
            }
        }

        cout << n - KM() << '\n';
    }
}