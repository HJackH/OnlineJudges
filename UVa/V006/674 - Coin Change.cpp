#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
#define pb push_back
const int MAXN = 7489;
const int coins[] = {1, 5, 10, 25, 50};

int n, ans[MAXN + 100];

int main() { IOS
    ans[0] = 1;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j <= MAXN; j++) {
            ans[j + coins[i]] += ans[j];
        }
    }

    while (cin >> n) {
        cout << ans[n] << '\n';
    }
}