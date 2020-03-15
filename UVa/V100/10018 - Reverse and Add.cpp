#include <bits/stdc++.h>
using namespace std;

long long T, n, cnt;
string tmp, rtmp;

bool chkPa() {
    rtmp = tmp = to_string(n);
    reverse(rtmp.begin(), rtmp.end());
    return tmp == rtmp;
}

int main() {
    cin >> T;
    while (T--) {
        cin >> n;
        cnt = 0;

        while (!chkPa()) {
            n += stoll(rtmp);
            cnt++;
        }
        
        cout << cnt << " " << n << endl;
    }
}
