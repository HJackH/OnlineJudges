#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100000 + 5;

int a, b;
vector<int> sq;

int main() {
    for (int i = 1; i * i <= MAXN; i++) {
        sq.push_back(i * i);
    }
    while (cin >> a >> b && (a || b)) {
        cout << upper_bound(sq.begin(), sq.end(), b) 
                - lower_bound(sq.begin(), sq.end(), a) << '\n';
    }
}