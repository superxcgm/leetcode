//
// Created by Yujia Li  on 2020/5/25.
//

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> mp;

        for (auto x : nums) {
            mp[x]++;
        }

        const double threshold = nums.size() / 2.0;

        for (auto [k, v] : mp) {
            if (v >= threshold) {
                return k;
            }
        }
        // 无意义的值，理论上不会到这里
        return 0;
    }
};