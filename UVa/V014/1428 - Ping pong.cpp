#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
#define lowbit(k) (k & -k)
const int MAXN = 2e4 + 5;
const int MAXA = 1e5;

int n, a[MAXN], lb[MAXN], rb[MAXN], tree[MAXA + 5];

void upd(int x) {
    for (; x <= MAXA; x += lowbit(x)) {
        ++tree[x];
    }
}

int qry(int x) {
    int sum = 0;
    for (; x > 0; x -= lowbit(x)) {
        sum += tree[x];
    }
    return sum;
}

int main() { IOS
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        memset(tree, 0, sizeof(tree));
        for (int i = 0; i < n; i++) {
            lb[i] = qry(a[i] - 1);
            upd(a[i]);
        }

        memset(tree, 0, sizeof(tree));
        for (int i = n - 1; i >= 0; i--) {
            rb[i] = qry(a[i] - 1);
            upd(a[i]);
        }

        LL ans = 0;
        for (int i = 0; i < n; i++) {
            LL larb = (i - lb[i]) * rb[i];
            LL lbra = lb[i] * (n - 1 - i - rb[i]);
            ans += larb + lbra;
        }
        cout << ans << '\n';
    }
}