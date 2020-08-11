#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);

int n;
vector<int> a, pos;

int LIS(vector<int> &arr) {
    vector<int> ans;
    for (int i = 0; i < arr.size(); i++) {
        if (ans.empty() || arr[i] > ans.back()) {
            pos[i] = ans.size();
            ans.push_back(arr[i]);
        } else {
            auto it = lower_bound(ans.begin(), ans.end(), arr[i]);
            pos[i] = it - ans.begin();
            *it = arr[i];
        }
    }
    return ans.size();
}

int main() {
    IOS
    while (cin >> n) {
        a.push_back(n);
    }
    pos.resize(a.size(), 0);
    int len = LIS(a);
    cout << len << "\n-\n";
    vector<int> ans;
    for (int i = a.size() - 1, t = len - 1; i >= 0; i--) {
        if (t == pos[i]) {
            ans.push_back(a[i]);
            t--;
        }
    }
    for (int i = ans.size() - 1; i >= 0; i--) {
        cout << ans[i] << '\n';
    }
}