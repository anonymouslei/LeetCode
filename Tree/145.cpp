class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        postorder(root);
        return res_;
    }
private:
    std::vector<int> res_;
    void postorder(TreeNode* root)
    {
        if(root == nullptr)
            return;
        postorder(root->left);
        postorder(root->right);
        res_.push_back(root->val);
    }
};