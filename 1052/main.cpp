//
// Created by Yujia Li  on 2020/6/17.
//

#include <vector>

using namespace std;

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int base_satisfy = 0;

        if (X == customers.size()) {
            for_each(customers.begin(), customers.end(), [&base_satisfy](int c) { base_satisfy+=c;});
            return base_satisfy;
        }

        int extra_satisfy = 0;
        for (int i = 0; i < X; i++) {
            if (grumpy[i]) {
                extra_satisfy += customers[i];
            } else {
                base_satisfy += customers[i];
            }
        }
        int max_extra_satisfy = extra_satisfy;

        for (int i = X; i < customers.size(); i++) {
            if (grumpy[i - X]) {
                extra_satisfy -= customers[i - X];
            }

            if (grumpy[i]) {
                extra_satisfy += customers[i];
            } else {
                base_satisfy += customers[i];
            }

            if (extra_satisfy > max_extra_satisfy) {
                max_extra_satisfy = extra_satisfy;
            }
        }

        return base_satisfy + max_extra_satisfy;
    }
};

int main() {
    Solution solution;

    vector<int> customers = {1, 0, 1, 2, 1, 1, 7, 5};
    vector<int> grumpy = {0, 1, 0, 1, 0, 1, 0, 1};

    solution.maxSatisfied(customers, grumpy, 3);
}