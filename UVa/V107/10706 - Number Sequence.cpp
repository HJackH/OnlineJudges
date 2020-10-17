#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
const int MAXN = 50000;
const LL MAXI = (1LL << 31) - 1;

int x;  //array length
vector<LL> cnt(MAXN + 5), sum(MAXN + 5);

void run_table() {
    LL digit = 1, up = 10;
    for (x = 1; x <= MAXN && sum[x - 1] <= MAXI; x++) {
        if (x == up) {
            up *= 10LL;
            ++digit;
        }
        cnt[x] = cnt[x - 1] + digit;
        sum[x] = sum[x - 1] + cnt[x];
    }
}

int main() { IOS
    run_table();

    int T, i;
    cin >> T;
    while (T--) {
        cin >> i;
        int in = lower_bound(sum.begin() + 1, sum.begin() + x, i) - sum.begin();
        i -= sum[in - 1];
        int num = lower_bound(cnt.begin() + 1, cnt.begin() + x, i) - cnt.begin();
        i -= cnt[num - 1];
        cout << to_string(num)[i - 1] << '\n';
    }
}