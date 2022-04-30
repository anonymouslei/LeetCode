/*
the thief has found himself a new place for his thievery again. 
there is only one entrance to this area, called root.
basides the root, each house has one and only one parent house.
after a tour,
the smart thief realized that all houses in this place form a binary.
it will automatically contact the police if two directly-linked houses
were bro
*/
struct rootState{
    int selected;
    int notSelected;
};

class Solution {
public:
    int rob(TreeNode* root) {
        rootState root_state = dfs(root);
        return max(root_state.selected, root_state.notSelected);
    }
private:
    rootState dfs(TreeNode* node) {
        if(node == nullptr)
        {
            return {0,0};
        }
        auto r = dfs(node->right);
        auto l = dfs(node->left);
        int selected = node->val + r.notSelected + l.notSelected;
        int notSelected = max(r.selected, r.notSelected) + max(l.selected, l.notSelected);
        return {selected, notSelected};
    }
};