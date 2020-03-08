#include <bits/stdc++.h>
using namespace std;

int n, a[3100];
vector<int> diff;

int main() {
    while (cin >> n) {
        diff.clear();

        cin >> a[0];
        for (int i = 1; i < n; i++) {
            cin >> a[i];
            diff.push_back(abs(a[i] - a[i - 1]));
        }

        sort(diff.begin(), diff.end());

        bool chk = true;
        for (int i = 0; i < n - 1; i++) {
            if (diff[i] != i + 1) {
                chk = false;
                break;
            }
        }

        if (chk) {
            cout << "Jolly" << endl;
        } else {
            cout << "Not jolly" << endl;
        }
    }
}
