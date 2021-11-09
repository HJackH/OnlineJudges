#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int MAXN = 1e4 + 5;

int n, m, tot;
vector<int> nums, lis(MAXN), cnt(MAXN), path(MAXN);

int main() {
    int kase = 0;
    while (cin >> n >> m && (n != -1 || m != -1)) {
        nums.clear();
        nums.pb(0);
        nums.pb((n + 1) * m);

        int x, y;
        while (cin >> x >> y && (x || y)) {
            int idx = (x - 1) * m + y;
            nums.pb(idx);
        }
        sort(nums.begin(), nums.end());

        tot = nums.size();
        for (int i = 0; i < tot; i++) {
            lis[i] = path[i] = 0;
            cnt[i] = 1;
        }
        
        for (int i = 0; i < tot; i++) {
            int iy = (nums[i] - 1) % m;
            for (int j = i + 1; j < tot; j++) {
                int jy = (nums[j] - 1) % m;
                if (jy < iy) {
                    continue;
                }
                if (lis[i] + 1 > lis[j]) {
                    lis[j] = lis[i] + 1;
                    cnt[j] = cnt[i];
                    path[j] = i;
                } else if (lis[i] + 1 == lis[j]) {
                    cnt[j] += cnt[i];
                }
            }
        }

        //                                  ignore last number (n + 1) * m
        cout << "CASE#" << ++kase << ": " << lis[tot - 1] - 1 << " " << cnt[tot - 1];

        vector<int> ans;
        for (int k = path[tot - 1]; k != 0; k = path[k]) {
            ans.pb(nums[k]);
        }
        reverse(ans.begin(), ans.end());
        for (int i : ans) {
            cout << " " << i;
        }
        cout << "\n";
    }
}