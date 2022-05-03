class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        inorder(root);
        return res_;
    }
private:
    std::vector<int> res_;
    void inorder(TreeNode* root)
    {
        if(root == nullptr)
            return;
        inorder(root->left);
        res_.push_back(root->val);
        inorder(root->right);
    }
};