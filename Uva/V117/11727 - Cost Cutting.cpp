#include <bits/stdc++.h>
using namespace std;

int T, a[3];

int main() {
    cin >> T;
    for (int t = 1; t <= T; t++) {
        for (int i = 0; i < 3; i++) {
            cin >> a[i];
        }
        sort(a, a + 3);
        cout << "Case " << t << ": " << a[1] << endl;
    }
}
