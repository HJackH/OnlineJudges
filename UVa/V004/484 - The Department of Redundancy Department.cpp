#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);

int num;
unordered_map<int, int> M;
vector<int> a;

int main() {
    IOS
    while (cin >> num) {
        if (M.count(num)) {
            M[num]++;
        } else {
            a.push_back(num);
            M[num] = 1;
        }
    }
    for (int i : a) {
        cout << i << ' ' << M[i] << '\n';
    }
}