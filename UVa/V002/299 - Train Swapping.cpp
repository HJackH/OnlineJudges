#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
#define lowbit(k) (k & -k)
const int MAXN = 50;

int n, a[MAXN + 5], tree[MAXN + 5];

void update(int x, int val) {
    for (; x <= MAXN; x += lowbit(x)) {
        tree[x] += val;
    }
}

int query(int x) {
    int ans = 0;
    for (; x >= 1; x -= lowbit(x)) {
        ans += tree[x];
    }
    return ans;
}

int main() {
    IOS
    int T;
    cin >> T;
    while (T--) {
        memset(tree, 0, sizeof(tree));
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int ans = 0;
        for (int i = n - 1; i >= 0; i--) {
            ans += query(a[i]);
            update(a[i], 1);
        }
        cout << "Optimal train swapping takes " << ans << " swaps.\n";
    }
}