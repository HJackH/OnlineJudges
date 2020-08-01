#include <bits/stdc++.h>
using namespace std;

long long n, m;

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        cout << (m - 1 + m - n) * n / 2 << '\n';
    }
}