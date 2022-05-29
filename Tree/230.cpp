class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        inorder(root, k);
        return res;
    }
    void inorder(TreeNode* root, int k)
    {
        if(root == nullptr)
            return;
        
        inorder(root->left, k);
        i++;
        if(i == k)
        {
            res = root->val;
            return;
        }
        inorder(root->right, k);
    }
private:
    int i = 0;
    int res = 0;
};