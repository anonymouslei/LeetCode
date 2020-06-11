//
// Created by lei.ge on 6/11/2020.
//
//Runtime: 12 ms, faster than 74.24% of C++ online submissions for Diameter of Binary Tree.
//Memory Usage: 20.7 MB, less than 34.36% of C++ online submissions for Diameter of Binary Tree.
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
    int diameterOfBinaryTree(TreeNode* root) {
        ans_ = 0;
        LongestPath(root);

        return ans_;
    }
private:
    int ans_;
    int LongestPath(TreeNode* root) {
        if (!root) return -1;
        int leftLength = LongestPath(root->left) + 1;
        int rightLength = LongestPath(root->right) + 1;

        ans_ = max(ans_, leftLength + rightLength);
        return max(leftLength, rightLength);
    }

};