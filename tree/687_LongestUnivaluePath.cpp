//
// Created by leige on 7/17/2020.
//
// ref: http://zxi.mytechroad.com/blog/tree/leetcode-687-longest-univalue-path/

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
    // Runtime: 192 ms, faster than 73.24% of C++ online submissions for Longest Univalue Path.
    //Memory Usage: 72.1 MB, less than 55.05% of C++ online submissions for Longest Univalue Path.
public:
    int longestUnivaluePath(TreeNode* root) {
        if (root==nullptr) return 0;
        int ans = 0;
        helper(root, ans);
        return ans;
    }
private:
    int helper(TreeNode* root, int& ans)
    {
        if (root==nullptr) return 0;
        int l = helper(root->left, ans);
        int r = helper(root->right, ans);
        int ansl = 0;
        int ansr = 0;
        if(root->left && root->val == root->left->val) ansl = l + 1;
        if(root->right && root->val == root->right->val) ansr = r + 1;

        ans = max(ans, ansl + ansr);
        return max(ansl, ansr);
    }
};