//
// Created by Yujia Li  on 2020/6/3.
//
#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Solution {
    struct Cost {
        int zero = 0;
        int one = 0;
        Cost() = default;
        Cost(int zero, int one): zero(zero), one(one) {}
    };
    int countOne(const string& str) {
        int cnt = 0;
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == '1') {
                cnt++;
            }
        }
        return cnt;
    }
public:
    int dp[101][101];
    int findMaxForm(vector<string>& strs, int m, int n) {
        int quantity = strs.size();
        vector<Cost> costs(quantity + 1);

        for (int i = 0; i < quantity; i++) {
            costs[i + 1].one = countOne(strs[i]);
            costs[i + 1].zero = strs[i].size() - costs[i + 1].one;
        }
        memset(dp, 0, sizeof(int) * 101 * 101);

        for (int i = 1; i <= quantity; i++) {
            for (int j = m; j >= costs[i].zero; j--) {
                for (int k = n; k >= costs[i].one; k--) {
                    int take = dp[j - costs[i].zero][k - costs[i].one];
                    dp[j][k] = max(dp[j][k], take + 1);
                }
            }
        }

        return dp[m][n];
    }
};

int main() {
    vector<string> vec{"10", "0001", "111001", "1", "0"};
    Solution solution;
    cout << solution.findMaxForm(vec, 5, 3) << endl;
}