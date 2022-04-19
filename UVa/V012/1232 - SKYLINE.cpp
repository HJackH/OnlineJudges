#include <bits/stdc++.h>
using namespace std;
#define lc(x) (x << 1)
#define rc(x) (x << 1 | 1)
const int MAXN = 1e5 + 5;

struct Node {
    int mx;
    int tag;
    Node() {
        init();
    }
    void init() {
        mx = tag = 0;
    }
};

int n;
Node nodes[MAXN << 2];

void init() {
    for (int i = 0, ed = (MAXN << 2); i < ed; i++) {
        nodes[i].init();
    }
}

void pull(int now) {
    nodes[now].mx = max(nodes[lc(now)].mx, nodes[rc(now)].mx);
}

void push(int now) {
    nodes[lc(now)].tag = max(nodes[lc(now)].tag, nodes[now].tag);
    nodes[rc(now)].tag = max(nodes[rc(now)].tag, nodes[now].tag);
}

int qry(int now, int L, int R, int ql, int qr, int h) {
    if (R < ql || qr < L) {
        return 0;
    }
    if (nodes[now].tag > h) {
        return 0;
    }
    if (ql <= L && R <= qr) {
        if (nodes[now].mx <= h) {
            nodes[now].mx = h;
            nodes[now].tag = h;
            return R - L + 1;
        }
    }
    
    int M = (L + R) / 2;
    push(now);
    int ret = qry(lc(now), L, M, ql, qr, h) + qry(rc(now), M + 1, R, ql, qr, h);
    pull(now);
    return ret;
}

int main() {
    int T, l, r, h;
    cin >> T;
    while (T--) {
        init();
        cin >> n;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            cin >> l >> r >> h;
            ans += qry(1, 1, MAXN - 1, l, r - 1, h);
        }
        cout << ans << "\n";
    }
}