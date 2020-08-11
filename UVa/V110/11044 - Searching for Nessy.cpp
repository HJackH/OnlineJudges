#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);

int n, m;

int main() {
    IOS
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        cout << (n / 3) * (m / 3) << '\n';
    }
}