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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        res_ = root->val;
        q.push(root);
        int s = q.size();
        while(s > 0)
        {
            bool left_flag = false;
            for(int i = 0; i < s; i++)
            {
                auto node = q.front();
                if(left_flag == false)
                {
                    left_flag = true;
                    res_ = node->val;
                }
                q.pop();
                if(node->left != nullptr)
                {
                    q.push(node->left);
                }
                if(node->right != nullptr)
                {
                    q.push(node->right);
                }
            }
            s = q.size();
        }
        return res_;
    }
private:
    int res_;
};
