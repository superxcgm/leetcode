#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        int f[102][102] = {0};
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == 1 || j == 1) {
                    f[i][j] = 1;
                    continue;
                }
                f[i][j] = f[i - 1][j] + f[i][j - 1];
            }
        }
        return f[m][n];
    }
};

int main() {
    Solution solution;

    return 0;
}