//
// Created by Yujia Li  on 2020/6/10.
//

#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution {
    bool isLegal(const string& s) {
        if (s.size() == 0) {
            return false;
        }
        if (s[0] == '0') {
            for (int i = 1; i < s.size(); i++) {
                if (s[i] != '.') {
                    return false;
                }
                break;
            }
        }

        if (s.find(".") != string::npos && s[s.size() - 1] == '0') {
            return false;
        }

        return true;
    }

    string assembly(const string &x, const string &y) {
        return "(" + x + ", " + y + ")";
    }
public:
    vector<string> ambiguousCoordinates(string S) {
        vector<string> possibles;
        for (int i = 1; i < S.size() - 2; i++) {
            auto x = S.substr(1, i);
            auto y = S.substr(i + 1, S.size() - i - 2);

            if (isLegal(x) && isLegal(y)) {
                possibles.push_back(assembly(x, y));
            }

            // x不加小数点，y加小数点
            if (isLegal(x)) {
                for (int j = 1; j < y.size(); j++) {
                    auto tmp_y = y.substr(0, j) + "." + y.substr(j);
                    if (isLegal(tmp_y)) {
                        possibles.push_back(assembly(x, tmp_y));
                    }
                }
            }

            // y不加小数点，x加小数点
            if (isLegal(y)) {
                for (int j = 1; j < x.size(); j++) {
                    auto tmp_x = x.substr(0, j) + "." + x.substr(j);
                    if (isLegal(tmp_x)) {
                        possibles.push_back(assembly(tmp_x, y));
                    }
                }
            }

            // x加小数点, y也加
            for (int j = 1; j < x.size(); j++) {
                auto tmp_x = x.substr(0, j) + "." + x.substr(j);
                if (!isLegal(tmp_x)) {
                    continue;
                }
                for (int k = 1; k < y.size(); k++) {
                    auto tmp_y = y.substr(0, k) + "." + y.substr(k);
                    if (isLegal(tmp_y)) {
                        possibles.push_back(assembly(tmp_x, tmp_y));
                    }
                }
            }
        }

        return possibles;
    }
};

int main() {
    Solution solution;

//    auto ret = solution.ambiguousCoordinates("(0123)");
//    auto ret = solution.ambiguousCoordinates("(100)");
//    auto ret = solution.ambiguousCoordinates("(0010)");
    auto ret = solution.ambiguousCoordinates("(00010)");
//    auto ret = solution.ambiguousCoordinates("(0000001)");

    return 0;
}