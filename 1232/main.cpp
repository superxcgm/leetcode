//
// Created by Yujia Li  on 2020/6/25.
//

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        if (coordinates.size() < 2) {
            return true;
        }

        double dy = coordinates[0][1] - coordinates[1][1];
        double dx = coordinates[0][0] - coordinates[1][0];

        if (dx == 0) {
            for (int i = 2; i < coordinates.size(); i++) {
                if (coordinates[i][0] != coordinates[0][0]) {
                    return false;
                }
            }
            return true;
        }

        double k = dy / dx;
        double EPS = 1e-5;
        double b = coordinates[0][1] - k * coordinates[0][0];

        for (int i = 2; i < coordinates.size(); i++) {
            if (abs(coordinates[i][1] - (k * coordinates[i][0] + b)) > EPS) {
                return false;
            }
        }
        return true;
    }
};