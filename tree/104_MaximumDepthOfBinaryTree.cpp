//
// Created by lei.ge on 6/11/2020.
//
// Runtime: 20 ms, faster than 9.19% of C++ online submissions for Maximum Depth of Binary Tree.
// Memory Usage: 19.3 MB, less than 32.78% of C++ online submissions for Maximum Depth of Binary Tree.

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
    int maxDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int leftDepth = maxDepth(root -> left);
        int rightDepth = maxDepth(root -> right);
        return max(leftDepth, rightDepth) + 1;
    }
};