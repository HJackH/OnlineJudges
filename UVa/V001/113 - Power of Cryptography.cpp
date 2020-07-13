#include <bits/stdc++.h>
using namespace std;

double n, p;

int main() {
    while (cin >> n >> p) {
        printf("%.0lf\n", pow(p, 1.0 / n));
    }
}