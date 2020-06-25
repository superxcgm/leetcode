//
// Created by Yujia Li  on 2020/6/25.
//

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            int val = nums[i];
            int absolute = abs(val);
            if (nums[absolute] < 0) {
                return absolute;
            }
            nums[absolute] = -nums[absolute];
        }
        return -1;
    }
};