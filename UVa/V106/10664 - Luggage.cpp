#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
#define pb push_back
const int MAXW = 200;

int dp[MAXW + 5];
vector<int> a;

int main() { IOS
    int T;
    string input;
    cin >> T;
    cin.ignore();
    while (T--) {
        getline(cin, input);
        stringstream ss(input);
        memset(dp, 0, sizeof(dp));
        a.clear();

        int b, sum = 0;
        while (ss >> b) {
            a.pb(b);
            sum += b;
        }

        dp[0] = 1;
        for (int i : a) {
            for (int w = MAXW; w >= i; w--) {
                if (dp[w - i]) {
                    dp[w] = 1;
                }
            }
        }

        if (sum & 1 || !dp[sum / 2]) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
}