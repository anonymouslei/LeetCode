//
// Created by leige on 7/17/2020.
//
// ref: https://zxi.mytechroad.com/blog/tree/leetcode-112-path-sum/

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
    //Runtime: 12 ms, faster than 92.80% of C++ online submissions for Path Sum.
    //Memory Usage: 21.4 MB, less than 33.40% of C++ online submissions for Path Sum.
    // 时间复杂度 O(n), 空间复杂度 O(h)
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (root==nullptr) return false;
        if (root->left==nullptr && root->right == nullptr) return (root->val==sum);

        int new_sum = sum - root->val;
        return hasPathSum(root->right, new_sum) || hasPathSum(root->left, new_sum);
    }
};