#include <bits/stdc++.h>
using namespace std;

int tmp;
vector<int> a;

int main() {
    while (cin >> tmp) {
        a.insert(lower_bound(a.begin(), a.end(), tmp), tmp);
        if (a.size() & 1) {
            cout << a[a.size() / 2] << '\n';
        } else {
            cout << (a[a.size() / 2 - 1] + a[a.size() / 2]) / 2 << '\n';
        }
    }
}