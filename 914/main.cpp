//
// Created by Yujia Li  on 2020/6/10.
//

class Solution {
    int gcd(int a, int b) {
        return a % b == 0 ? b : gcd(b, a % b);
    }
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> mp;

        for (int x : deck) {
            ++mp[x];
        }

        bool first = true;
        int factor;

        for (auto [_, v] : mp) {
            if (first) {
                first = false;
                factor = v;
                continue;
            }
            factor = gcd(factor, v);
        }

        return factor >= 2;
    }
};