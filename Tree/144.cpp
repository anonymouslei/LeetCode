class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        preorder(root);
        return res_;
    }
private:
    void preorder(TreeNode* root) {
        if(root == nullptr)
            return;
        res_.push_back(root->val);
        preorder(root->left);
        preorder(root->right);
    }
    std::vector<int> res_;
};