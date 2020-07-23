//
// Created by leige on 7/17/2020.
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
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (root==nullptr) return 0;
        if (root->left!=nullptr && root->left->left == nullptr && root->left->right == nullptr)
        {
            return sum + root->left->val + sumOfLeftLeaves(root->right) + sumOfLeftLeaves(root->left);
        }
        return sumOfLeftLeaves(root->right) + sumOfLeftLeaves(root->left);
    }
private:
    int sum = 0;
};
