#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100000 + 5;

int T, F, parent[MAXN], k;
map<string, int> M;

int find(int x) {
    if (parent[x] < 0) {
        return x;
    }
    return parent[x] = find(parent[x]);
}

void uni(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) {
        if (parent[a] > parent[b]) {
            swap(a, b);
        }
        parent[a] += parent[b];
        parent[b] = a;
    }
    cout << -parent[a] << '\n';
}

int ID(string str) {
    if (!M.count(str)) {
        M[str] = k++;
    }
    return M[str];
}

int main() {
    cin >> T;
    while (T--) {
        k = 0;
        M.clear();
        for (int i = 0; i < MAXN; i++) {
            parent[i] = -1;
        }

        cin >> F;

        string a, b;
        for (int i = 0; i < F; i++) {
            cin >> a >> b;
            uni(ID(a), ID(b));
        }
    }
}