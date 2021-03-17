#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
#define pb push_back

int n;

int sol(int num) {
    return num * (num - 1) / 2;
}

int main() { IOS
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        cout << sol(n / 2) + sol((n + 1) / 2) << '\n';
    }
}