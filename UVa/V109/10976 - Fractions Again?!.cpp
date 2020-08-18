#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);

struct Item {
    int x;
    int y;
    Item(int _x, int _y) : x(_x), y(_y) {}
};

int k;
vector<Item> ans;

int main() {
    IOS
    while (cin >> k) {
        ans.clear();
        for (int y = k + 1, ed = 2 * k; y <= ed; y++) {
            int x = (double)k * y / (y - k) + 0.4;
            if (x * y == k * (x + y)) {
                ans.emplace_back(x, y);
            }
        }
        cout << ans.size() << '\n';
        for (auto i : ans) {
            cout << "1/" << k << " = 1/" << i.x << " + 1/" << i.y << '\n';
        }
    }
}