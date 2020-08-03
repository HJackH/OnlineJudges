#include <cstdio>
#include <vector>
using namespace std;
#define lowbit(k) (k & -k)

const int MAXN = 1e5 + 5;

struct Node {
    int val;
    int in;
    int out;
};

int n, m, ttime, tree[MAXN];
Node nodes[MAXN];
vector< vector<int> > G(MAXN);

void update(int x) {
    int delta;
    if (nodes[x].val == 1) {
        nodes[x].val = 0;
        delta = -1;
    } else {
        nodes[x].val = 1;
        delta = 1;
    }
    for (; x <= n; x += lowbit(x)) {
        tree[x] += delta;
    }
}

int query(int x) {
    int ans = 0;
    for (; x > 0; x -= lowbit(x)) {
        ans += tree[x];
    }
    return ans;
}

void dfs(int x) {
    nodes[x].in = ++ttime;
    for (int i = 0; i < G[x].size(); i++) {
        int v = G[x][i];
        if (!nodes[v].in) {
            dfs(v);
        }
    }
    nodes[x].out = ttime;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        update(i);
    }
    int u, v;
    for (int i = 1; i <= n - 1; i++) {
        scanf("%d %d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    ttime = 0;
    dfs(1);
    
    scanf("%d", &m);
    char mode;
    while (m--) {
        scanf(" %c %d", &mode, &v);
        if (mode == 'C') {
            update(nodes[v].in);
        } else {
            printf("%d\n", query(nodes[v].out) - query(nodes[v].in - 1));
        }
    }
}