#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
#define pb push_back
const int MAXN = 2000 + 5;

int n, k;

int main() { IOS
    cin >> n >> k;
    vector<int> a(n);
    for (auto &i : a) {
        cin >> i;
    }
    sort(a.begin(), a.end());
    int num = lower_bound(a.begin(), a.end(), 6 - k) - a.begin();
    cout << num / 3 << '\n';
}