#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
#define pb push_back
#define eb emplace_back
// 0-base
const LL INF = 1e18;
const int MAXN = 100 + 5;
struct Edge {
  int u, v;
  LL cost;
  LL cap;
  Edge(int _u, int _v, LL _c, LL _cap) : u(_u), v(_v), cost(_c), cap(_cap) {}
};
struct MCMF {     // inq times
  int n, pre[MAXN], cnt[MAXN];
  LL ans_flow, ans_cost, dis[MAXN];
  bool inq[MAXN];
  vector<int> G[MAXN];
  vector<Edge> edges;
  void init(int _n) {
    n = _n;
    edges.clear();
    for (int i = 0; i < n; i++) {
      G[i].clear();
    }
  }
  void add_edge(int u, int v, LL c, LL cap) {
    // directed
    G[u].pb(edges.size());
    edges.eb(u, v, c, cap);
    G[v].pb(edges.size());
    edges.eb(v, u, -c, 0);
  }
  bool SPFA(int st, int ed) {
    for (int i = 0; i < n; i++) {
      pre[i] = -1;
      dis[i] = INF;
      cnt[i] = 0;
      inq[i] = false;
    }
    queue<int> q;
    bool negcycle = false;

    dis[st] = 0;
    cnt[st] = 1;
    inq[st] = true;
    q.push(st);

    while (!q.empty() && !negcycle) {
      int u = q.front();
      q.pop();
      inq[u] = false;
      for (int i : G[u]) {
        int v = edges[i].v;
        LL cost = edges[i].cost;
        LL cap = edges[i].cap;

        if (dis[v] > dis[u] + cost && cap > 0) {
          dis[v] = dis[u] + cost;
          pre[v] = i;
          if (!inq[v]) {
            q.push(v);
            cnt[v]++;
            inq[v] = true;

            if (cnt[v] == n + 2) {
              negcycle = true;
              break;
            }
          }
        }
      }
    }

    return dis[ed] != INF;
  }
  LL sendFlow(int v, LL curFlow) {
    if (pre[v] == -1) {
      return curFlow;
    }
    int i = pre[v];
    int u = edges[i].u;
    LL cost = edges[i].cost;
  
    LL f = sendFlow(u, min(curFlow, edges[i].cap));

    ans_cost += f * cost;
    edges[i].cap -= f;
    edges[i ^ 1].cap += f;
    return f;
  }
  pair<LL, LL> run(int st, int ed) {
    ans_flow = ans_cost = 0;
    while (SPFA(st, ed)) {
      ans_flow += sendFlow(ed, INF);
    }
    return make_pair(ans_flow, ans_cost);
  }
};

MCMF mf;

int main() { IOS
   int n, m;
   while (cin >> n && n) {
       cin >> m;
       n += 2;
       mf.init(n);
       int u, v;
       LL cost;
       for (int i = 0; i < m; i++) {
           cin >> u >> v >> cost;
           mf.add_edge(u, v, cost, 1);
           mf.add_edge(v, u, cost, 1);
       }
       mf.add_edge(0, 1, 0, 2);
       mf.add_edge(n - 2, n - 1, 0, 2);
       auto ans = mf.run(0, n - 1);
       if (ans.first != 2) {
           cout << "Back to jail\n";
       } else {
           cout << ans.second << "\n";
       }
   }
}
