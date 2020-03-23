#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000 + 50;

int n, a[MAXN];

int main() {
    while (cin >> n && n) {
        while (cin >> a[1] && a[1]) {
            for (int i = 2; i <= n; i++) {
                cin >> a[i];
            }

            stack<int> st;
            bool chk = true;
            int now = 1;
            for (int i = 1; i <= n && chk; i++) {
                for (int j = now; j < a[i]; j++) {
                    st.push(j);
                    now++;
                }
                if (!st.empty() && st.top() == a[i]) {
                    st.pop();
                } else if (now == a[i]) {
                    now++;
                } else {
                    chk = false;
                }
            }

            if (chk) {
                cout << "Yes\n";
            } else {
                cout << "No\n";
            }
        }
        cout << "\n";
    }
}
