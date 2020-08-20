#include <iostream>
#include <bitset>
#include <queue>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);

const int MAXN = 1e5;

struct Pos {
    int at;
    int time;
};

int n, k;
bitset<MAXN + 5> vis;

bool chk(int at) {
    return 0 <= at && at <= MAXN && !vis[at];
}

int bfs() {
    queue<Pos> q;
    vis[n] = 1;
    q.push({n, 0});
    while (!q.empty()) {
        Pos now = q.front();
        q.pop();
        if (now.at == k) {
            return now.time;
        }
        if (now.at > k) {
            if (chk(now.at - 1)) {
                vis[now.at - 1] = 1;
                q.push({now.at - 1, now.time + 1});
            }
        } else {
            if (chk(now.at - 1)) {
                vis[now.at - 1] = 1;
                q.push({now.at - 1, now.time + 1});
            }
            if (chk(now.at + 1)) {
                vis[now.at + 1] = 1;
                q.push({now.at + 1, now.time + 1});
            }
            if (chk(now.at * 2)) {
                vis[now.at * 2] = 1;
                q.push({now.at * 2, now.time + 1});
            }
        }
    }
    return -1;
}

int main() {
    IOS
    while (cin >> n >> k) {
        vis.reset();
        cout << bfs() << '\n';
    }
}