//
// Created by Yujia Li  on 2020/6/25.
//

class Solution {
    static constexpr int len = 10;
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ret;
        if (s.size() <= len) {
            return ret;
        }
        unordered_map<string, int> hash;
        int end = s.size() - len;
        for (int i = 0; i <= end; i++) {
            string sub_str = s.substr(i, len);
            if (hash.find(sub_str) == hash.end()) {
                hash[sub_str] = 0;
            }
            auto& val = hash[sub_str];
            if (val == -1) {
                continue;
            }
            val++;
            if (val == 2) {
                ret.push_back(sub_str);
                val = -1;
            }
        }

        return ret;
    }
};