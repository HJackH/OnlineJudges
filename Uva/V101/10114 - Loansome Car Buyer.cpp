#include <bits/stdc++.h>
using namespace std;

int dur, n;
double downPay, loan, deps[110];

int main() {
    while (cin >> dur >> downPay >> loan >> n && dur >= 0) {
        int month, nowMonth = 1;
        double nowPercent;

        cin >> month >> nowPercent;
        nowPercent = 1.0 - nowPercent;
        deps[0] = (downPay + loan) * nowPercent;

        for (int i = 1; i < n; i++) {
            cin >> month;
            for (int m = nowMonth; m <= month - 1; m++, nowMonth++) {
                deps[m] = deps[m - 1] * nowPercent;
            }

            cin >> nowPercent;
            nowPercent = 1.0 - nowPercent;
        }

        for (int m = nowMonth; m <= dur; m++) {
            deps[m] = deps[m - 1] * nowPercent;
        }

        int ans;
        double borrow = loan, down = loan / dur;
        for (ans = 0; ans <= dur; ans++) {  
            if (borrow < deps[ans]) {
                break;
            }
            borrow -= down; 
        }

        if (ans != 1) {
            cout << ans << " months" << endl;
        } else {
            cout << "1 month" << endl;
        }
    }
}
