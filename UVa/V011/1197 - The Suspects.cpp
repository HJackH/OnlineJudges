#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
#define pb push_back
const int MAXN = 30000 + 5;

int n, m;
int boss[MAXN];

int find(int x) {
    if (boss[x] < 0) {
        return x;
    }
    return boss[x] = find(boss[x]);
}

void uni(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) {
        return;
    }
    if (boss[a] > boss[b]) {
        swap(a, b);
    }
    boss[a] += boss[b];
    boss[b] = a;
}

int main() { IOS
    while (cin >> n >> m && (n || m)) {
        for (int i = 0; i < n; i++) {
            boss[i] = -1;
        }
        
        for (int i = 0, k; i < m; i++) {
            cin >> k;
            for (int j = 0, mem = -1, num; j < k; j++) {
                cin >> num;
                if (~mem) {
                    uni(mem, num);
                }
                mem = num;
            }
        }

        cout << -boss[find(0)] << '\n';
    }
}