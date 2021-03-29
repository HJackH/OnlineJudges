#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
#define pb push_back
const int MAXN = 1e7;

string s;
vector<bool> isPrime(MAXN + 5, 1);
unordered_set<int> st;

void table() {
    isPrime[1] = isPrime[0] = 0;
    for (int i = 2, ed = sqrt(MAXN); i <= ed; i++) {
        if (isPrime[i]) {
            for (int j = 2 * i; j <= MAXN; j += i) {
                isPrime[j] = 0;
            }
        }
    }
}

int main() { IOS
    table();
    int T;
    cin >> T;
    while (T--) {
        st.clear();
        cin >> s;
        int n = s.length();
        sort(s.begin(), s.end());

        string a;
        for (int i = 1, ed = 1 << n; i < ed; i++) {
            a.clear();
            for (int j = 0; j < n; j++) {
                if (i & (1 << j)) {
                    a += s[j];
                }
            }
            do {
                int k = stoi(a);
                if (isPrime[k]) {
                    st.insert(k);
                }
            } while (next_permutation(a.begin(), a.end()));
        }

        cout << st.size() << '\n';
    }
}