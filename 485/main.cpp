//
// Created by Yujia Li  on 2020/5/30.
//

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max_count = 0;
        int count = 0;

        for (int x : nums) {
            if (x == 1) {
                count++;
            } else {
                if (count > max_count) {
                    max_count = count;
                }
                count = 0;
            }
        }

        return max(max_count, count);
    }
};