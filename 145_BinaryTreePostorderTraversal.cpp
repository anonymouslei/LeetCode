//
// Created by lei.ge on 6/19/2020.
// reference: http://zxi.mytechroad.com/blog/tree/leetcode-145-binary-tree-postorder-traversal/
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
class Solution_Recursive {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        postorderTraversal(root, res);
        return res;
    }

    void postorderTraversal(TreeNode* root, vector<int>& res) {
        if(!root) return ;
        postorderTraversal(root->left, res);
        postorderTraversal(root->right, res);
        res.push_back(root->val);
    }
};
// Runtime: 0 ms
// Memory Usage: 8.7 MB
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root) return {};
        deque<int> res;
        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()) {
            auto it = s.top();
            s.pop();
            res.push_front(it->val);
            if (it->left) {s.push(it->left);}
            if (it->right) {s.push(it->right);}
        }
        return vector<int> (res.begin(), res.end());

    }
};
