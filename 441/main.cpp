#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int arrangeCoins(int n) {
        return sqrt(2ll * n + 0.25) - 0.5;
    }
};

int main() {
    Solution solution;

    return 0;
}