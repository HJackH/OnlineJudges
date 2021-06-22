#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
#define pb push_back
#define sz(x) int((x).size())
const int MAXL = 100 + 5;

struct Agt {
    string name;
    int a;
    int b;
    int cost;
    bool operator < (const Agt &other) const {
        if (cost == other.cost) {
            return name < other.name;
        }
        return cost < other.cost;
    }
};

int n, m, l;
Agt agts[MAXL];

void cal(Agt &t) {
    t.cost = 0;
    int now = n;
    while (now != m) {
        if ((now >> 1) < m) {
            t.cost += (now - m) * t.a;
            now = m;
        } else {
            t.cost += min(t.b, ((now + 1) >> 1) * t.a);
            now >>= 1;
        }
    }
}

int main() {
    int T;
    cin >> T;
    for (int kase = 1; kase <= T; kase++) {
        cin >> n >> m >> l;
        char buf[20];
        for (int i = 0; i < l; i++) {
            scanf(" %[^:]:%d,%d", buf, &agts[i].a, &agts[i].b);
            agts[i].name = string(buf);
            cal(agts[i]);
        }

        sort(agts, agts + l);

        cout << "Case " << kase << "\n";
        for (int i = 0; i < l; i++) {
            cout << agts[i].name << " " << agts[i].cost << "\n";
        }
    }
}