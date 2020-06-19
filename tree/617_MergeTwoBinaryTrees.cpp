//
// Created by lei.ge on 6/19/2020.
//
/**
 * Runtime: 44 ms, faster than 75.62% of C++ online submissions for Merge Two Binary Trees.
 * Memory Usage: 21.9 MB, less than 84.86% of C++ online submissions for Merge Two Binary Trees.
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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (t1 == nullptr) return t2;
        if (t2 == nullptr) return t1;

        auto root = t1;
        root->val += t2->val;
        root->right = mergeTrees(t1->right, t2->right);
        root->left = mergeTrees(t1->left, t2->left);

        return root;
    }
    }
