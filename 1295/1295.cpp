//
// Created by Yujia Li  on 2020/5/30.
//

class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int cnt = 0;

        for (int x : nums) {
            if (x >= 10 && x <= 99 || x >= 1000 && x <= 9999) {
                cnt++;
            }
        }

        return cnt;
    }
};