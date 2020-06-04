#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000;
const int INF = 1e9;

struct Elephant{
    int w;
    int s;
    int id;
    bool operator < (const Elephant &other) const {
        return s > other.s;
    }
};

int n, pre[MAXN + 5], dp[MAXN + 5];
Elephant ele[MAXN + 5];

int main() {
    n = 0;
    while (cin >> ele[n].w >> ele[n].s) {
        ele[n].id = n + 1;
        n++;
    }
    sort(ele, ele + n);

    for (int i = 0; i <= n + 2; i++) {
        dp[i] = 1;
        pre[i] = -1;
    }

    int mxlen = 1, mxat = 0;
    for (int i = 1; i < n; i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (ele[j].w < ele[i].w && dp[j] + 1 > dp[i] && ele[j].s > ele[i].s) {
                pre[i] = j;
                dp[i] = dp[j] + 1;
            }
        }
        if (dp[i] > mxlen) {
            mxlen = dp[i];
            mxat = i;
        }
    }

    cout << mxlen << '\n';
    vector<int> ans;
    for (int i = mxat; i != -1; i = pre[i]) {
        ans.push_back(ele[i].id);
    }
    reverse(ans.begin(), ans.end());
    for (int i : ans) {
        cout << i << '\n';
    }
}