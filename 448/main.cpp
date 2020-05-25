//
// Created by Yujia Li  on 2020/5/25.
//

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> not_appear;

        for (int i = 0; i < nums.size(); i++) {
            int val = abs(nums[i]) - 1;
            if (nums[val] > 0) {
                nums[val] = -nums[val];
            }
        }

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                not_appear.push_back(i + 1);
            }
        }
        return not_appear;
    }
};