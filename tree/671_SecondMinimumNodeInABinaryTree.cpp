//
// Created by leige on 7/17/2020.
//
// ref: http://zxi.mytechroad.com/blog/leetcode/leetcode-671-second-minimum-node-in-a-binary-tree/

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
    int findSecondMinimumValue(TreeNode* root) {
        if(!root) return -1;

        // return BFS(root);
        return BFS(root, root->val);
    }

private:
    // Time complexity: O(n)
    // Space complexity: O(n)
    int BFS(TreeNode* root)
    {
        if (!root) return -1;

        // Smallest value
        int s1 = root->value;
        // Second smallest value
        int s2 = INT_MAX;
        bool found = false;

        deque<TreeNode*> q;
        q.push_back(root);

        while (!q.empty())
        {
            TreeNode* node = q.front();
            q.pop_front();

            // keep updating second smallest value
            if (node->val > s1 &&  node->val < s2)
            {
                s2 = node->val;
                found = true;
                // No need to add it's children into queue
                continue;
            }

            if (!node->left) continue;
            q.push_back(node->left);
            q.push_back(node->right);
        }
        return found?s2:-1;
    }

    // Return the second smallest number in the (sub-tree)
    // s1 is the smallest value
    int DFS(TreeNode* root, int s1)
    {
        if (!root) return -1;

        // If root's value is already grater than s1,
        // then all its children's value should be >= s1.
        // Thus root's value is the second smallest one.
        // No need to visit the
        if (root->val > s1) return root->val; // 因为根节点是最小值，所以第一个比它大的数值就是第二小的数值

        int sl = DFS(root->left, s1);
        int sr = DFS(root->right, s1);

        if (sl == -1) return sr;
        if (sr == -1) return sl;

        // Return the smaller one among two subtrees
        return min(sl, sr);
    }
};
