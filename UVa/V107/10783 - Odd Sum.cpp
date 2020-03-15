#include <bits/stdc++.h>
using namespace std;

int T, a, b;

int main() {
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> a >> b;
        if (a % 2 == 0) {
            ++a;
        }
        if (b % 2 == 0) {
            --b;
        }

        int sum = 0;
        for (int i = a; i <= b; i += 2) {
            sum += i;
        }
        cout << "Case " << t << ": " << sum << '\n';
    }
}
