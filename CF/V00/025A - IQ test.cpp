#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);

const int MAXN = 100 + 5;

int n, a[MAXN];

int main() {
    IOS

    cin >> n;
    int cnt[2] = {0}, at[2];
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] & 1) {
            ++cnt[1];
            at[1] = i;
        } else {
            ++cnt[0];
            at[0] = i;
        }
    }
    
    cout << (cnt[0] > cnt[1] ? at[1] : at[0]) << '\n';
}