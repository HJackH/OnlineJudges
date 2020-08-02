#include <bits/stdc++.h>
using namespace std;

long long n;

int main() {
    while (cin >> n) {
        n = (n + 1) * (n + 1) / 4;
        n = 2 * n - 1;
        cout << 3 * n - 6 << '\n';
    }
}