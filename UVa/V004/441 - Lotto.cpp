#include <bits/stdc++.h>
using namespace std;

const int MAXN = 13 + 5;

int T, a[MAXN];

int main() {
    cin >> T;
    while (true) {
        for (int i = 0; i < T; i++) {
            cin >> a[i];
        }

        for (int i = 0; i < T - 5; i++) {
            for (int j = i + 1; j < T - 4; j++) {
                for (int k = j + 1; k < T - 3; k++) {
                    for (int l = k + 1; l < T - 2; l++) {
                        for (int m = l + 1; m < T - 1; m++) {
                            for (int n = m + 1; n < T; n++) {
                                cout << a[i] << ' ' << a[j] << ' ' << a[k] << ' '
                                        << a[l] << ' ' << a[m] << ' ' << a[n] << '\n';
                            }
                        }
                    }
                }
            }
        }

        cin >> T;
        if (T) {
            cout << '\n';
        } else {
            break;
        }
    }
    
}