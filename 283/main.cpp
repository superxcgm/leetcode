//
// Created by Yujia Li  on 2020/5/25.
//

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i]) {
                continue;
            }
            for (j = max(j, i + 1); j < nums.size(); j++) {
                if (nums[j]) {
                    swap(nums[i], nums[j]);
                    break;
                }
            }
        }
    }
};