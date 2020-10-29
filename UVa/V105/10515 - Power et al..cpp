#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);

string m, n;
const int a[10][4] = {
    {0, 0, 0, 0},
    {1, 1, 1, 1},
    {6, 2, 4, 8},
    {1, 3, 9, 7},
    {6, 4, 6, 4},
    {5, 5, 5, 5},
    {6, 6, 6, 6},
    {1, 7, 9, 3},
    {6, 8, 4, 2},
    {1, 9, 1, 9}
};

int main() { IOS
    while (cin >> m >> n && (m != "0" || n != "0")) {
        if (n == "0") {
            cout << 1 << '\n';
        } else {
            cout << a[m.back() - '0'][stoi(n.substr(max(0, (int)n.size() - 2))) % 4] << '\n';
        }
    }
}