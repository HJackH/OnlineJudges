#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5000 + 50;

int c, r, n, parent[MAXN];
map<string, int> M;

void init(string s) {
    parent[n] = -1;
    M[s] = n++;
}

int find(int x) {
    if (parent[x] < 0) {
        return x;
    }
    return parent[x] = find(parent[x]);
}

void unionSet(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) {
        if (parent[a] > parent[b]) {
            swap(a, b);
        }
        parent[a] += parent[b];
        parent[b] = a;
    }
}

int main() {
    while (cin >> c >> r && (c || r)) {
        n = 0;
        M.clear();
        string tmp[2];
        for (int i = 0; i < c; i++) {
            cin >> tmp[0];
            init(tmp[0]);
        }

        for (int i = 0; i < r; i++) {
            cin >> tmp[0] >> tmp[1];
            unionSet(M[tmp[0]], M[tmp[1]]);
        }

        int ans = 1;
        for (int i = 0; i < c; i++) {
            ans = min(ans, parent[i]);
        }
        cout << abs(ans) << '\n';
    }
}