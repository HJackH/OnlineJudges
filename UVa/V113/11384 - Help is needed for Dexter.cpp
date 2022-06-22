#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    while (cin >> n) {
        for (int i = 1; i <= 30; i++) {
            if ((1 << i) > n) {
                cout << i << "\n";
                break;
            }
        }
    }
}