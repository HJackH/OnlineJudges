#include <bits/stdc++.h>
using namespace std;

long long T, num;
char op;
string input;
vector<long long> nums, numMax, numMin;
vector<char> ops;

int main() {
    cin >> T;
    while (T--) {
        cin >> input;
        stringstream ss(input);

        nums.clear();
        numMax.clear();
        numMin.clear();
        ops.clear();

        ss >> num;
        nums.push_back(num);
        while (ss >> op >> num) {
            ops.push_back(op);
            nums.push_back(num);
        }

        numMax.push_back(nums[0]);
        numMin.push_back(nums[0]);
        for (int i = 0, ed = ops.size(); i < ed; i++) {
            long long tmp2, tmp3;
            if (ops[i] == '+') {
                tmp2 = numMax.back(); numMax.pop_back();
                tmp3 = 1;
            } else {
                tmp2 = 0;
                tmp3 = numMin.back(); numMin.pop_back();
            }
            numMax.push_back(tmp2 + nums[i + 1]);
            numMin.push_back(tmp3 * nums[i + 1]);
        }

        long long ansMax = 1, ansMin = 0;
        for (auto i : numMax) {
            ansMax *= i;
        }
        for (auto i : numMin) {
            ansMin += i;
        }
        cout << "The maximum and minimum are " << ansMax << " and " << ansMin << ".\n";
    }
}  