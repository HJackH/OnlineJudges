#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
#define eb emplace_back
#define pb push_back

int n;
vector<int> a[3];

int main() { IOS
    cin >> n;
    for (int j = 0; j < 3; j++) {
        a[j].resize(n - j);
        for (int i = 0; i < n - j; i++) {
            cin >> a[j][i];
        }
        sort(a[j].begin(), a[j].end());
    }

    for (int j = 1; j < 3; j++) {
        int i;
        for (i = 0; i < a[j].size(); i++) {
            if (a[j][i] != a[j - 1][i]) {
                break;
            }
        }
        cout << a[j - 1][i] << '\n';
    }
}