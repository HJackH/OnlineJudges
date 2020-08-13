#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);

const int MAXN = 1e6 + 5;

int n;
LL a[MAXN], b[MAXN];

int main() {
    IOS
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        LL sum = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i] >> b[i];
            sum += b[i];
        }  
        for (int i = 0; i < n; i++) {
            ans += min(a[i], sum - b[i]);
        }
        cout << min(ans, sum) << '\n';
    }
}