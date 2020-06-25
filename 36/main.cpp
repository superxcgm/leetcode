//
// Created by Yujia Li  on 2020/5/27.
//

#include <vector>
#include <array>
#include <iostream>

using namespace std;

class Solution {
    static constexpr int len = 9;

    inline bool is_legal(const vector<char> &nums) {
        array<int, len + 1> arr = {0};
        for (auto ch : nums) {
            if (ch >= '0' && ch <= '9') {
                int num = ch - '0';
                arr[num]++;
                if (arr[num] > 1) {
                    return false;
                }
            }
        }
        return true;
    }
    inline vector<char> extract(const vector<vector<char>>& board, int col) {
        vector<char> ret;
        for (auto &row: board) {
            ret.push_back(row[col]);
        }
        return ret;
    }
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < len; i++) {
            if (!is_legal(board[i])) {
                return false;
            }

            const auto &vec_col = extract(board, i);
            if (!is_legal(vec_col)) {
                return false;
            }

            int y = (i / 3) * 3;
            int x = (i % 3) * 3;

            vector<char> vec_block = {
                    board[y][x],     board[y][x + 1],     board[y][x+2],
                    board[y + 1][x], board[y + 1][x + 1], board[y + 1][x + 2],
                    board[y + 2][x], board[y + 2][x + 1], board[y + 2][x + 2],
            };

            if (!is_legal(vec_block)) {
                return false;
            }
        }

        return true;
    }
};


int main() {

    Solution solution;

    vector<vector<char>> v = {
            {'5','3','.','.','7','.','.','.','.'},
            {'6','.','.','1','9','5','.','.','.'},
            {'.','9','8','.','.','.','.','6','.'},
            {'8','.','.','.','6','.','.','.','3'},
            {'4','.','.','8','.','3','.','.','1'},
            {'7','.','.','.','2','.','.','.','6'},
            {'.','6','.','.','.','.','2','8','.'},
            {'.','.','.','4','1','9','.','.','5'},
            {'.','.','.','.','8','.','.','7','9'}
    };

    cout << (solution.isValidSudoku(v) ? "true" : "false") << endl;

    return 0;
}