#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2500 + 5;

struct Node {
    int at;
    int day;
};

int e, n, ansM, ansD, cnt[MAXN];
vector<int> G[MAXN];
bitset<MAXN> vis;

void bfs(int st) {
    for (int i = 0; i < e; i++) {
        vis[i] = 0;
        cnt[i] = 0;
    }
    queue<Node> q;
    q.push({st, 0});
    vis[st] = 1;
    while (!q.empty()) {
        auto now = q.front();
        q.pop();
        for (int to : G[now.at]) {
            if (!vis[to]) {
                q.push({to, now.day + 1});
                vis[to] = 1;
                cnt[now.day + 1]++;
            }
        }
    }
}

int main() {
    int tmp;
    cin >> e;
    for (int i = 0; i < e; i++) {
        cin >> n;
        for (int j = 0; j < n; j++) {
            cin >> tmp;
            G[i].push_back(tmp);
        }
    }

    int T;
    cin >> T;
    while (T--) {
        cin >> tmp;
        bfs(tmp);

        ansM = ansD = 0;
        for (int i = 0; i < e + 2; i++) {
            if (ansM < cnt[i]) {
                ansM = cnt[i];
                ansD = i;
            }
        }
        if (ansM == 0) {
            cout << "0\n";
        } else {
            cout << ansM << ' ' << ansD << '\n';
        }
    }
}