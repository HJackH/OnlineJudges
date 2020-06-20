#include <bits/stdc++.h>
using namespace std;

const int MAXN = 750 + 5;

struct Item {
    int sum;
    int pos;
    bool operator < (const Item &other) const {
        return sum > other.sum;
    }
};

int k, input[2][MAXN];

void merge(int* A, int* B, int* C) {
    priority_queue<Item> pq;
    for (int i = 0; i < k; i++) {
        pq.push({A[i] + B[0], 0});
    }

    for (int i = 0; i < k; i++) {
        Item it = pq.top();
        pq.pop();
        C[i] = it.sum;
        if (it.pos + 1 < k) {
            pq.push({it.sum - B[it.pos] + B[it.pos + 1], it.pos + 1});
        }
    }
}

int main() {
    while (cin >> k) {
        for (int i = 0; i < k; i++) {
            cin >> input[0][i];
        }
        sort(input[0], input[0] + k);
        
        for (int t = 1; t < k; t++) {
            for (int i = 0; i < k; i++) {
                cin >> input[1][i];
            }
            sort(input[1], input[1] + k);
            merge(input[0], input[1], input[0]);
        }

        cout << input[0][0];
        for (int i = 1; i < k; i++) {
            cout << ' ' << input[0][i];
        }
        cout << '\n';
    }
}