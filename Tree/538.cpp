class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        inorder(root);
        return root;
    }
    void inorder(TreeNode* root)
    {
        if(root == nullptr)
            return;
        inorder(root->right);
        
        int tmp = root->val;
        root->val += sum;
        sum += tmp;
        
        inorder(root->left);
    }
private:
    int sum = 0;
};

class Solution {
    public TreeNode convertBST(TreeNode root) {
        int sum = 0;
        TreeNode node = root;
        //借鉴线索二叉树的思想，充分利用二叉树中的空指针。考虑到遍历顺序为右中左，
        //故当前节点的右子树遍历结束后应当遍历当前节点，
        //故应将当前节点右子树中最后遍历的节点的左指针指向当前节点，即建立右孩子到父节点的联系，
        //而其右子树最后遍历的节点一定为右子树中最左侧节点。
        while (node != null){
            if (node.right == null){//当前节点没有右孩子，优先遍历当前节点
                sum += node.val;
                node.val = sum;
                node = node.left;//当前节点遍历结束，继续遍历其后继节点
            } else {
                TreeNode succ = getSuccessor(node);//寻找当前节点的前驱节点
                if (succ.left == null){//如果前驱节点左指针为空，将其指向当前节点，方便从当前节点的右子树寻找当前节点
                    succ.left = node;
                    node = node.right;//控制权优先转交给其右孩子
                } else {//前驱节点左指针不为空，即已经建立线索
                    succ.left = null;//拆除当前节点的前驱节点的线索还原二叉树（该节点已经在上一次循环中被访问过，其左指针不再需要）
                    sum += node.val;//遍历当前节点
                    node.val = sum;
                    node = node.left;//继续遍历后继节点
                }
            }
        }
        return root;
    }
    //建立一个函数寻找当前节点的前驱节点。
    public TreeNode getSuccessor(TreeNode node){
        TreeNode succ = node.right;
        //前驱节点一定在当前节点右子树的最左端，或前驱节点的左指针已经指向当前节点
        while (succ.left != null && succ.left != node){
            succ = succ.left;
        }
        return succ;
    }
    
}