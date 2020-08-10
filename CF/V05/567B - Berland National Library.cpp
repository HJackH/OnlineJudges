#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);

int n, num;
char mode;
unordered_set<int> S;

int main() {
    IOS
    cin >> n;
    char mode;
    int ans = 0, tmp = 0;
    while (n--) {
        cin >> mode >> num;
        if (mode == '+') {
            tmp++;
            S.insert(num);
        } else {
            auto it = S.find(num);
            if (it == S.end()) {
                ans++;
            } else {
                tmp--;
                S.erase(it);
            }
        }
        ans = max(ans, tmp);
    }
    cout << ans << '\n';
}