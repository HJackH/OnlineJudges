#include <bits/stdc++.h>
using namespace std;

#define lowbit(k) k & -k
const int MAXN = 200010;

int n, a[MAXN], tree[MAXN], kase = 0, tmp;

void setAt(int index, int data) {
    int diff = data - a[index];
    a[index] = data;
    for (int i = index; i <= n; i += lowbit(i)) {
        tree[i] += diff;
    }
}

int query(int index) {
    int res = 0;
    for (int i = index; i >= 1; i -= lowbit(i)) {
        res += tree[i];
    }
    return res;
}

int main() {
    cin >> n;
    while (n) {
        memset(a, 0, sizeof(a));
        memset(tree, 0, sizeof(tree));

        for (int i = 1; i <= n; i++) {
            cin >> tmp;
            setAt(i, tmp);
        }

        string mode;
        int x, y;

        cout << "Case " << ++kase << ":" << endl;
        while (cin >> mode && mode != "END") {
            cin >> x >> y;
            if (mode == "S") {
                setAt(x, y);
            } else {
                cout << query(y) - query(x - 1) << endl;
            }
        }

        cin >> n;
        if (n) {
            cout << endl;
        }
    }
}
