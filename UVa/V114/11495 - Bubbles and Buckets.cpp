#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
#define pb push_back
#define lowbit(k) (k & -k)
const int MAXN = 1e5;

int n, a[MAXN + 5], tree[MAXN + 5];

void upd(int x) {
    for (; x <= MAXN; x += lowbit(x)) {
        tree[x]++;
    }
}

int qry(int x) {
    int sum = 0;
    for (; x >= 1; x -= lowbit(x)) {
        sum += tree[x];
    }
    return sum;
}

int main() { IOS
    while (cin >> n && n) {
        memset(tree, 0, sizeof(tree));
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += i - qry(a[i] - 1);
            upd(a[i]);
        }
        if (ans & 1) {
            cout << "Marcelo\n";
        } else {
            cout << "Carlos\n";
        }
    }
}