#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    void traverse(TreeNode* node, int deep, vector<vector<int>>& result) {
        if (node == nullptr) {
            return;
        }

        if (result.size() <= deep) {
            result.push_back({});
        }

        if (node->left) {
            traverse(node->left, deep + 1, result);
        }

        result[deep].push_back(node->val);

        if (node->right) {
            traverse(node->right, deep + 1, result);
        }

    }
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        traverse(root, 0, result);
        return {result.rbegin(), result.rend()};
    }
};

int main() {
    Solution solution;

    return 0;
}