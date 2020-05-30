#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10000;

struct Prod{
    int value;
    int dead;
    bool operator < (const Prod &other) const {
        if (value == other.value) {
            return dead > other.dead; 
        }
        return value > other.value;
    }
};

int n;
bool vis[MAXN + 5];
Prod prods[MAXN + 5];

int main() {
    while (cin >> n) {
        for (int i = 0; i < n; i++) {
            cin >> prods[i].value >> prods[i].dead;
        }
        sort(prods, prods + n);

        memset(vis, 0, sizeof(vis));
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = prods[i].dead, flag = 0; j >= 1 && !flag; j--) {
                if (!vis[j]) {
                    vis[j] = true;
                    ans += prods[i].value;
                    flag = 1;
                }
            }
        }

        cout << ans << endl;
    }
}