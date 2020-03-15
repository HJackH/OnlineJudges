#include <bits/stdc++.h>
using namespace std;

int n, a[10000 + 10], wnt;

int main() {
    while (cin >> n) {
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        cin >> wnt;
        sort(a, a + n);

        int i = 0, j = n - 1, ansi, ansj;
        while (i < j) {
            if (a[i] + a[j] > wnt) {
                j--;
            } else if (a[i] + a[j] < wnt) {
                i++;
            } else {
                ansi = i;
                ansj = j;
                i++;
                j--;
            }
        }

        cout << "Peter should buy books whose prices are " << a[ansi] << " and " << a[ansj] << ".\n" << endl;
    }
}
