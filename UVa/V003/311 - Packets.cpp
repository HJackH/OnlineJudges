#include <bits/stdc++.h>
using namespace std;

int a[7];

void placeOne(int num) {
    if (a[1] >= num) {
        a[1] -= num;
    } else {
        a[1] = 0;
    }
}

int placeTwo(int num) {
    if (a[2] >= num) {
        a[2] -= num;
        return 0;
    } else {
        num -= a[2];
        a[2] = 0;
        return num;
    }
}

int main() {
    while (true) {
        int flag = 0;
        for (int i = 1; i <= 6; i++) {
            cin >> a[i];
            flag += a[i];
        }
        if (!flag) {
            break;
        }

        int cnt = a[6] + a[5] + a[4] + (a[3] + 3) / 4;
        placeOne(a[5] * 11);
        placeOne(placeTwo(a[4] * 5) * 4);
        if (a[3] % 4) {
            placeOne(placeTwo(5 - 2 * (a[3] % 4 - 1)) * 4 + 8 - a[3] % 4);
        }
        cnt += (a[2] + 8) / 9;
        if (a[2] % 9) {
            placeOne((9 - a[2] % 9) * 4);
        }
        cnt += (a[1] + 35) / 36;
        cout << cnt << '\n';
    }
}
