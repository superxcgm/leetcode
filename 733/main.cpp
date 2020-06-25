//
// Created by Yujia Li  on 2020/6/17.
//
#include <vector>

using namespace std;

class Solution {
    int offset[4][2] = {
            {0, 1},
            {0, -1},
            {1, 0},
            {-1, 0}
    };

    bool visit[52][52] = {false};

    void dfs(vector<vector<int>>& image, int sr, int sc, int init_color, int new_color) {
        image[sr][sc] = new_color;
        visit[sr][sc] = true;

        for (int i = 0; i < 4; i++) {
            int next_sr = sr + offset[i][0];
            int next_sc = sc + offset[i][1];

            if (next_sr < 0 || next_sr >= image.size()) {
                continue;
            }

            if (next_sc < 0 || next_sc >= image[0].size()) {
                continue;
            }

            if (image[next_sr][next_sc] != init_color) {
                continue;
            }

            if (visit[next_sr][next_sc]) {
                continue;
            }

            dfs(image, next_sr, next_sc, init_color, new_color);
        }
        visit[sr][sc] = false;
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        dfs(image, sr, sc, image[sr][sc], newColor);
        return image;
    }
};

int main() {
    Solution solution;

    vector<vector<int>> img = {
            {0, 0, 0},
            {0, 1, 1}
    };

    solution.floodFill(img, 1, 1, 1);
}