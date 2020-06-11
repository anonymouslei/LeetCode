// o(n)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *	int val;
 * 	TreeNode *left;
 *	TreeNode *right;
 *	TreeNode() : val(0), left(nullptr), right(nullptr) {}
 * 	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isBalanced(TreeNode* root) {
    	if(!root) return true;
	bool balanced = true;
	height(root, balanced);
	return balanced;
    }
private:
    int height(TreeNode* root, bool& balanced)  {
    	if(!root) return 0;
	int left_height = height(root->left, balanced);
	if(!balanced) return -1;
	int right_height = height(root->right, balanced);
	if(!balanced) return -1;
	if(abs(left_height-right_height)>1) {
	    balance = false;
	    return -1;
	}
	return max(left_height, right_height) + 1;
    }
};

/*
// test 1: &  only one of(!balanced) return -1
//Runtime: 20 ms, faster than 47.08% of C++ online submissions for Balanced Binary Tree.
//Memory Usage: 21.9 MB, less than 23.50% of C++ online submissions for Balanced Binary Tree.
 Runtime: 16 ms, faster than 73.88% of C++ online submissions for Balanced Binary Tree.
Memory Usage: 22 MB, less than 13.54% of C++ online submissions for Balanced Binary Tree.

// test 2: &  only one of(!balanced) return -1
Runtime: 12 ms
Memory Usage: 21.9 MB
 Runtime: 20 ms, faster than 47.08% of C++ online submissions for Balanced Binary Tree.
Memory Usage: 21.5 MB, less than 59.28% of C++ online submissions for Balanced Binary Tree.
// test 3: if(!balanced) return -1 * 2; &
Runtime: 32 ms, faster than 11.05% of C++ online submissions for Balanced Binary Tree.
Memory Usage: 22 MB, less than 16.61% of C++ online submissions for Balanced Binary Tree.

 */