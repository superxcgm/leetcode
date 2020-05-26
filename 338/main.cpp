//
// Created by Yujia Li  on 2020/5/26.
//

class Solution {
    inline int count(int x) {
        int ret = 0;
        while (x) {
            if (x & 1) {
                ret++;
            }
            x >>= 1;
        }
        return ret;
    }
public:
    vector<int> countBits(int num) {
        vector<int> ret;
        for (int i = 0; i <= num; i++) {
            ret.push_back(count(i));
        }
        return ret;
    }
};