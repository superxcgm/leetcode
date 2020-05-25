//
// Created by Yujia Li  on 2020/5/25.
//

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
    inline TreeNode* leftChild(TreeNode* node) {
        return node == nullptr ? nullptr : node->left;
    }

    inline TreeNode* rightChild(TreeNode* node) {
        return node == nullptr ? nullptr : node->right;
    }
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (t1 == nullptr && t2 == nullptr) {
            return nullptr;
        }
        int lhs = t1 == nullptr ? 0 : t1->val;
        int rhs = t2 == nullptr ? 0 : t2->val;

        TreeNode *ret;

        if (t1 != nullptr) {
            ret = t1;
        } else if (t2 != nullptr) {
            ret = t2;
        }

        ret->val = lhs + rhs;
        ret->left = mergeTrees(leftChild(t1), leftChild(t2));
        ret->right = mergeTrees(rightChild(t1), rightChild(t2));

        return ret;
    }
};